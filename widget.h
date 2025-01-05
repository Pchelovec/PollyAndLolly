#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "game.h"
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
    
private slots:
    void on_label_clicked();

private:
    Ui::Widget *ui;
    Game *game;

    void setSceneByNewTask(GameTask * gameTask);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // WIDGET_H
