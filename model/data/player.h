#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"
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
    Direction getDirection() const;
    QVector<int>& getItems();
    /* Setters */
    void setHealth(int newValue);
    void setAttack(int newValue);
    void setDefence(int newValue);
    void setGold(int newValue);
    void setExp(int newValue);
    void setPosition(QPair<int, int> newValue);
    void setDirection(Direction newValue);

private:
    int m_health;
    int m_attack;
    int m_defence;
    int m_gold;
    int m_exp;
    QPair<int, int> m_position;
    Direction m_direction;
    QVector<int> m_items;

signals:

};

#endif // PLAYER_H
