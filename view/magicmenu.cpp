#include "magicmenu.h"
#include "ui_magicmenu.h"
#include <QDebug>
#include <QFile>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QMediaPlaylist>

MagicMenu::MagicMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MagicMenu)
{
    ui->setupUi(this);

    QPixmap mainLabelPix(":/assets/Images/mainLabel.png");
    ui->mainLabel->setPixmap(mainLabelPix);
    ui->aboutWidget->hide();
    ui->aboutTextEdit->setReadOnly(true);

    QMediaPlaylist *bgmList=new QMediaPlaylist();
    bgmList->addMedia(QUrl("qrc:/assets/Sounds/streaming.wav"));
    menuBgm=new QMediaPlayer();
    bgmList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    menuBgm->setPlaylist(bgmList);
    menuBgm->play();

    mainLabelGraph();


    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(ui->aboutButton,SIGNAL(clicked()),this,SLOT(openAbout()));
    connect(ui->exitButton,SIGNAL(clicked()),this,SLOT(exitGame()));
    connect(ui->aboutBackButton,SIGNAL(clicked()),this,SLOT(closeAbout()));
}

MagicMenu::~MagicMenu()
{
    delete ui;
}

void MagicMenu::startGame()
{
    this->hide();
    menuBgm->stop();
    emit startButtonClicked();
}
void MagicMenu::exitGame()
{
    emit exitButtonClicked();
}
void MagicMenu::mainLabelGraph()
{
    QSequentialAnimationGroup *s_group=new QSequentialAnimationGroup(this);
    QParallelAnimationGroup *p_group=new QParallelAnimationGroup(this);

    QGraphicsOpacityEffect *mainLabelOpacity = new QGraphicsOpacityEffect(this);
    mainLabelOpacity->setOpacity(1);
    ui->mainLabel->setGraphicsEffect(mainLabelOpacity);
    QPropertyAnimation *ani = new QPropertyAnimation(mainLabelOpacity,"opacity");
    ani->setDuration(3000);
    ani->setStartValue(1);
    ani->setEndValue(0);


    QGraphicsOpacityEffect *cnLabelOpacity = new QGraphicsOpacityEffect(this);
    cnLabelOpacity->setOpacity(0);
    ui->cnLabel->setGraphicsEffect(cnLabelOpacity);
    QPropertyAnimation *aniCn = new QPropertyAnimation(cnLabelOpacity,"opacity");
    aniCn->setDuration(1000);
    aniCn->setStartValue(0);
    aniCn->setEndValue(1);

    QGraphicsOpacityEffect *enLabelOpacity = new QGraphicsOpacityEffect(this);
    enLabelOpacity->setOpacity(0);
    ui->enLabel->setGraphicsEffect(enLabelOpacity);
    QPropertyAnimation *aniEn = new QPropertyAnimation(enLabelOpacity,"opacity");
    aniEn->setDuration(1000);
    aniEn->setStartValue(0);
    aniEn->setEndValue(1);

    QGraphicsOpacityEffect *buttonLabelOpacity = new QGraphicsOpacityEffect(this);
    buttonLabelOpacity->setOpacity(0);
    ui->startButton->setGraphicsEffect(buttonLabelOpacity);
    QPropertyAnimation *aniBtn = new QPropertyAnimation(buttonLabelOpacity,"opacity");
    aniBtn->setDuration(1000);
    aniBtn->setStartValue(0);
    aniBtn->setEndValue(1);

    QGraphicsOpacityEffect *aboutbuttonLabelOpacity = new QGraphicsOpacityEffect(this);
    aboutbuttonLabelOpacity->setOpacity(0);
    ui->aboutButton->setGraphicsEffect(aboutbuttonLabelOpacity);
    QPropertyAnimation *aniBtn1 = new QPropertyAnimation(aboutbuttonLabelOpacity,"opacity");
    aniBtn1->setDuration(1000);
    aniBtn1->setStartValue(0);
    aniBtn1->setEndValue(1);

    QGraphicsOpacityEffect *exitbuttonLabelOpacity = new QGraphicsOpacityEffect(this);
    exitbuttonLabelOpacity->setOpacity(0);
    ui->exitButton->setGraphicsEffect(exitbuttonLabelOpacity);
    QPropertyAnimation *aniBtn2 = new QPropertyAnimation(exitbuttonLabelOpacity,"opacity");
    aniBtn2->setDuration(1000);
    aniBtn2->setStartValue(0);
    aniBtn2->setEndValue(1);

    p_group->addAnimation(aniBtn);
    p_group->addAnimation(aniBtn1);
    p_group->addAnimation(aniBtn2);


    s_group->addAnimation(ani);
    s_group->addAnimation(aniCn);
    s_group->addAnimation(aniEn);
    s_group->addAnimation(p_group);
    s_group->start();
}
void MagicMenu::openAbout()
{
    menuBgm->pause();
    QMediaPlaylist *bgmList=new QMediaPlaylist();
    bgmList->addMedia(QUrl("qrc:/assets/Sounds/about.wav"));
    aboutBgm=new QMediaPlayer();
    bgmList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    aboutBgm->setPlaylist(bgmList);
    aboutBgm->play();
    ui->menuWidget->hide();
    ui->aboutWidget->show();
}
void MagicMenu::closeAbout()
{
    aboutBgm->stop();
    menuBgm->play();
    ui->aboutWidget->hide();
    ui->menuWidget->show();
}
