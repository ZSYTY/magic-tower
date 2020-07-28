#include "magicmap.h"
#include "ui_magicmap.h"
#include <QColor>

MagicMap::MagicMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MagicMap)
{
    ui->setupUi(this);

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
    for(auto i=monsterList.begin();i!=monsterList.end();i++)
    {
        qDebug()<<i->id<<endl;
    }

}
void MagicMap::closeBook()
{
    qDebug()<<"close book";
}

