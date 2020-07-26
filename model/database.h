#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QFile>
#include <QString>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QHash>
#include "common/gamemap.h"
#include "common/player.h"
#include "item.h"
#include <memory>

class Database
{
public:
    Database();
    ~Database();
    void connect(const QString& dbName);
    void loadMap(std::shared_ptr<GameMap> gamemap, int id = 0);
    void saveMap(std::shared_ptr<GameMap> gamemap, int id = 0);
    void loadPlayer(std::shared_ptr<Player> player, int id = 0);
    void savePlayer(std::shared_ptr<Player> player, int id = 0);
    void loadItems();
private:
    QSqlDatabase db;
    QHash<int, monster> monsterList;
    QHash<int, medicine> medicineList;
    QHash<int, weapon> weaponList;
    QHash<int, armour> armourList;
};

#endif // DATABASE_H
