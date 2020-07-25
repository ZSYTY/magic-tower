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
    qDebug() << id;
}
