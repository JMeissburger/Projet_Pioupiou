#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "controller.h"
#include <QProcess>
#include<QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow , Controller
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int get_Speed();
public slots:
    void set_Speed(int speed);
protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int m_speed;
    int m_timerId;
    QProcess *process;
};

#endif // MAINWINDOW_H
