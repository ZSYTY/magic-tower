#include "magicmap.h"
#include "ui_magicmap.h"

MagicMap::MagicMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MagicMap)
{
    ui->setupUi(this);
}

MagicMap::~MagicMap()
{
    delete ui;
}

void MagicMap::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    painter.translate(0,0);
    pix.load(":/assets/Images/878.jpg");
    painter.drawPixmap(0,0,width(),height(),pix);
}
