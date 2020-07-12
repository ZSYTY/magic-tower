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
    setFocusPolicy(Qt::ClickFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::InitPlayerWidget()
{
    ui->playerDataWidget->setRowCount(6);
    ui->playerDataWidget->setColumnCount(2);
    ui->playerDataWidget->setItem(1,0,new QTableWidgetItem("生命"));
    ui->playerDataWidget->setItem(2,0,new QTableWidgetItem("攻击"));
    ui->playerDataWidget->setItem(3,0,new QTableWidgetItem("防御"));
    ui->playerDataWidget->setItem(4,0,new QTableWidgetItem("金币"));
    ui->playerDataWidget->setItem(5,0,new QTableWidgetItem("经验"));
    ui->playerDataWidget->horizontalHeader()->setHidden(true);
    ui->playerDataWidget->verticalHeader()->setHidden(true);
    ui->playerDataWidget->setShowGrid(false);
    ui->playerDataWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playerDataWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->playerDataWidget->setFocusPolicy(Qt::NoFocus);
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
void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Up:
        m_playerMoveCommand(MagicTower::UP);
        break;
    case Qt::Key_Down:
        m_playerMoveCommand(MagicTower::DOWN);
        break;
    case Qt::Key_Left:
        m_playerMoveCommand(MagicTower::LEFT);
        break;
    case Qt::Key_Right:
        m_playerMoveCommand(MagicTower::RIGHT);
        break;
    default:
        break;
    }
}

void MainWindow::attachPlayerMoveCommand(std::function<void(MagicTower::Direction)> playerMoveCommand) {
    m_playerMoveCommand = playerMoveCommand;
}
