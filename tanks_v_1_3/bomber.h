#ifndef BOMBER_H
#define BOMBER_H

#include "header.h"
#include "QString"
#include "map.h"
#include "tank.h"
#include "QObject"

class Tank;
class Bomb;

struct Point
{
    int x;
    int y;
};

class Bomber: public QObject
{
    Q_OBJECT
    public:
        Bomber(int _x, int _y, Side _army, int _btar);
        ~Bomber();
        void control();
        QString IMG() {return pic;}
        int X() {return x;}
        int Y() {return y;}
    private:
        void domove() {y+=speed;} //�������� � ����� �����
        void fire();              //�����
        int x;
        int y;
        int btar;                 //�����-��������� �� ����
        int speed;                //��������
        bool empty;               //������� ����� ��� ���
        Point rad[9]; //������ ���������
        Side army;
        QString pic;
        QString s;    //�������� �������������
    signals:
        void bomba(Bomb *_b);
};

class Bomb: public QObject
{
    Q_OBJECT
    public:
        Bomb(int _x, int _y);
        ~Bomb();
        QString IMG() {return img;}
        int X() {return x;}
        int Y() {return y;}
        void popal(Map *_m, QList<Tank*> _T);
    private:
        int x;
        int y;
        QString img;
    signals:
        void popal_stena(Cell *_pos); //������ ����� � �����
        void popal_tank(Tank *_t); //������ ����� � ����
};

#endif // BOMBER_H
