#include "gamemodel.h"

GameModel::GameModel(QObject *parent) : QObject(parent)
{

}

void GameModel::playerMove(MagicTower::Direction direction) {
    qDebug("playerMove: %d\n", direction);
}
