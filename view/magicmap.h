#ifndef MAGICMAP_H
#define MAGICMAP_H

#include <QWidget>
#include <QString>
#include <QHash>
#include <QPainter>
#include <QKeyEvent>
#include <memory>
#include <functional>
#include "common/common.h"
#include "common/player.h"

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
    /* std::shared_ptr<Player> detachPlayer() noexcept; */

protected:
    void paintEvent(QPaintEvent *) override;

private:
    Ui::MagicMap *ui;
    std::shared_ptr<Player> m_player;
    QHash<MagicTower::Direction, QString> playerImageHash;
};

#endif // MAGICMAP_H
