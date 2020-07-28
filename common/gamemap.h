#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "common/common.h"
#include <QObject>
#include <QString>
#include <QVector>
#include <QPair>

class GameMap {

public:
    explicit GameMap();
    QString getData(int l, int x, int y) const;
    bool setData(int l, int x, int y, const QString &newValue);
    QPair<int, int> findStr(int l, QString str);

private:
    QVector<QVector<QVector<QString>>> m_data;

};

#endif // GAMEMAP_H
