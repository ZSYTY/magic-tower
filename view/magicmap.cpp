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

    //for view test
    m_gamemap=std::make_shared<GameMap>();
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
            ;                       //wait common
        for(int i=0;i<11;i++)
            for(int j=0;j<11;j++)
            {
                pix.load(":/assets/Images/221.bmp");   //draw the floor

                //int itemIndex=m_gamemap->getData(m_level,i,j);
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
    painter.drawRect(this->rect().x(),this->rect().y(),this->rect().width()-5,this->rect().height()-5);

}

void MagicMap::attachPlayer(const std::shared_ptr<Player> &player)
{
    m_player = player;
    /* Why to call static_cast here, see: https://asmaloney.com/2015/05/code/qsignalmapper-example-revisited/ */
    QObject::connect(m_player.get(), &Player::positionChanged, this, static_cast<void (MagicMap::*)()>(&MagicMap::update), Qt::QueuedConnection);
    QObject::connect(m_player.get(), &Player::directionChanged, this, static_cast<void (MagicMap::*)()>(&MagicMap::update), Qt::QueuedConnection);
    repaint();
}

void MagicMap::attachGameMap(const std::shared_ptr<GameMap>& gamemap)
{
    m_gamemap=gamemap;

    repaint();
}
