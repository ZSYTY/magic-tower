#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "magicmap.h"
#include "memory"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    std::shared_ptr<QVector<int>> getPtrToPlayerData();
    std::shared_ptr<QVector<int>> getPtrToKeysData();
    std::shared_ptr<int> getPtrToLevelData();

private:
    Ui::MainWindow *ui;
    void InitPlayerWidget();
    void InitKeysWidget();
    void InitLevelWidget();
    void InitOptionsWidget();

    std::shared_ptr<QVector<int>> ptrToPlayerData;
    std::shared_ptr<QVector<int>> ptrToKeysData;
    std::shared_ptr<int> ptrToLevelData;
};
#endif // MAINWINDOW_H
