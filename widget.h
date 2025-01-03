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

private slots:
    void on_pushButton_clicked();

    void on_label_clicked();

private:
    Ui::Widget *ui;
    Game *game;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // WIDGET_H
