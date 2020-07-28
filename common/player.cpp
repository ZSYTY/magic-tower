#include "player.h"

Player::Player() {

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

bool Player::setHealth(int newValue) {
    if (m_health != newValue) {
        m_health = newValue;
        return true;
    }
    return false;
}

bool Player::setAttack(int newValue) {
    if (m_attack != newValue) {
        m_attack = newValue;
        return true;
    }
    return false;
}

bool Player::setDefence(int newValue) {
    if (m_defence != newValue) {
        m_defence = newValue;
        return true;
    }
    return false;
}

bool Player::setGold(int newValue) {
    if (m_gold != newValue) {
        m_gold = newValue;
        return true;
    }
    return false;
}

bool Player::setExp(int newValue) {
    if (m_exp != newValue) {
        m_exp = newValue;
        return true;
    }
    return false;
}

bool Player::setLevel(int newValue) {
    if (m_level != newValue) {
        m_level = newValue;
        return true;
    }
    return false;
}

bool Player::setLayer(int newValue) {
    if (m_layer != newValue) {
        m_layer = newValue;
        return true;
    }
    return false;
}

bool Player::setKeyCount(MagicTower::KeyType keyType, int newValue) {
    if (m_keyCount[keyType] != newValue) {
        m_keyCount[keyType] = newValue;
        return true;
    }
    return false;
}

bool Player::setItemOwn(MagicTower::ItemType itemType, bool newValue) {
    if (m_itemOwn[itemType] != newValue) {
        m_itemOwn[itemType] = newValue;
        return true;
    }
    return false;
}

bool Player::setPosition(QPair<int, int> newValue) {
    if (m_position != newValue) {
        m_position = newValue;
        return true;
    }
    return false;
}

bool Player::setDirection(MagicTower::Direction newValue) {
    if (m_direction != newValue) {
        m_direction = newValue;
        return true;
    }
    return false;
}
