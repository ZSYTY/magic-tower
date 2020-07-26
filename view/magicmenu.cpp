#include "magicmenu.h"
#include "ui_magicmenu.h"
#include <QDebug>
#include <QFile>

MagicMenu::MagicMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MagicMenu)
{
    ui->setupUi(this);
    QFile file(":/assets/Styles/gameMenu.qss");
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
    QString stylesheet=in.readAll();
    qDebug()<<stylesheet;
    this->setStyleSheet(stylesheet);
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(startGame()));
}

MagicMenu::~MagicMenu()
{
    delete ui;
}

void MagicMenu::startGame()
{
    this->hide();
    emit startButtonClicked();
}
