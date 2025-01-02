#ifndef STATE_H
#define STATE_H

#include <QObject>

class State : public QObject
{
    Q_OBJECT
public:
    explicit State(QObject *parent = nullptr);

signals:

public slots:
};

#endif // STATE_H