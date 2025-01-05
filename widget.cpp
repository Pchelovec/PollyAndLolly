#include "widget.h"
#include "ui_widget.h"
#include "gametask.h"
#include <QDebug>
#include <QPainter>
#include<QMovie>
#include"level.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    game=new Game();
    ui->stackedWidget->setCurrentIndex(0);
    qDebug()<<"Welcome to Polly And Lolly Lyric Story!";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::drawScene0(QPaintEvent *pe)
{
    GameTask *gameTask =new GameTask(Level::prolog,Prolog_scene::Prolog_StartMenuScreen);
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

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"Mouse pressed";

    if (game->isLastSceneInLevel()){
        ui->stackedWidget->setCurrentIndex(0);
    }
    else{
        game->lastPainted->sceneImg++;
        GameTask *gameTask =new GameTask(game->lastPainted->level,game->lastPainted->sceneImg);
        gameTask->screenSize=QSize(width(),height());

        setSceneByNewTask(gameTask);
    }
    game->changed=true;
    QWidget::update();
}

void Widget::setDeveloperImages()
{
    QMovie *movie = new QMovie(":/developer/photo/img/developer/3ball_shower_man.gif");
    ui->scene_img_label->setMovie(movie);
    ui->scene_img_label->setScaledContents(true);
    ui->scene_img_label->setToolTip("Developer photo(colorized)");
    movie->start();
}

void Widget::on_label_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    setDeveloperImages();

    game->changed=true;
    QWidget::update();
}

void Widget::setSceneByNewTask(GameTask *gameTask)
{
    GameTask *task=gameTask;
    if (task==NULL){
        task=new GameTask(Level::prolog,Prolog_scene::Prolog_StartMenuScreen);
    }
    gameTask->screenSize=QSize(ui->scene_img_label->width(),ui->scene_img_label->height());
    State *s=game->drawMeScene(task);
    game->lastPainted=s;
    ui->scene_img_label->setPixmap(s->img);
    ui->scene_text_label->setText(s->gameText);
}
