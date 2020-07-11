#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QObject>

class GameMap : public QObject
{
    Q_OBJECT
public:
    explicit GameMap(QObject *parent = nullptr);
    /* TODO */

private:
    static const int MAP_WIDTH = 11;
    static const int MAP_HEIGHT = 11;
    static const int MAP_LAYER = 24;
    int m_data[MAP_LAYER][MAP_HEIGHT][MAP_WIDTH];

signals:

};

#endif // GAMEMAP_H
