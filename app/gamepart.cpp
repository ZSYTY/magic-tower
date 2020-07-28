#include "gamepart.h"

GamePart::GamePart(QObject *parent) : QObject(parent)
{
    m_gameViewModel.attachModel(std::shared_ptr<GameModel>(&m_gameModel));
    m_mainWindow.attachPlayerMoveCommand(m_gameViewModel.getPlayerMoveCommand());
    m_mainWindow.getMapWidget()->attachPlayer(m_gameViewModel.getPlayer());
    m_mainWindow.attachPlayer(m_gameViewModel.getPlayer());
    m_mainWindow.getMapWidget()->attachGameMap(m_gameViewModel.getGameMap());
    m_mainWindow.attachPlayerChooseCommand(m_gameViewModel.getPlayerChooseCommand());
    m_mainWindow.attachLoadCommand(m_gameViewModel.getLoadCommand());
    m_mainWindow.attachRestartCommand(m_gameViewModel.getRestartCommand());
    m_mainWindow.attachSaveCommand(m_gameViewModel.getSaveCommand());
    m_mainWindow.attachUseBookCommand(m_gameViewModel.getUseBookCommand());

    connect(&m_gameModel,SIGNAL(playerWin(QString)),&m_mainWindow,SLOT(success(QString)));
    connect(&m_gameModel,SIGNAL(itemGet(QString)),&m_mainWindow,SLOT(gainItem(QString)));
    connect(&m_gameModel,SIGNAL(openModal(QString)),&m_mainWindow,SLOT(openModal(QString)));
    connect(&m_gameModel,SIGNAL(closeModal()),&m_mainWindow,SLOT(closeModal()));

    connect(&m_gameModel,SIGNAL(levelChanged(int)),&m_mainWindow,SLOT(updateLevel(int)));
    connect(&m_gameModel,SIGNAL(healthChanged(int)),&m_mainWindow,SLOT(updateHealth(int)));
    connect(&m_gameModel,SIGNAL(attackChanged(int)),&m_mainWindow,SLOT(updateAttack(int)));
    connect(&m_gameModel,SIGNAL(defenceChanged(int)),&m_mainWindow,SLOT(updateDefence(int)));
    connect(&m_gameModel,SIGNAL(goldChanged(int)),&m_mainWindow,SLOT(updateGold(int)));
    connect(&m_gameModel,SIGNAL(expChanged(int)),&m_mainWindow,SLOT(updateExp(int)));
    connect(&m_gameModel,SIGNAL(layerChanged(int)),&m_mainWindow,SLOT(updateLayer(int)));
    connect(&m_gameModel,SIGNAL(keyCountChanged(MagicTower::KeyType, int)), &m_mainWindow, SLOT(updateKeys(MagicTower::KeyType, int)));

    /* Why to call static_cast here, see: https://asmaloney.com/2015/05/code/qsignalmapper-example-revisited/ */
    connect(&m_gameModel, &GameModel::positionChanged, m_mainWindow.getMapWidget(), static_cast<void (MagicMap::*)()>(&MagicMap::update), Qt::QueuedConnection);
    connect(&m_gameModel, &GameModel::directionChanged, m_mainWindow.getMapWidget(), static_cast<void (MagicMap::*)()>(&MagicMap::update), Qt::QueuedConnection);

    connect(&m_gameModel, &GameModel::mapDataChanged, m_mainWindow.getMapWidget(), static_cast<void (MagicMap::*)()>(&MagicMap::update), Qt::QueuedConnection);

    connect(&m_gameModel,SIGNAL(openBook(const QVector<monster>&)),m_mainWindow.getMapWidget(),SLOT(openBook(const QVector<monster>&)));
    connect(&m_gameModel,SIGNAL(closeBook()),m_mainWindow.getMapWidget(),SLOT(closeBook()));
}

MainWindow& GamePart::getMainWindow()
{
    return m_mainWindow;
}
