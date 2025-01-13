#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "game.h"
#include "Admob/QmlBanner.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void drawScene0(QPaintEvent *event);

    void setDeveloperImages();
    
    void loadAds();
    
    
    GameTask * gameTaskForNextScene();

private slots:
    void on_label_prolog_clicked();

    void on_pushButton_clicked();

    void on_label_walk_clicked();

private:
    Ui::Widget *ui;
    Game *game;
    QmlBanner *banner;

    void setSceneByNewTask(GameTask * gameTask);
    void updateGameProgressUI();

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // WIDGET_H
