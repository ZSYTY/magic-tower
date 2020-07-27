#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup >
#include <QTextCursor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gameWidget->hide();
    this->setFixedSize(this->width(),this->height());
    InitPlayerWidget();
    InitKeysWidget();
    InitLevelWidget();
    InitOptionsWidget();

    ui->gainLabel->hide();
    ui->successLabel->hide();
    ui->intTextEdit->hide();
    ui->intTextEdit->setReadOnly(true);
    setFocusPolicy(Qt::ClickFocus);
    connect(ui->MenuWidget,SIGNAL(startButtonClicked()),this,SLOT(startGame()));
    connect(ui->MenuWidget,SIGNAL(exitButtonClicked()),this,SLOT(exitGame()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::InitPlayerWidget()
{
    ui->playerDataWidget->setRowCount(6);
    ui->playerDataWidget->setColumnCount(2);
    QLabel *label = new QLabel("");
    label->setPixmap(QPixmap(":/assets/Images/415_.png").scaled(40,40));
    label->setStyleSheet("border:0;padding-left:30");

    ui->playerDataWidget->setCellWidget(0,0,label);
    ui->playerDataWidget->setItem(0,1,new QTableWidgetItem("1   级"));
    ui->playerDataWidget->setItem(1,0,new QTableWidgetItem("生命"));
    ui->playerDataWidget->setItem(1,1,new QTableWidgetItem("1000"));
    ui->playerDataWidget->setItem(2,0,new QTableWidgetItem("攻击"));
    ui->playerDataWidget->setItem(2,1,new QTableWidgetItem("10"));
    ui->playerDataWidget->setItem(3,0,new QTableWidgetItem("防御"));
    ui->playerDataWidget->setItem(3,1,new QTableWidgetItem("10"));
    ui->playerDataWidget->setItem(4,0,new QTableWidgetItem("金币"));
    ui->playerDataWidget->setItem(4,1,new QTableWidgetItem("0"));
    ui->playerDataWidget->setItem(5,0,new QTableWidgetItem("经验"));
    ui->playerDataWidget->setItem(5,1,new QTableWidgetItem("0"));
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
    ui->playerDataWidget->item(0,1)->setTextAlignment(Qt::AlignCenter);
}
void MainWindow::InitKeysWidget()
{
    ui->keysDataWidget->setRowCount(3);
    ui->keysDataWidget->setColumnCount(3);
    QLabel *labelGolden = new QLabel("");
    labelGolden->setPixmap(QPixmap(":/assets/Images/190.bmp").scaled(50,50));
    labelGolden->setStyleSheet("border:0;padding-left:20");
    QLabel *labelBlue = new QLabel("");
    labelBlue->setPixmap(QPixmap(":/assets/Images/193.bmp").scaled(50,50));
    labelBlue->setStyleSheet("border:0;padding-left:20");
    QLabel *labelYellow = new QLabel("");
    labelYellow->setPixmap(QPixmap(":/assets/Images/196.bmp").scaled(50,50));
    labelYellow->setStyleSheet("border:0;padding-left:20");
    ui->keysDataWidget->setCellWidget(0,0,labelGolden);
    ui->keysDataWidget->setCellWidget(1,0,labelBlue);
    ui->keysDataWidget->setCellWidget(2,0,labelYellow);

    ui->keysDataWidget->setItem(0,1,new QTableWidgetItem("1"));
    ui->keysDataWidget->setItem(1,1,new QTableWidgetItem("1"));
    ui->keysDataWidget->setItem(2,1,new QTableWidgetItem("1"));


    ui->keysDataWidget->setItem(0,2,new QTableWidgetItem("个"));
    ui->keysDataWidget->setItem(1,2,new QTableWidgetItem("个"));
    ui->keysDataWidget->setItem(2,2,new QTableWidgetItem("个"));
    QFont numFont;
    numFont.setItalic(true);
    numFont.setPointSize(24);
    ui->keysDataWidget->item(0,1)->setFont(numFont);
    ui->keysDataWidget->item(1,1)->setFont(numFont);
    ui->keysDataWidget->item(2,1)->setFont(numFont);
    ui->keysDataWidget->setRowHeight(0,60);
    ui->keysDataWidget->setRowHeight(1,60);
    ui->keysDataWidget->setRowHeight(2,60);
    ui->keysDataWidget->setColumnWidth(1,50);
    ui->keysDataWidget->setColumnWidth(2,30);
    ui->keysDataWidget->horizontalHeader()->setHidden(true);
    ui->keysDataWidget->verticalHeader()->setHidden(true);
    ui->keysDataWidget->setShowGrid(false);
    ui->keysDataWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->keysDataWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->keysDataWidget->setFocusPolicy(Qt::NoFocus);
}

void MainWindow::InitLevelWidget()
{
    ui->levelDataWidget->addItem("序   章");
    ui->levelDataWidget->item(0)->setTextAlignment(Qt::AlignCenter);
    ui->levelDataWidget->item(0)->setSizeHint(QSize(50,50));
    ui->levelDataWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->levelDataWidget->setFocusPolicy(Qt::NoFocus);
}
void MainWindow::InitOptionsWidget()
{
    ui->optionsDataWidget->setRowCount(3);
    ui->optionsDataWidget->setColumnCount(3);
    ui->optionsDataWidget->setItem(1,1,new QTableWidgetItem("S 保存"));
    ui->optionsDataWidget->setItem(1,2,new QTableWidgetItem("Q 退出程序"));
    ui->optionsDataWidget->setItem(2,1,new QTableWidgetItem("A 读取"));
    ui->optionsDataWidget->setItem(2,2,new QTableWidgetItem("R 重新开始"));
    ui->optionsDataWidget->horizontalHeader()->setHidden(true);
    ui->optionsDataWidget->verticalHeader()->setHidden(true);
    ui->optionsDataWidget->setShowGrid(false);
    ui->optionsDataWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->optionsDataWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->optionsDataWidget->setFocusPolicy(Qt::NoFocus);
    ui->optionsDataWidget->setRowHeight(0,0);
    ui->optionsDataWidget->setRowHeight(1,40);
    ui->optionsDataWidget->setRowHeight(2,20);
    ui->optionsDataWidget->setColumnWidth(0,10);
    ui->optionsDataWidget->setColumnWidth(1,50);
    ui->optionsDataWidget->setColumnWidth(1,80);
    for(int i=1;i<3;i++)
        for(int j=0;j<2;j++)
            ui->playerDataWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);


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
    case Qt::Key_0:   //for test: 测试人物信息绑定是否成功，以及connect是否成功
        m_player->setLevel(m_player->getLevel()+1);
        m_player->setHealth(m_player->getHealth()+1);
        m_player->setAttack(m_player->getAttack()+1);
        m_player->setDefence(m_player->getDefence()+1);
        m_player->setGold(m_player->getGold()+1);
        m_player->setExp(m_player->getExp()+1);
        m_player->setLayer(m_player->getLayer()+1);
        m_player->setKeyCount(MagicTower::RED_KEY,m_player->getKeyCount(MagicTower::RED_KEY)+1);
        m_player->setKeyCount(MagicTower::BLUE_KEY,m_player->getKeyCount(MagicTower::BLUE_KEY)+1);
        m_player->setKeyCount(MagicTower::YELLOW_KEY,m_player->getKeyCount(MagicTower::YELLOW_KEY)+1);
        break;
    case Qt::Key_1:
        gainItem("得到金币数 1   经验值 1  !");
        break;
    case Qt::Key_2:
        success("得到金币数 1   经验值 1  !");
        break;
    default:
        break;
    }
}

void MainWindow::attachPlayerMoveCommand(std::function<void(MagicTower::Direction)> playerMoveCommand) {
    m_playerMoveCommand = playerMoveCommand;
}

MagicMap* MainWindow::getMapWidget() const {
    return ui->mapWidget;
}

void MainWindow::attachPlayer(const std::shared_ptr<Player> &player) {

    m_player = player;

    QObject::connect(m_player.get(),SIGNAL(levelChanged(int)),this,SLOT(updateLevel(int)));
    QObject::connect(m_player.get(),SIGNAL(healthChanged(int)),this,SLOT(updateHealth(int)));
    QObject::connect(m_player.get(),SIGNAL(attackChanged(int)),this,SLOT(updateAttack(int)));
    QObject::connect(m_player.get(),SIGNAL(defenceChanged(int)),this,SLOT(updateDefence(int)));
    QObject::connect(m_player.get(),SIGNAL(goldChanged(int)),this,SLOT(updateGold(int)));
    QObject::connect(m_player.get(),SIGNAL(expChanged(int)),this,SLOT(updateExp(int)));
    QObject::connect(m_player.get(),SIGNAL(layerChanged(int)),this,SLOT(updateLayer(int)));
    QObject::connect(m_player.get(),SIGNAL(keyCountChanged(MagicTower::KeyType, int)), this, SLOT(updateKeys(MagicTower::KeyType, int)));
}

void MainWindow::updateLevel(int newValue)
{
    QString spaces="   ",newLevel=QString::number(newValue);
    if(newValue/100)
       spaces=" ";
    else if(newValue/10)
        spaces="  ";
    QString text=newLevel+spaces+"级";
    ui->playerDataWidget->setItem(0,1,new QTableWidgetItem(text));
}

void MainWindow::updateHealth(int newValue)
{
    ui->playerDataWidget->setItem(1,1,new QTableWidgetItem(QString::number(newValue)));
    ui->playerDataWidget->item(1,1)->setTextAlignment(Qt::AlignCenter);
    QFont numFont;
    numFont.setItalic(true);
    ui->playerDataWidget->item(1,1)->setFont(numFont);
}

void MainWindow::updateAttack(int newValue)
{
    ui->playerDataWidget->setItem(2,1,new QTableWidgetItem(QString::number(newValue)));
    ui->playerDataWidget->item(2,1)->setTextAlignment(Qt::AlignCenter);
    QFont numFont;
    numFont.setItalic(true);
    ui->playerDataWidget->item(2,1)->setFont(numFont);
}

void MainWindow::updateDefence(int newValue)
{
    ui->playerDataWidget->setItem(3,1,new QTableWidgetItem(QString::number(newValue)));
    ui->playerDataWidget->item(3,1)->setTextAlignment(Qt::AlignCenter);
    QFont numFont;
    numFont.setItalic(true);
    ui->playerDataWidget->item(3,1)->setFont(numFont);
}

void MainWindow::updateGold(int newValue)
{
    ui->playerDataWidget->setItem(4,1,new QTableWidgetItem(QString::number(newValue)));
    ui->playerDataWidget->item(4,1)->setTextAlignment(Qt::AlignCenter);
    QFont numFont;
    numFont.setItalic(true);
    ui->playerDataWidget->item(4,1)->setFont(numFont);
}

void MainWindow::updateExp(int newValue)
{
    ui->playerDataWidget->setItem(5,1,new QTableWidgetItem(QString::number(newValue)));
    ui->playerDataWidget->item(5,1)->setTextAlignment(Qt::AlignCenter);
    QFont numFont;
    numFont.setItalic(true);
    ui->playerDataWidget->item(5,1)->setFont(numFont);
}

void MainWindow::updateLayer(int newValue)
{
    if(newValue==0)
    {
        QListWidgetItem *item = ui->levelDataWidget->takeItem(0);
        delete item;
        ui->levelDataWidget->addItem("序   章");
    }

    else
    {
        QListWidgetItem *item = ui->levelDataWidget->takeItem(0);
        delete item;
        QString newLayer=QString::number(newValue);
        QString text = "第 "+newLayer+" 层";
        ui->levelDataWidget->addItem(text);
    }
    ui->levelDataWidget->item(0)->setTextAlignment(Qt::AlignCenter);
    ui->levelDataWidget->item(0)->setSizeHint(QSize(50,50));
}

void MainWindow::updateKeys(MagicTower::KeyType keyType,int newValue)
{
    QFont numFont;
    numFont.setItalic(true);
    numFont.setPointSize(24);
    QString newKeyNum=QString::number(newValue);
    switch (keyType) {
    case MagicTower::RED_KEY:
            ui->keysDataWidget->setItem(0,1,new QTableWidgetItem(newKeyNum));
            ui->keysDataWidget->item(0,1)->setFont(numFont);
            break;
        case MagicTower::BLUE_KEY:
            ui->keysDataWidget->setItem(1,1,new QTableWidgetItem(newKeyNum));
            ui->keysDataWidget->item(1,1)->setFont(numFont);
            break;
        case MagicTower::YELLOW_KEY:
            ui->keysDataWidget->setItem(2,1,new QTableWidgetItem(newKeyNum));
            ui->keysDataWidget->item(2,1)->setFont(numFont);
        break;
    }
}

void MainWindow::startGame()
{
    ui->gameWidget->show();
}
void MainWindow::exitGame()
{
    this->close();
}
void MainWindow::gainItem(QString newValue)
{
    ui->gainLabel->setText(newValue);
    ui->gainLabel->show();
    QGraphicsOpacityEffect *gainLabelOpacity = new QGraphicsOpacityEffect(this);
    gainLabelOpacity->setOpacity(1);
    ui->gainLabel->setGraphicsEffect(gainLabelOpacity);
    QPropertyAnimation *ani = new QPropertyAnimation(gainLabelOpacity,"opacity");
    ani->setDuration(1000);
    ani->setStartValue(1);
    ani->setEndValue(0);
    ani->start();
}
void MainWindow::success(QString newValue)
{
    ui->gainLabel->setText(newValue);
    ui->gainLabel->show();
    ui->successLabel->show();

    QGraphicsOpacityEffect *successLabelOpacity = new QGraphicsOpacityEffect(this);
    successLabelOpacity->setOpacity(1);
    ui->successLabel->setGraphicsEffect(successLabelOpacity);
    QPropertyAnimation *ani1 = new QPropertyAnimation(successLabelOpacity,"opacity");
    ani1->setDuration(500);
    ani1->setStartValue(1);
    ani1->setEndValue(0);

    QGraphicsOpacityEffect *gainLabelOpacity = new QGraphicsOpacityEffect(this);
    gainLabelOpacity->setOpacity(0);
    ui->gainLabel->setGraphicsEffect(gainLabelOpacity);
    QPropertyAnimation *ani = new QPropertyAnimation(gainLabelOpacity,"opacity");
    ani->setDuration(500);
    ani->setStartValue(0);
    ani->setKeyValueAt(0.1,1);
    ani->setEndValue(0);

    QSequentialAnimationGroup *s_group=new QSequentialAnimationGroup(this);
    s_group->addAnimation(ani1);
    s_group->addAnimation(ani);
    s_group->start();
}
void MainWindow::openModal(QString value)
{
    qDebug()<<value;
    ui->intTextEdit->show();
    ui->intTextEdit->setText(value);
    ui->intTextEdit->setReadOnly(true);
}
