#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    InitPlayerWidget();
    InitKeysWidget();
    InitLevelWidget();
    InitOptionsWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::InitPlayerWidget()
{
    ui->playerDataWidget->setRowCount(6);
    ui->playerDataWidget->setColumnCount(2);
    QIcon playerImg;
    playerImg.addFile(":/assets/Images/415_.png");
    ui->playerDataWidget->setItem(0,0,new QTableWidgetItem(playerImg,""));
    ui->playerDataWidget->setItem(1,0,new QTableWidgetItem("生命"));
    ui->playerDataWidget->setItem(1,1,new QTableWidgetItem("1000"));
    ui->playerDataWidget->setItem(2,0,new QTableWidgetItem("攻击"));
    ui->playerDataWidget->setItem(2,1,new QTableWidgetItem("0"));
    ui->playerDataWidget->setItem(3,0,new QTableWidgetItem("防御"));
    ui->playerDataWidget->setItem(3,1,new QTableWidgetItem("0"));
    ui->playerDataWidget->setItem(4,0,new QTableWidgetItem("金币"));
    ui->playerDataWidget->setItem(4,1,new QTableWidgetItem("0"));
    ui->playerDataWidget->setItem(5,0,new QTableWidgetItem("经验"));
    ui->playerDataWidget->setItem(5,1,new QTableWidgetItem("0"));
    ui->playerDataWidget->setIconSize(QSize(60,60));
    ui->playerDataWidget->horizontalHeader()->setHidden(true);
    ui->playerDataWidget->verticalHeader()->setHidden(true);
    ui->playerDataWidget->setShowGrid(false);
    ui->playerDataWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playerDataWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->playerDataWidget->setFocusPolicy(Qt::NoFocus);
    ui->playerDataWidget->setColumnWidth(0,100);
    ui->playerDataWidget->setColumnWidth(1,100);

    ui->playerDataWidget->setRowHeight(0,80);
    ui->playerDataWidget->setRowHeight(1,40);
    ui->playerDataWidget->setRowHeight(2,40);
    ui->playerDataWidget->setRowHeight(3,40);
    ui->playerDataWidget->setRowHeight(4,40);
    ui->playerDataWidget->setRowHeight(5,40);
    for(int i=1;i<6;i++)
        for(int j=0;j<2;j++)
        {
            if(j==1)
            {
                QFont numFont;
                numFont.setItalic(true);
                ui->playerDataWidget->item(i,j)->setFont(numFont);
            }
            ui->playerDataWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }

}
void MainWindow::InitKeysWidget()
{
    ui->keysDataWidget->setRowCount(3);
    ui->keysDataWidget->setColumnCount(2);
    ui->keysDataWidget->setItem(0,0,new QTableWidgetItem("金钥匙"));
    ui->keysDataWidget->setItem(1,0,new QTableWidgetItem("蓝钥匙"));
    ui->keysDataWidget->setItem(2,0,new QTableWidgetItem("黄钥匙"));
    ui->keysDataWidget->horizontalHeader()->setHidden(true);
    ui->keysDataWidget->verticalHeader()->setHidden(true);
    ui->keysDataWidget->setShowGrid(false);
    ui->keysDataWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->keysDataWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->keysDataWidget->setFocusPolicy(Qt::NoFocus);
}

void MainWindow::InitLevelWidget()
{
    ui->levelDataWidget->addItem("序章");
    ui->levelDataWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->levelDataWidget->setFocusPolicy(Qt::NoFocus);
}
void MainWindow::InitOptionsWidget()
{
    ui->optionsDataWidget->addItem("ctrl S 保存    ctrl Q 退出程序");
    ui->optionsDataWidget->addItem("ctrl A 读取    ctrl R 重新开始");
    ui->optionsDataWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->optionsDataWidget->setFocusPolicy(Qt::NoFocus);
}

std::shared_ptr<QVector<int>> MainWindow::getPtrToPlayerData()
{
    return ptrToPlayerData;
}

std::shared_ptr<QVector<int>> MainWindow::getPtrToKeysData()
{
    return ptrToKeysData;
}

std::shared_ptr<int> MainWindow::getPtrToLevelData()
{
    return ptrToLevelData;
}
