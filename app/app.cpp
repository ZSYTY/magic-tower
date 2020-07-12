#include "app.h"

App::App(int argc, char *argv[]) : QApplication(argc, argv)
{

}

bool App::init() {
    /* TODO */
    return true;
}

int App::run() {
    m_gamePart.getMainWindow().show();
    return exec();
}
