#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "common/common.h"
#include <QObject>

class GameMap : public QObject
{
    Q_OBJECT
public:
    explicit GameMap(QObject *parent = nullptr);
    /* TODO */

private:
    int m_data[MagicTower::MAP_LAYER][MagicTower::MAP_HEIGHT][MagicTower::MAP_WIDTH];

signals:

};

#endif // GAMEMAP_H
