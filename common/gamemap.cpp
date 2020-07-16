#include "gamemap.h"

GameMap::GameMap(QObject *parent) : QObject(parent)
{

}


QString GameMap::getData(int l, int x, int y) const {
    return m_data[l][x][y];
}

void GameMap::setData(int l, int x, int y, const QString &newValue) {
    if (m_data[l][x][y] != newValue) {
        m_data[l][x][y] = newValue;
        emit dataChanged(l, x, y, newValue);
    }
}
