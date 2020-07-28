#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "magicmap.h"
#include "magicmenu.h"
#include "common/player.h"
#include "common/item.h"
#include "view/magicmenu.h"
#include "memory"
#include <QMediaPlayer>

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
    void attachPlayerChooseCommand(std::function<void(int)> playerChooseCommand);
    void attachSaveCommand(std::function<void()> saveCommand);
    void attachLoadCommand(std::function<void()> loadCommand);
    void attachRestartCommand(std::function<void()> restartCommand);
    void attachUseBookCommand(std::function<void()> useBookCommand);
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
    std::function<void(int)> m_playerChooseCommand;
    std::function<void()> m_saveCommand;
    std::function<void()> m_loadCommand;
    std::function<void()> m_restartCommand;
    std::function<void()> m_useBookCommand;
    std::shared_ptr<Player> m_player;
    QMediaPlayer *stepBgm;
    QMediaPlayer *beatBgm;
    QMediaPlayer *gainBgm;
    QMediaPlayer *mapBgm;

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
    void exitGame();
    void gainItem(QString);
    void success(QString);
    void openModal(QString);
    void closeModal();
};
#endif // MAINWINDOW_H
