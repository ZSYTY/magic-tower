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

Direction Player::getDirection() const {
    return m_direction;
}

QVector<int> &Player::getItems() {
    return m_items;
}

void Player::setHealth(int newValue) {
    m_health = newValue;
}

void Player::setAttack(int newValue) {
    m_attack = newValue;
}

void Player::setDefence(int newValue) {
    m_defence = newValue;
}

void Player::setGold(int newValue) {
    m_gold = newValue;
}

void Player::setExp(int newValue) {
    m_exp = newValue;
}

void Player::setPosition(QPair<int, int> newValue) {
    m_position = newValue;
}

void Player::setDirection(Direction newValue) {
    m_direction = newValue;
}
