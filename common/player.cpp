#include "player.h"

Player::Player(QObject *parent) : QObject(parent) {
    /* TODO: should init from database */
    m_health = 100;
    m_attack = 5;
    m_defence = 5;
    m_gold = 3;
    m_exp = 3;
}

int Player::getHealth() const {
    return m_health;
}

int Player::getAttack() const {
    return m_attack;
}

int Player::getDefence() const {
    return m_defence;
}

int Player::getGold() const {
    return m_gold;
}

int Player::getExp() const {
    return m_exp;
}

QPair<int, int> Player::getPosition() const {
    return m_position;
}

MagicTower::Direction Player::getDirection() const {
    return m_direction;
}

QVector<int>& Player::getItems() {
    return m_items;
}

void Player::setHealth(int newValue) {
    if (m_health != newValue) {
        m_health = newValue;
        emit healthChanged(newValue);
    }
}

void Player::setAttack(int newValue) {
    if (m_attack != newValue) {
        m_attack = newValue;
        emit attackChanged(newValue);
    }
}

void Player::setDefence(int newValue) {
    if (m_defence != newValue) {
        m_defence = newValue;
        emit defenceChanged(newValue);
    }
}

void Player::setGold(int newValue) {
    if (m_gold != newValue) {
        m_gold = newValue;
        emit goldChanged(newValue);
    }
}

void Player::setExp(int newValue) {
    if (m_exp != newValue) {
        m_exp = newValue;
        emit expChanged(newValue);
    }
}

void Player::setPosition(QPair<int, int> newValue) {
    if (m_position != newValue) {
        m_position = newValue;
        emit positionChanged(newValue);
    }
}

void Player::setDirection(MagicTower::Direction newValue) {
    if (m_direction != newValue) {
        m_direction = newValue;
        emit directionChanged(newValue);
    }
}
