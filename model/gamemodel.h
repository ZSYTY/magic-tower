#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include <memory>
#include "common/player.h"
#include "common/gamemap.h"

class GameModel : public QObject
{
    Q_OBJECT
public:
    explicit GameModel(QObject *parent = nullptr);
    GameModel(const GameModel&) = delete;
    GameModel& operator=(const GameModel&) = delete;

    void playerMove(MagicTower::Direction direction);
    std::shared_ptr<Player> getPlayer() const;

private:
    std::shared_ptr<GameMap>    map;
    std::shared_ptr<Player>     player;

signals:

};

#endif // GAMEMODEL_H
