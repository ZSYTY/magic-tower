#ifndef MAGICMENU_H
#define MAGICMENU_H

#include <QWidget>

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
    void mainLabelGraph();

public slots:
    void startGame();
    void exitGame();

signals:
    void startButtonClicked();
    void exitButtonClicked();
};

#endif // MAGICMENU_H
