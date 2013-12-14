#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mythreads.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    MyThreads *m1; //ობიექტზე მიმთითებლების შექმნა
    MyThreads *m2;
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked(); //ბატონების ღილაკების სლოტები

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

public slots:
    void onNumChanged(int); //რიცხვის შეცვლის დაჭერის სლოტი
};

#endif // MAINWINDOW_H
