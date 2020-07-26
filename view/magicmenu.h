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

public slots:
    void startGame();

signals:
    void startButtonClicked();
};

#endif // MAGICMENU_H
