#ifndef GAMETASK_H
#define GAMETASK_H

#include <QObject>

class GameTask : public QObject
{
    Q_OBJECT
public:
    explicit GameTask(QObject *parent = nullptr);

signals:

public slots:
};

#endif // GAMETASK_H