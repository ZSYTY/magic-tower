#include "gamemodel.h"

GameModel::GameModel(QObject *parent) : QObject(parent)
{
    player  = std::make_shared<Player>();
    map     = std::make_shared<GameMap>();
    database.connect("data");
    database.loadMap(map);
    database.loadPlayer(player);
}

void GameModel::playerMove(MagicTower::Direction direction) {
    qDebug("playerMove: %d\n", direction);
    player->setDirection(direction);
    auto position = player->getPosition(), newPosition = position;
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
    if (/* TODO */ newPosition.first >= 0 && newPosition.first < MagicTower::MAP_HEIGHT && newPosition.second >= 0 && newPosition.second < MagicTower::MAP_WIDTH) {
        player->setPosition(newPosition);
    }
}

std::shared_ptr<Player> GameModel::getPlayer() const {
    return player;
}

std::shared_ptr<GameMap> GameModel::getGameMap() const{
    return map;
}
