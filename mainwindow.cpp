 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <mythreads.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m1 = new MyThreads(this); //m1-ს ენიჭება mythread-ის ახალი ობიექტი
    m1->stop=false;
    m1->sleepTime=300;//ნაკადის ძილის პერიოდი
    m2 = new MyThreads(this);
    m2->stop=false;
    m2->sleepTime=150;

    connect(m1,SIGNAL(numChanged(int)),this,SLOT(onNumChanged(int))); //m1ის numChanged სიგნალისა და ამ კლასის onNumChanged სლოტის დაკავშირება
    connect(m1,SIGNAL(numChanged(int)),ui->progressBar,SLOT(setValue(int))); //m1ის numChanged სიგნალისა და პროგრესბარის დაკავშრება

    connect(m2,SIGNAL(numChanged(int)),this,SLOT(onNumChanged(int)));
    connect(m2,SIGNAL(numChanged(int)),ui->progressBar_2,SLOT(setValue(int)));
  //  qApp->processEvents();


    setWindowTitle("ნაკადები");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   m1->stop=false;
    m1->start(); //ნაკადის დაწყება
    m1->wait(3); //დალოდება
}

void MainWindow::on_pushButton_2_clicked()
{
    m1->stop=true; //ნაკადის გაჩერება
}
void MainWindow::onNumChanged(int k){
    ui->label->setText(QString::number(k)); //ტექსტის დაყენება labelზე

}

void MainWindow::on_pushButton_3_clicked()
{
    m2->stop=false;
    m2->start();
    m2->wait(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    m1->stop=true;
}
