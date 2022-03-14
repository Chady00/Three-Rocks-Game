#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void enable_buttons();
    void disable_buttons();
    void myfunction();
    void blink();
    void clear_one_left();
    void clear_two_left();
    void clear_three_left();
    void check();
    void clear_one_right();
    void clear_two_right();
    void clear_three_right();


    void delay();
    void on_one_zero_clicked();

    void on_two_zero_clicked();

    void on_three_zero_clicked();

    void on_one_one_clicked();

    void on_two_one_clicked();
    void Engine_turn();

private:
    Ui::MainWindow *ui;
    //creating a new time slot
    QTimer * timer;
    QTimer *blinktimer;

private slots:
    void on_zero_one_clicked();
    void on_zero_two_clicked();
    void on_zero_three_clicked();
    void on_one_two_clicked();
    void on_pushButton_clicked();

};
#endif // MAINWINDOW_H
