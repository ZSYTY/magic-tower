#include "gamemodel.h"

GameModel::GameModel(QObject *parent) : QObject(parent)
{
    meetNpc = false;
    player  = std::make_shared<Player>();
    map     = std::make_shared<GameMap>();
    database.connect("data");
    database.loadMap(map);
    database.loadPlayer(player);
    database.loadItems();
}

void GameModel::playerMove(MagicTower::Direction direction) {
    if (meetNpc) {
        return;
    }
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
                if (id == 4) {
                    if (newPosition.second == 5) {
                        map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                        map->setData(player->getLayer(), newPosition.first, newPosition.second - 1, "me_4");
                    }
                } else if (id == 3) {
                    emit openModal("商人: 用25元换取任意一项:\n1. 增加800点生命\n2. 增加4点攻击\n3. 增加4点防御\n0. 取消");
                    meetNpc = 3;
                } else if (id == 2) {
                    emit openModal("商人: 经验换实力.\n1. 提升一级(100经验)\n2. 增加5点攻击(30经验)\n3. 增加5点防御(30点经验)");
                    meetNpc = 2;
                } else if (id == 1) {
                    emit openModal("商人: 金币换钥匙.\n1. 购买一把黄钥匙($10)\n2. 购买一把蓝钥匙($50)\n3. 购买一把红钥匙($100)");
                    meetNpc = 1;
                }
                /* TODO: different merchant */
            } else if (type == "k") { /* key */
                map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                player->setKeyCount((MagicTower::KeyType)id, player->getKeyCount((MagicTower::KeyType)id) + 1);
                const QString colorList[MagicTower::KEY_TYPE_COUNT] = {"黄", "蓝", "红"};
                emit itemGet("获得了" + colorList[id] + "钥匙一把");
            } else if (type == "dr") { /* door */
                if (id < 3 && player->getKeyCount((MagicTower::KeyType)id)) {
                    map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                    player->setKeyCount((MagicTower::KeyType)id, player->getKeyCount((MagicTower::KeyType)id) - 1);
                }
            } else if (type == "m") { /* medicine */
                map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                medicine cur = database.getMedicine(id);
                if (cur.health) {
                    player->setHealth(player->getHealth() + cur.health);
                    emit itemGet("生命回复了 " + QString::number(cur.health));
                }
                if (cur.attack) {
                    player->setAttack(player->getAttack() + cur.attack);
                    emit itemGet("攻击上升了 " + QString::number(cur.attack));
                }
                if (cur.defence) {
                    player->setDefence(player->getDefence() + cur.defence);
                    emit itemGet("防御上升了 " + QString::number(cur.defence));
                }
            } else if (type == "a") { /* armour */
                map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                armour cur = database.getArmour(id);
                player->setDefence(player->getDefence() + cur.defence);
                emit itemGet("防御上升了 " + QString::number(cur.defence));
            } else if (type == "s") { /* weapon */
                map->setData(player->getLayer(), newPosition.first, newPosition.second, ".");
                weapon cur = database.getWeapon(id);
                player->setDefence(player->getDefence() + cur.attack);
                emit itemGet("攻击上升了 " + QString::number(cur.attack));
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
                        emit playerWin("得到金币数 " + QString::number(cur.gold) + "得到经验值 " + QString::number(cur.exp));
                    }
                }
            }
        }
        if (willMove) {
            player->setPosition(newPosition);
        }
    }
}


void GameModel::playerChoose(int choice) {
    if (meetNpc == 3) {
        if (choice >= 0 && choice <= 3) {
            if (player->getGold() >= 25) {
                player->setGold(player->getGold() - 25);
                if (choice == 1) {
                    player->setHealth(player->getHealth() + 800);
                } else if (choice == 2) {
                    player->setAttack(player->getAttack() + 4);
                } else if (choice == 3) {
                    player->setDefence(player->getDefence() + 4);
                }
            }
            meetNpc = 0;
            emit closeModal();
        }
    } else if (meetNpc == 2) {
        if (choice >= 0 && choice <= 3) {
            if (choice == 1) {
                if (player->getExp() >= 100) {
                    player->setExp(player->getExp() - 100);
                    player->setHealth(player->getHealth() + 1000);
                    player->setAttack(player->getAttack() + 7);
                    player->setDefence(player->getDefence() + 7);
                }
            } else if (choice == 2) {
                if (player->getExp() >= 30) {
                    player->setExp(player->getExp() - 30);
                    player->setAttack(player->getAttack() + 5);
                }
            } else if (choice == 3) {
                if (player->getExp() >= 30) {
                    player->setExp(player->getExp() - 30);
                    player->setDefence(player->getDefence() + 5);
                }
            }
            meetNpc = 0;
            emit closeModal();
        }
    } else if (meetNpc == 1) {
        if (choice >= 0 && choice <= 3) {
            if (choice == 1) {
                if (player->getGold() >= 10) {
                    player->setGold(player->getGold() - 10);
                    player->setKeyCount((MagicTower::KeyType)0, player->getKeyCount((MagicTower::KeyType)0) + 1);
                }
            } else if (choice == 2) {
                if (player->getGold() >= 50) {
                    player->setGold(player->getGold() - 50);
                    player->setKeyCount((MagicTower::KeyType)1, player->getKeyCount((MagicTower::KeyType)1) + 1);
                }
            } else if (choice == 3) {
                if (player->getGold() >= 100) {
                    player->setGold(player->getGold() - 100);
                    player->setKeyCount((MagicTower::KeyType)2, player->getKeyCount((MagicTower::KeyType)2) + 1);
                }
            }
            meetNpc = 0;
            emit closeModal();
        }
    }
}

std::shared_ptr<Player> GameModel::getPlayer() const {
    return player;
}

std::shared_ptr<GameMap> GameModel::getGameMap() const{
    return map;
}
