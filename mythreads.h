#ifndef MYTHREADS_H
#define MYTHREADS_H

#include <QThread>
#include <mythreads.h>
class MyThreads : public QThread
{
    Q_OBJECT
public:
    explicit MyThreads(QObject *parent = 0);
    bool stop; //გამჩერებელის ბულეან ცვლადი
    void run(); //გადასატვირთი run() ფუნქცია
    int sleepTime; //ძილის პერიოდი

    
signals:
    void numChanged(int); //რიცხვის შეცვლის სიგნალი

public slots:

};

#endif // MYTHREADS_H
