#include "gamepart.h"

GamePart::GamePart(QObject *parent) : QObject(parent)
{
    m_gameViewModel.attachModel(std::shared_ptr<GameModel>(&m_gameModel));
    /* TODO */
}

MainWindow& GamePart::getMainWindow() {
    return m_mainWindow;
}
