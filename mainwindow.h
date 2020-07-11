#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "magicmap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void InitPlayerWidget();
    void InitKeysWidget();
    void InitLevelWidget();
    void InitOptionsWidget();
};
#endif // MAINWINDOW_H
