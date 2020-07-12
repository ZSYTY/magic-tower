#ifndef APP_H
#define APP_H

#include "gamepart.h"
#include <QObject>
#include <QApplication>

class App : public QApplication
{
    Q_OBJECT
public:
    explicit App(int argc, char *argv[]);
    App(const App&) = delete;
    App& operator=(const App&) = delete;

    bool init();
    int run();

private:
    GamePart m_gamePart;

signals:

};

#endif // APP_H
