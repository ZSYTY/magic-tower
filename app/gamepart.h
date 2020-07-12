#ifndef GAMEPART_H
#define GAMEPART_H

#include "view/mainwindow.h"
#include "model/gamemodel.h"
#include "viewModel/gameviewmodel.h"
#include <QObject>

class GamePart : public QObject
{
    Q_OBJECT
public:
    explicit GamePart(QObject *parent = nullptr);
    GamePart(const GamePart&) = delete;
    GamePart& operator=(const GamePart&) = delete;

public:
    MainWindow& getMainWindow();

private:
    MainWindow      m_mainWindow;
    GameModel       m_gameModel;
    GameViewModel   m_gameViewModel;

signals:

};

#endif // GAMEPART_H
