#ifndef COMMON_H
#define COMMON_H

namespace MagicTower {

const int MAP_WIDTH         = 11;
const int MAP_HEIGHT        = 11;
const int MAP_LAYER         = 24;
const int ITEM_TYPE_COUNT   = 20;
const int KEY_TYPE_COUNT    = 3;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef enum {
    YELLOW_KEY,
    BLUE_KEY,
    RED_KEY
} KeyType;

typedef enum {
    /* TODO */
} ItemType;

}; // MAGIC_TOWER

#endif // COMMON_H
