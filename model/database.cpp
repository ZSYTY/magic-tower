#include "database.h"

Database::Database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

Database::~Database() {
    db.close();
}

void Database::connect(const QString &dbName) {
    db.setDatabaseName(dbName);
    if (! db.open()) {
        qWarning() << "database open error: " << db.lastError().text();
    }

    QFile file(":/model/database/data.sql");
    if (! file.exists()) {
        qDebug() << "file not open";
    }

    QSqlQuery query(db);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QStringList queryList = QTextStream(&file).readAll().split(';');
        foreach (QString queryText, queryList) {
            if (queryText.trimmed().isEmpty()) {
                continue;
            }
            if (! query.exec(queryText)) {
                qWarning() << "query executed error: " << query.lastError().text();
            }
            query.finish();
        }
    }
    file.close();
}

void Database::loadMap(std::shared_ptr<GameMap> gamemap, int id) {
    QSqlQuery query(db);
    QString str = "SELECT data FROM map WHERE id = " + QString::number(id);
    query.exec(str);
    query.next();
    QStringList mapItemList = query.value(0).toString().split(',');
    int idx = 0;
    foreach (QString item, mapItemList) {
        int layer = idx / (MagicTower::MAP_WIDTH * MagicTower::MAP_HEIGHT);
        int x = idx % (MagicTower::MAP_WIDTH * MagicTower::MAP_HEIGHT) / (MagicTower::MAP_WIDTH);
        int y = idx % MagicTower::MAP_WIDTH;
        gamemap->setData(layer, x, y, item);
        idx++;
    }
}

void Database::saveMap(std::shared_ptr<GameMap> gamemap, int id) {
    QString data = "";
    for (int l = 0; l < MagicTower::MAP_LAYER; l++) {
        for (int x = 0; x < MagicTower::MAP_HEIGHT; x++) {
            for (int y = 0; y < MagicTower::MAP_WIDTH; y++) {
                if (l | x | y) {
                    data += ",";
                }
                data += gamemap->getData(l, x, y);
            }
        }
    }
    QSqlQuery query(db);
    QString str = "REPLACE INTO map(id, data) VALUES (" + QString::number(id) + ",'" + data + "')";
    query.exec(str);
}

void Database::loadPlayer(std::shared_ptr<Player> player, int id) {
    QSqlQuery query(db);
    QString str = "SELECT * FROM player WHERE id = " + QString::number(id);
    query.exec(str);
    query.next();
    player->setLevel(query.value(1).toInt());
    player->setHealth(query.value(2).toInt());
    player->setAttack(query.value(3).toInt());
    player->setDefence(query.value(4).toInt());
    player->setGold(query.value(5).toInt());
    player->setExp(query.value(6).toInt());
    player->setLayer(query.value(7).toInt());
    player->setPosition(QPair<int, int>(query.value(8).toInt(), query.value(9).toInt()));
    player->setDirection((MagicTower::Direction)query.value(10).toInt());
    player->setKeyCount(MagicTower::YELLOW_KEY, query.value(11).toInt());
    player->setKeyCount(MagicTower::BLUE_KEY, query.value(12).toInt());
    player->setKeyCount(MagicTower::RED_KEY, query.value(13).toInt());
    QString itemStr = query.value(14).toString();
    for (int i = 0; i < itemStr.size(); i++) {
        player->setItemOwn((MagicTower::ItemType)i, itemStr[i] == '1');
    }
}

void Database::savePlayer(std::shared_ptr<Player> player, int id) {
    QSqlQuery query(db);
    QString itemStr = "";
    for (int i = 0; i < itemStr.size(); i++) {
        itemStr += player->getItemOwn((MagicTower::ItemType)i) ? "1" : "0";
    }
    QString str = "REPLACE INTO `player` (`id`,`level`, `health`, `attack`, `defence`, `gold`, `exp`, `layer`, `position_x`, `position_y`, `direction`, `yellow_key`, `blue_key`, `red_key`, `items`) VALUES ("
            + QString::number(id) + "'"
            + QString::number(player->getLevel()) + ","
            + QString::number(player->getHealth()) + ","
            + QString::number(player->getAttack()) + ","
            + QString::number(player->getDefence()) + ","
            + QString::number(player->getGold()) + ","
            + QString::number(player->getExp()) + ","
            + QString::number(player->getLayer()) + ","
            + QString::number(player->getPosition().first) + ","
            + QString::number(player->getPosition().second) + ","
            + QString::number(player->getDirection()) + ","
            + QString::number(player->getKeyCount(MagicTower::YELLOW_KEY)) + ","
            + QString::number(player->getKeyCount(MagicTower::BLUE_KEY)) + ","
            + QString::number(player->getKeyCount(MagicTower::RED_KEY)) + ",'"
            + itemStr + "')";
    query.exec(str);
}

void Database::loadItems() {
    QSqlQuery query(db);
    QString str = "SELECT * FROM monster";
    query.exec(str);
    while (query.next()) {
        monster cur(query.value(1).toInt(),
                    query.value(2).toInt(),
                    query.value(3).toInt(),
                    query.value(4).toInt(),
                    query.value(5).toInt(),
                    query.value(6).toInt());
        monsterList[cur.id] = cur;
    }

    str = "SELECT * FROM medicine";
    query.exec(str);
    while (query.next()) {
        medicine cur(query.value(1).toInt(),
                     query.value(2).toInt(),
                     query.value(3).toInt(),
                     query.value(4).toInt());
        medicineList[cur.id] = cur;
    }

    str = "SELECT * FROM weapon";
    query.exec(str);
    while (query.next()) {
        weapon cur(query.value(1).toInt(),
                   query.value(2).toInt());
        weaponList[cur.id] = cur;
    }

    str = "SELECT * FROM armour";
    query.exec(str);
    while (query.next()) {
        armour cur(query.value(1).toInt(),
                   query.value(2).toInt());
        armourList[cur.id] = cur;
    }
}

monster Database::getMonster(int id) {
    return monsterList[id];
}

medicine Database::getMedicine(int id) {
    return medicineList[id];
}

weapon Database::getWeapon(int id) {
    return weaponList[id];
}

armour Database::getArmour(int id) {
    return armourList[id];
}


