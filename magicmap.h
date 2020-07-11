#ifndef MAGICMAP_H
#define MAGICMAP_H

#include <QWidget>
#include <QPainter>

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
    void paintEvent(QPaintEvent *);

private:
    Ui::MagicMap *ui;
};

#endif // MAGICMAP_H
