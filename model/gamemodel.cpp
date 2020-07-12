#include "gamemodel.h"

GameModel::GameModel(QObject *parent) : QObject(parent)
{

}

void GameModel::playerMove(MagicTower::Direction direction) {
    qDebug("playerMove: %d\n", direction);
    player.setDirection(direction);
    auto position = player.getPosition(), newPosition = position;
    switch (direction) {
    case MagicTower::LEFT:
        newPosition.second--;
        break;
    case MagicTower::RIGHT:
        newPosition.second++;
        break;
    case MagicTower::UP:
        newPosition.first--;
        break;
    case MagicTower::DOWN:
        newPosition.first++;
        break;
    }
    if (/* TODO */ newPosition.first >= 0 and newPosition.first < MagicTower::MAP_HEIGHT and newPosition.second >= 0 and newPosition.second < MagicTower::MAP_WIDTH) {
        player.setPosition(newPosition);
    }
}
