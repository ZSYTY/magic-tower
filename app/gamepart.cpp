#include "gamepart.h"

GamePart::GamePart(QObject *parent) : QObject(parent)
{
    m_gameViewModel.attachModel(std::shared_ptr<GameModel>(&m_gameModel));
    m_mainWindow.attachPlayerMoveCommand(m_gameViewModel.getPlayerMoveCommand());
    // m_mainWindow.attachPlayerChooseCommand(m_gameViewModel.getPlayerChooseCommand());
    m_mainWindow.getMapWidget()->attachPlayer(m_gameViewModel.getPlayer());
    m_mainWindow.attachPlayer(m_gameViewModel.getPlayer());
    m_mainWindow.getMapWidget()->attachGameMap(m_gameViewModel.getGameMap());
    /* TODO */
//    connect(&m_gameModel, &GameModel::openModal, &m_mainWindow, /* TODO */);
//    connect(&m_gameModel, &GameModel::closeModal, &m_mainWindow, /* TODO */);
//    connect(&m_gameModel, &GameModel::playerWin, &m_mainWindow, /* TODO */);
//    connect(&m_gameModel, &GameModel::itemGet, &m_mainWindow, /* TODO */);

}

MainWindow& GamePart::getMainWindow() {
    return m_mainWindow;
}
