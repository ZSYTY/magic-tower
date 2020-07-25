#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "common/common.h"
#include <QObject>
#include <QString>
#include <QVector>

class GameMap : public QObject
{
    Q_OBJECT
public:
    explicit GameMap(QObject *parent = nullptr);
    /* TODO */
    QString getData(int l, int x, int y) const;
    void setData(int l, int x, int y, const QString &newValue);

private:
    QVector<QVector<QVector<QString>>> m_data;

signals:
    void dataChanged(int l, int x, int y, const QString &newValue);
};

#endif // GAMEMAP_H
