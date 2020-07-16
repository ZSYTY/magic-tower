#ifndef PLAYER_H
#define PLAYER_H

#include "common/common.h"
#include <QObject>
#include <QVector>

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);

    /* Getters */
    int getHealth() const;
    int getAttack() const;
    int getDefence() const;
    int getGold() const;
    int getExp() const;
    int getLevel() const;
    int getLayer() const;
    int getKeyCount(MagicTower::KeyType keyType) const;
    bool getItemOwn(MagicTower::ItemType itemType) const;
    QPair<int, int> getPosition() const;
    MagicTower::Direction getDirection() const;

    /* Setters */
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

private:
    int                     m_health;
    int                     m_attack;
    int                     m_defence;
    int                     m_gold;
    int                     m_exp;
    int                     m_level;
    int                     m_layer;
    int                     m_keyCount[MagicTower::KEY_TYPE_COUNT];
    bool                    m_itemOwn[MagicTower::ITEM_TYPE_COUNT];
    QPair<int, int>         m_position;
    MagicTower::Direction   m_direction;

signals:
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

#endif // PLAYER_H
