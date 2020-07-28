#ifndef MAGICMAP_H
#define MAGICMAP_H

#include <QWidget>
#include <QString>
#include <QHash>
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <memory>
#include <functional>
#include "common/common.h"
#include "common/player.h"
#include "common/item.h"
#include "common/gamemap.h"

namespace Ui {
class MagicMap;
}

class MagicMap : public QWidget
{
    Q_OBJECT

public:
    explicit MagicMap(QWidget *parent = nullptr);
    ~MagicMap();
    void attachPlayer(const std::shared_ptr<Player>& player);
    void attachGameMap(const std::shared_ptr<GameMap>& gamemap);
    /* std::shared_ptr<Player> detachPlayer() noexcept; */

protected:
    void paintEvent(QPaintEvent *) override;

private:
    Ui::MagicMap *ui;
    std::shared_ptr<Player> m_player;
    QHash<MagicTower::Direction, QString> playerImageHash;
    std::shared_ptr<GameMap> m_gamemap;
    QMap<QString,QString> map_hash;
    QMap<QString,QString> map_hash_flash;
    bool flash_flag;
    QTimer *m_Timer;

public slots:
    void shining();
    void openBook(const QVector<monster>& monsterList);
    void closeBook();
};

#endif // MAGICMAP_H
