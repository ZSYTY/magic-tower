#include "gamepart.h"

GamePart::GamePart(QObject *parent) : QObject(parent)
{
    m_gameViewModel.attachModel(std::shared_ptr<GameModel>(&m_gameModel));
    m_mainWindow.attachPlayerMoveCommand(m_gameViewModel.getPlayerMoveCommand());
    m_mainWindow.getMapWidget()->attachPlayer(m_gameViewModel.getPlayer());
    m_mainWindow.attachPlayer(m_gameViewModel.getPlayer());
    m_mainWindow.getMapWidget()->attachGameMap(m_gameViewModel.getGameMap());
    /* TODO */

    connect(&m_gameModel,SIGNAL(playerWin(QString)),&m_mainWindow,SLOT(success(QString)));
    connect(&m_gameModel,SIGNAL(itemGet(QString)),&m_mainWindow,SLOT(gainItem(QString)));
    connect(&m_gameModel,SIGNAL(openModal(QString)),&m_mainWindow,SLOT(openModal(QString)));
}

MainWindow& GamePart::getMainWindow() {
    return m_mainWindow;
}
