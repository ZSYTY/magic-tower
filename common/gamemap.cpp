#include "gamemap.h"

GameMap::GameMap()
{
    m_data.resize(MagicTower::MAP_LAYER);
    for (int i = 0; i < MagicTower::MAP_LAYER; i++) {
        m_data[i].resize(MagicTower::MAP_HEIGHT);
        for (int j = 0; j < MagicTower::MAP_HEIGHT; j++) {
            m_data[i][j].resize(MagicTower::MAP_WIDTH);
        }
    }
}


QString GameMap::getData(int l, int x, int y) const {
    return m_data[l][x][y];
}

bool GameMap::setData(int l, int x, int y, const QString &newValue) {
    if (m_data[l][x][y] != newValue) {
        m_data[l][x][y] = newValue;
        return true;
    }
    return false;
}

QPair<int, int> GameMap::findStr(int l, QString str) {
    for (int x = 0; x < MagicTower::MAP_HEIGHT; x++) {
        for (int y = 0; y < MagicTower::MAP_WIDTH; y++) {
            if (getData(l, x, y) == str) {
                return QPair<int, int>(x, y);
            }
        }
    }
    return QPair<int, int>(-1, -1);
}
