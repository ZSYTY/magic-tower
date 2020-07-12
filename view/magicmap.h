#ifndef MAGICMAP_H
#define MAGICMAP_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <functional>
#include "common/common.h"

namespace Ui {
class MagicMap;
}

class MagicMap : public QWidget
{
    Q_OBJECT

public:
    explicit MagicMap(QWidget *parent = nullptr);
    ~MagicMap();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    Ui::MagicMap *ui;
};

#endif // MAGICMAP_H
