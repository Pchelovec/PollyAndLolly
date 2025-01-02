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

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    Game *game;
};

#endif // WIDGET_H
