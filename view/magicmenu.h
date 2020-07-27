#ifndef MAGICMENU_H
#define MAGICMENU_H

#include <QWidget>
#include <QMediaPlayer>

namespace Ui {
class MagicMenu;
}

class MagicMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MagicMenu(QWidget *parent = nullptr);
    ~MagicMenu();

private:
    Ui::MagicMenu *ui;
    QMediaPlayer *menuBgm;
    QMediaPlayer *aboutBgm;
    void mainLabelGraph();

public slots:
    void startGame();
    void exitGame();
    void openAbout();
    void closeAbout();

signals:
    void startButtonClicked();
    void exitButtonClicked();
};

#endif // MAGICMENU_H
