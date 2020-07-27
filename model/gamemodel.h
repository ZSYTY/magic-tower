#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include <QVector>
#include <QSet>
#include <memory>
#include "common/player.h"
#include "common/gamemap.h"
#include "database.h"

class GameModel : public QObject
{
    Q_OBJECT
public:
    explicit GameModel(QObject *parent = nullptr);
    GameModel(const GameModel&) = delete;
    GameModel& operator=(const GameModel&) = delete;

    void playerMove(MagicTower::Direction direction);
    void playerChoose(int choice);
    void gameSave();
    void gameLoad();
    void gameRestart();
    void useBook();
    std::shared_ptr<Player> getPlayer() const;
    std::shared_ptr<GameMap> getGameMap() const;

private:
    std::shared_ptr<GameMap>    map;
    std::shared_ptr<Player>     player;
    Database                    database;
    int                         meetNpc;
    bool                        isBookOpened;

signals:
    void playerWin(const QString& info);
    void itemGet(const QString& info);
    void openModal(const QString& info);
    void closeModal();
    void openBook(const QVector<monster>& monsterList);
    void closeBook();
};

#endif // GAMEMODEL_H
