#ifndef PLAYER_H
#define PLAYER_H

#include "common/common.h"
#include <QObject>
#include <QVector>

class Player {

public:
    explicit Player();

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
    bool setHealth(int newValue);
    bool setAttack(int newValue);
    bool setDefence(int newValue);
    bool setGold(int newValue);
    bool setExp(int newValue);
    bool setLevel(int newValue);
    bool setLayer(int newValue);
    bool setKeyCount(MagicTower::KeyType keyType, int newValue);
    bool setItemOwn(MagicTower::ItemType itemType, bool newValue);
    bool setPosition(QPair<int, int> newValue);
    bool setDirection(MagicTower::Direction newValue);

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

};

#endif // PLAYER_H
