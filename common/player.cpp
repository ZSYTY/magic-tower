#include "player.h"

Player::Player(QObject *parent) : QObject(parent) {
    /* TODO: should init from database */
    m_health = 100;
    m_attack = 5;
    m_defence = 5;
    m_gold = 3;
    m_exp = 3;
    m_keyCount[MagicTower::YELLOW_KEY] = 1;
    m_keyCount[MagicTower::BLUE_KEY] = 1;
    m_keyCount[MagicTower::RED_KEY] = 1;
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

int Player::getLevel() const {
    return m_level;
}

int Player::getLayer() const {
    return m_layer;
}

int Player::getKeyCount(MagicTower::KeyType keyType) const {
    return m_keyCount[keyType];
}

bool Player::getItemOwn(MagicTower::ItemType itemType) const {
    return m_itemOwn[itemType];
}

QPair<int, int> Player::getPosition() const {
    return m_position;
}

MagicTower::Direction Player::getDirection() const {
    return m_direction;
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

void Player::setLevel(int newValue) {
    if (m_level != newValue) {
        m_level = newValue;
        emit levelChanged(newValue);
    }
}

void Player::setLayer(int newValue) {
    if (m_layer != newValue) {
        m_layer = newValue;
        emit layerChanged(newValue);
    }
}

void Player::setKeyCount(MagicTower::KeyType keyType, int newValue) {
    if (m_keyCount[keyType] != newValue) {
        m_keyCount[keyType] = newValue;
        emit keyCountChanged(keyType, newValue);
    }
}

void Player::setItemOwn(MagicTower::ItemType itemType, bool newValue) {
    if (m_itemOwn[itemType] != newValue) {
        m_itemOwn[itemType] = newValue;
        emit itemOwnChanged(itemType, newValue);
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
