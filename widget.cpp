#include "widget.h"
#include "ui_widget.h"
#include "gametask.h"
#include <QDebug>
#include <QPainter>
#include<QMovie>
#include"level.h"
#include<QScreen>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    game=new Game();
    ui->stackedWidget->setCurrentIndex(0);
    updateGameProgressUI();
    loadAds();
    qDebug()<<"Welcome to Polly And Lolly Lyric Story!";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::loadAds()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    banner=new QmlBanner();
    banner->setUnitId("ca-app-pub-3940256099942544/6300978111");
    banner->setBannerSize(QmlBanner::LARGE_BANNER);
    banner->setX(40);
    banner->setY((height/4)*3);
    banner->setTestDeviceId("41E647017EBEBB0650DAE627391B7A43");
    banner->loadBanner();
    banner->setVisible(true);
}
void Widget::drawScene0(QPaintEvent *pe)
{
    GameTask *gameTask =new GameTask(Level::PROLOG,Prolog_scene::Prolog_StartMenuScreen);
    gameTask->screenSize=QSize(width(),height());

    QPainter paint(this);
    QPixmap pixmap = game->drawMeScene(gameTask)->img;
    paint.drawPixmap(0, 0, pixmap);
    QWidget::paintEvent(pe);
}

void Widget::paintEvent(QPaintEvent *event)
{
    if (game->changed){
        qDebug()<<"Widget paint for changed screen!";
        drawScene0(event);
    }
    game->changed=false;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    game->changed=true;
    QWidget::update();
}

GameTask * Widget::gameTaskForNextScene()
{
    game->lastPainted->incrementScene();
    GameTask *gameTask =new GameTask(game->lastPainted->level,game->lastPainted->screen);
    gameTask->screenSize=QSize(width(),height());

    return gameTask;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"Mouse pressed";

    if (ui->stackedWidget->currentIndex()==1){
        if (game->isLastSceneInLevel()){
            ui->stackedWidget->setCurrentIndex(0);
            banner->setVisible(true);
            game->saveProgress();
        }
        else{
            //todo update incrementation by new mitod like 'next'
            GameTask *gameTask = gameTaskForNextScene();
            setSceneByNewTask(gameTask);
        }
    }
    game->changed=true;
    QWidget::update();
}

void Widget::setDeveloperImages()
{
    QMovie *movie = new QMovie(":/img/developer/3ball_shower_man.gif");
    ui->scene_img_label->setMovie(movie);
    ui->scene_img_label->setScaledContents(true);
    ui->scene_img_label->setToolTip("Developer photo(colorized)");
    movie->start();
}

void Widget::setSceneByNewTask(GameTask *gameTask)
{
    GameTask *task=gameTask;
    if (task==NULL){
        task=new GameTask(Level::PROLOG,Prolog_scene::Prolog_StartMenuScreen);
    }
    gameTask->screenSize=QSize(ui->scene_img_label->width(),ui->scene_img_label->height());
    Scene *s=game->drawMeScene(task);
    game->lastPainted=s;
    ui->scene_img_label->setPixmap(s->img);
    ui->scene_text_label->setText(s->gameText);
}

void Widget::on_label_prolog_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    banner->setVisible(false);

    setDeveloperImages();

    game->changed=true;
    QWidget::update();
}

void Widget::updateGameProgressUI()
{
    ui->label_prolog->setText("Пролог");
    ui->label_walk->setText("Прогулка");
    ui->label_road->setText("Поход");
    ui->label_journey->setText("Путешествие");
    if (Progress::progressExist()){
        //load from file
        game->loadProgress();
        switch (game->lastPainted->level) {
            case(Level::VOYAGE):{ui->label_journey->setText("Путешествие🗸");}
            case(Level::ZOO):{ui->label_road->setText("Поход🗸");}
            case(Level::TEA_WALK):{ui->label_walk->setText("Прогулка🗸");}
            case(Level::PROLOG):{ui->label_prolog->setText("Пролог🗸");}
        }
    }
}

