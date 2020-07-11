#include "gamemodel.h"

GameModel::GameModel(QObject *parent) : QObject(parent)
{

}

void GameModel::playerMove(Direction direction) {
    qDebug("playerMove: %d\n", direction);
}
