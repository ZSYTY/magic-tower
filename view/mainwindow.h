#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "magicmap.h"
#include "magicmenu.h"
#include "common/player.h"
#include "view/magicmenu.h"
#include "memory"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void attachPlayerMoveCommand(std::function<void(MagicTower::Direction)> playerMoveCommand);
    void attachPlayer(const std::shared_ptr<Player>& player);
    void keyPressEvent(QKeyEvent *event) override;
    MagicMap* getMapWidget() const;


private:
    Ui::MainWindow *ui;
    void InitPlayerWidget();
    void InitKeysWidget();
    void InitLevelWidget();
    void InitOptionsWidget();
    std::function<void(MagicTower::Direction)> m_playerMoveCommand;
    std::shared_ptr<Player> m_player;

public slots:
    void updateLevel(int);  //人物等级
    void updateHealth(int);
    void updateAttack(int);
    void updateDefence(int);
    void updateGold(int);
    void updateExp(int);
    void updateLayer(int);  //楼层
    void updateKeys(MagicTower::KeyType,int);
    void startGame();
};
#endif // MAINWINDOW_H
