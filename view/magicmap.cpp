#include "magicmap.h"
#include "ui_magicmap.h"
#include <QColor>
#include <QLabel>

MagicMap::MagicMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MagicMap)
{
    ui->setupUi(this);
    ui->bookWidget->hide();
    QString prefix(":/assets/Images/");
    playerImageHash[MagicTower::DOWN]   = prefix + "415_.png";
    playerImageHash[MagicTower::UP]     = prefix + "485_.png";
    playerImageHash[MagicTower::LEFT]   = prefix + "473_.png";
    playerImageHash[MagicTower::RIGHT]  = prefix + "479_.png";

    flash_flag=true;

    m_Timer = new QTimer(this);
    connect(m_Timer,SIGNAL(timeout()),this,SLOT(shining()));
    m_Timer->start(300);

    //read maphash
    QFile f(":/view/mapHash/mapHash.txt");
    if(f.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&f);
        QString item,imgIndex;
        while(!in.atEnd())
        {
            in>>item>>imgIndex;
            map_hash.insert(item,prefix+imgIndex+".bmp");
        }
    }
    QFile f2(":/view/mapHash/mapHash_flash.txt");
    if(f2.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&f2);
        QString item,imgIndex;
        while(!in.atEnd())
        {
            in>>item>>imgIndex;
            map_hash_flash.insert(item,prefix+imgIndex+".bmp");
        }
    }

}

MagicMap::~MagicMap()
{
    delete ui;
}

void MagicMap::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    painter.translate(0, 0);


    /* Draw map */

    if(m_gamemap!=nullptr)
    {
        int m_level=0;
        if(m_player!=nullptr)
            m_level=m_player->getLayer();
        for(int i=0;i<11;i++)
            for(int j=0;j<11;j++)
            {
                QString itemId=m_gamemap->getData(m_level,i,j);
                QString imgIndex;
                if(map_hash.find(itemId)==map_hash.end())   //unknown id,draw floor
                {
                    imgIndex=":/assets/Images/221.bmp";
                }
                else
                {
                    if(flash_flag)
                        imgIndex = map_hash.find(itemId).value();
                    else
                        imgIndex = map_hash_flash.find(itemId).value();
                }
                pix.load(imgIndex);
                int picWidth   = width() / MagicTower::MAP_WIDTH;
                int picHeight  = height() / MagicTower::MAP_HEIGHT;
                painter.drawPixmap(j*picWidth,i*picHeight,picWidth,picHeight,pix);
            }
    }
    /* Draw player */
    if (m_player != nullptr) {
        auto direction  = m_player->getDirection();
        auto position   = m_player->getPosition();
        pix.load(playerImageHash[direction]);
        int picWidth   = width() / MagicTower::MAP_WIDTH;
        int picHeight  = height() / MagicTower::MAP_HEIGHT;
        painter.drawPixmap(position.second * picWidth, position.first * picHeight, picWidth, picHeight, pix);
    }

    /* Draw border */
    QPen pen;
    pen.setColor(QColor(204,102,0));
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawLine(0, 0, this->width() - 8, 0);
    painter.drawLine(0, 0, 0, this->height() - 8);
    painter.drawLine(this->width() - 8, 0, this->width() - 8, this->height() - 8);
    painter.drawLine(0, this->height() - 8, this->width() - 8, this->height() - 8);
}

void MagicMap::attachPlayer(const std::shared_ptr<Player> &player)
{
    m_player = player;
    repaint();
}

void MagicMap::attachGameMap(const std::shared_ptr<GameMap>& gamemap)
{
    m_gamemap=gamemap;
    repaint();
}

void MagicMap::shining()
{
    if(flash_flag)
        flash_flag=false;
    else
        flash_flag=true;
    repaint();
}
void MagicMap::openBook(const QVector<monster>& monsterList)
{
    ui->bookWidget->show();
    int length = monsterList.size();
    ui->bookWidget->setRowCount(length*2);
    ui->bookWidget->setColumnCount(5);
    ui->bookWidget->horizontalHeader()->setHidden(true);
    ui->bookWidget->verticalHeader()->setHidden(true);
    ui->bookWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->bookWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->bookWidget->setFocusPolicy(Qt::NoFocus);
    ui->bookWidget->setColumnWidth(0,100);
    ui->bookWidget->setColumnWidth(1,120);
    ui->bookWidget->setColumnWidth(2,120);
    ui->bookWidget->setColumnWidth(3,120);
    ui->bookWidget->setColumnWidth(4,120);
    int j=0;
    for(auto i=monsterList.begin();i!=monsterList.end();i++,j++)
    {
        QLabel *labelEny = new QLabel("");
        QString enyKey="e_"+QString::number(i->id);
        QString imgPath;
        if(flash_flag)
            imgPath=map_hash.find(enyKey).value();
        else
            imgPath=map_hash_flash.find(enyKey).value();
        labelEny->setPixmap(QPixmap(imgPath).scaled(60,60));
        labelEny->setStyleSheet("border:0;padding-left:20");
        ui->bookWidget->setSpan(j*2,0,2,1);
        ui->bookWidget->setCellWidget(j*2,0,labelEny);
        ui->bookWidget->setItem(j*2,1,new QTableWidgetItem("攻击"));
        ui->bookWidget->setItem(j*2,2,new QTableWidgetItem(QString::number(i->attack)));
        ui->bookWidget->setItem(j*2,3,new QTableWidgetItem("金·经"));
        ui->bookWidget->setItem(j*2,4,new QTableWidgetItem(QString::number(i->gold)+"·"+QString::number(i->exp)));
        ui->bookWidget->setItem(j*2+1,1,new QTableWidgetItem("防御"));
        ui->bookWidget->setItem(j*2+1,2,new QTableWidgetItem(QString::number(i->defence)));
        ui->bookWidget->setItem(j*2+1,3,new QTableWidgetItem("生命"));
        ui->bookWidget->setItem(j*2+1,4,new QTableWidgetItem(QString::number(i->health)));

        ui->bookWidget->setRowHeight(j*2,40);
        ui->bookWidget->setRowHeight(j*2+1,40);
        ui->bookWidget->item(j*2,1)->setTextAlignment(Qt::AlignCenter);
        ui->bookWidget->item(j*2,2)->setTextAlignment(Qt::AlignCenter);
        ui->bookWidget->item(j*2,3)->setTextAlignment(Qt::AlignCenter);
        ui->bookWidget->item(j*2,4)->setTextAlignment(Qt::AlignCenter);
        ui->bookWidget->item(j*2+1,1)->setTextAlignment(Qt::AlignCenter);
        ui->bookWidget->item(j*2+1,2)->setTextAlignment(Qt::AlignCenter);
        ui->bookWidget->item(j*2+1,3)->setTextAlignment(Qt::AlignCenter);
        ui->bookWidget->item(j*2+1,4)->setTextAlignment(Qt::AlignCenter);
    }
}
void MagicMap::closeBook()
{
    ui->bookWidget->hide();
}

