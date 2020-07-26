#include "database.h"

Database::Database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

Database::~Database() {
    db.close();
}

#include <QCoreApplication>
#include <QDir>
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
    QString str = "UPDATE map SET data = '" + data + "' WHERE id = " + QString::number(id); /* TODO: INSERT */
    query.exec(str);
    query.next();
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

}
