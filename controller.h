#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QPainter>
#define NB_POINT 13

class Controller
{
public:
    Controller();
    int get_Speed(){return m_speed;}
    QPixmap PrintSpeedBackground();
public slots:
    void set_Speed(int speed){m_speed = speed;}
private:
    int m_speed;
};

#endif // CONTROLLER_H
