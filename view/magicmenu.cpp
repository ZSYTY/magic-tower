#include "magicmenu.h"
#include "ui_magicmenu.h"
#include <QDebug>

MagicMenu::MagicMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MagicMenu)
{
    ui->setupUi(this);
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(startGame()));
}

MagicMenu::~MagicMenu()
{
    delete ui;
}

void MagicMenu::startGame()
{
    qDebug()<<123;
    this->hide();
    emit startButtonClicked();
}
