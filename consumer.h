#ifndef CONSUMER_H
#define CONSUMER_H
#include <QThread>

class Consumer: public QThread
{
public:
    Consumer();
    void run();
};

#endif // CONSUMER_H
