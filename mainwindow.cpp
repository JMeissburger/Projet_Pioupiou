#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_speed = 0;
    process = new QProcess(this);
    connect (process, SIGNAL(readyReadStandardOutput()), this, SLOT(on_pushButton_clicked()));
    connect (process, SIGNAL(readyReadStandardError()), this, SLOT(on_pushButton_clicked()));
    m_timerId = startTimer(100);
    ui->label_2->setPixmap(Controller::PrintSpeedBackground());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timerId)
        Controller::set_Speed(get_Speed());
        ui->label_2->setPixmap(Controller::PrintSpeedBackground());
}

int MainWindow::get_Speed()
{
    return m_speed;
}

void MainWindow::set_Speed(int speed)
{
    m_speed=speed;
}

void MainWindow::on_pushButton_clicked()
{
     QString out,out2;
     bool ok=false;
    process->start("python3 ../TestQlabelQpainter/compteur.py");
    out = process->readAllStandardOutput();
    out2 = process->readAllStandardError();
    set_Speed(out.toInt(&ok,10));
    qDebug()<<out <<out.toInt(&ok,10);


}
