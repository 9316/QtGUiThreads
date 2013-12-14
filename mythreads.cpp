#include "mythreads.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
MyThreads::MyThreads(QObject *parent) :
    QThread(parent)
{
   sleepTime=200; //ძირითადი ძილის დრო თუ არაფერი არ იქნა გადმოცემული
}
void MyThreads::run(){ //run-ის იმპლემენტაცია
    for(int i=1; i<=100; i++){
        if(this->stop) break;

        emit numChanged(i); //სიგნალის გამოძახება ყოველი ციკლისას
        this->msleep(sleepTime); //ძილის პერიოდის დაყენება
    }
}
