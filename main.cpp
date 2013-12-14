#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; //MainWindow კლასის ობიექტი
    w.show(); // ფანრჯის გამოჩენა
    
    return a.exec(); //შესრულებული სამუშაოს შედეგი
}
