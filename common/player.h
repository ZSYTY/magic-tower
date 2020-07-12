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
    QPair<int, int> getPosition() const;
    MagicTower::Direction getDirection() const;
    QVector<int>& getItems(); /* Fixme: no signal emit */
    /* Setters */
    void setHealth(int newValue);
    void setAttack(int newValue);
    void setDefence(int newValue);
    void setGold(int newValue);
    void setExp(int newValue);
    void setPosition(QPair<int, int> newValue);
    void setDirection(MagicTower::Direction newValue);

private:
    int                     m_health;
    int                     m_attack;
    int                     m_defence;
    int                     m_gold;
    int                     m_exp;
    QPair<int, int>         m_position;
    MagicTower::Direction   m_direction;
    QVector<int>            m_items;

signals:
    void healthChanged(int newValue);
    void attackChanged(int newValue);
    void defenceChanged(int newValue);
    void goldChanged(int newValue);
    void expChanged(int newValue);
    void positionChanged(QPair<int, int> newValue);
    void directionChanged(MagicTower::Direction newValue);
};

#endif // PLAYER_H
