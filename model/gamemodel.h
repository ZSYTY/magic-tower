#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include "data/player.h"
#include "data/gamemap.h"

class GameModel : public QObject
{
    Q_OBJECT
public:
    explicit GameModel(QObject *parent = nullptr);
    GameModel(const GameModel&) = delete;
    GameModel& operator=(const GameModel&) = delete;

    void playerMove(MagicTower::Direction direction);

private:
    GameMap     map;
    Player      player;

signals:

};

#endif // GAMEMODEL_H
