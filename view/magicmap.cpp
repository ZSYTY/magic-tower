#include "magicmap.h"
#include "ui_magicmap.h"

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

    /* Draw player */
    if (m_player != nullptr) {
        auto direction  = m_player->getDirection();
        auto position   = m_player->getPosition();
        pix.load(playerImageHash[direction]);
        int picWidth   = width() / MagicTower::MAP_WIDTH;
        int picHeight  = height() / MagicTower::MAP_HEIGHT;
        painter.drawPixmap(position.second * picWidth, position.first * picHeight, picWidth, picHeight, pix);
    }
}

void MagicMap::attachPlayer(const std::shared_ptr<Player> &player) {
    m_player = player;
    /* Why to call static_cast here, see: https://asmaloney.com/2015/05/code/qsignalmapper-example-revisited/ */
    QObject::connect(m_player.get(), &Player::positionChanged, this, static_cast<void (MagicMap::*)()>(&MagicMap::update), Qt::QueuedConnection);
    QObject::connect(m_player.get(), &Player::directionChanged, this, static_cast<void (MagicMap::*)()>(&MagicMap::update), Qt::QueuedConnection);
    repaint();
}
