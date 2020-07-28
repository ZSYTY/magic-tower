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

    void setMapData(int l, int x, int y, const QString &newValue);
    void setHealth(int newValue);
    void setAttack(int newValue);
    void setDefence(int newValue);
    void setGold(int newValue);
    void setExp(int newValue);
    void setLevel(int newValue);
    void setLayer(int newValue);
    void setKeyCount(MagicTower::KeyType keyType, int newValue);
    void setItemOwn(MagicTower::ItemType itemType, bool newValue);
    void setPosition(QPair<int, int> newValue);
    void setDirection(MagicTower::Direction newValue);
    void emitAll();

signals:
    void playerWin(const QString& info);
    void itemGet(const QString& info);
    void openModal(const QString& info);
    void closeModal();
    void openBook(const QVector<monster>& monsterList);
    void closeBook();
    void mapDataChanged(int l, int x, int y, const QString &newValue);
    void healthChanged(int newValue);
    void attackChanged(int newValue);
    void defenceChanged(int newValue);
    void goldChanged(int newValue);
    void expChanged(int newValue);
    void levelChanged(int newValue);
    void layerChanged(int newValue);
    void keyCountChanged(MagicTower::KeyType keyType, int newValue);
    void itemOwnChanged(MagicTower::ItemType itemType, bool newValue);
    void positionChanged(QPair<int, int> newValue);
    void directionChanged(MagicTower::Direction newValue);
};

#endif // GAMEMODEL_H
