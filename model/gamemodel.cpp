#include "gamemodel.h"

GameModel::GameModel(QObject *parent) : QObject(parent)
{
    player  = std::make_shared<Player>();
    map     = std::make_shared<GameMap>();
    database.connect("data");
    database.loadMap(map);
    database.loadPlayer(player);
    database.loadItems();
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
    if (newPosition.first >= 0 && newPosition.first < MagicTower::MAP_HEIGHT && newPosition.second >= 0 && newPosition.second < MagicTower::MAP_WIDTH) {
        bool willMove = false;
        QString statusStr = map->getData(player->getLayer(), newPosition.first, newPosition.second);
        QStringList status = statusStr.split('_');
        if (status.size() == 1) {
            QString &type = status[0];
            if (type == ".") { /* empty */
                willMove = true;
            } else if (type == "dn") { /* downstair */
                willMove = true;
                player->setLayer(player->getLayer() - 1);
                newPosition = map->findStr(player->getLayer(), "d_1");
                qDebug() << newPosition;
            } else if (type == "up") { /* upstair */
                willMove = true;
                player->setLayer(player->getLayer() + 1);
                newPosition = map->findStr(player->getLayer(), "d_0");
                qDebug() << newPosition;
            }
        } else if(status.size() == 2) {
            QString &type = status[0];
            int id = status[1].toInt();
            if (type == "d") { /* empty */
                willMove = true;
            } else if (type == "me") { /* merchant */
                willMove = true;
                /* TODO: different merchant */
            } else if (type == "k") { /* key */
                map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                player->setKeyCount((MagicTower::KeyType)id, player->getKeyCount((MagicTower::KeyType)id) + 1);
            } else if (type == "dr") { /* door */
                if (player->getKeyCount((MagicTower::KeyType)id)) {
                    map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                    player->setKeyCount((MagicTower::KeyType)id, player->getKeyCount((MagicTower::KeyType)id) - 1);
                }
            } else if (type == "m") { /* medicine */
                map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                medicine cur = database.getMedicine(id);
                player->setHealth(player->getHealth() + cur.health);
                player->setAttack(player->getAttack() + cur.attack);
                player->setDefence(player->getDefence() + cur.defence);
            } else if (type == "a") { /* armour */
                map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                armour cur = database.getArmour(id);
                player->setDefence(player->getDefence() + cur.defence);
            } else if (type == "w") { /* weapon */
                map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                weapon cur = database.getWeapon(id);
                player->setDefence(player->getDefence() + cur.attack);
            } else if (type == "e") { /* enemy */
                monster cur = database.getMonster(id);
                int damage = player->getAttack() - cur.defence;
                qDebug() << cur.health << cur.attack << cur.defence;
                if (damage > 0) {
                    int roundCnt = (cur.health + damage - 1) / damage;
                    int monsterDamage = qMax(cur.attack - player->getDefence(), 0);
                    if (player->getHealth() > monsterDamage * roundCnt) { /* win */
                        map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                        player->setHealth(player->getHealth() - monsterDamage * roundCnt);
                        player->setGold(player->getGold() + cur.gold);
                        player->setExp(player->getExp() + cur.exp);
                    }
                }
            }
        }
        if (willMove) {
            player->setPosition(newPosition);
        }
    }
}

std::shared_ptr<Player> GameModel::getPlayer() const {
    return player;
}
