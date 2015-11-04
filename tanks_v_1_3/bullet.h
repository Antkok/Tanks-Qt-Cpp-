#ifndef BULLET_H
#define BULLET_H

#include "header.h"
#include "QObject"
#include "QTimer"
#include "map.h"
#include "tank.h"
#include "QGraphicsPixmapItem"

class Tank;

class Bullet: public QObject
{
    Q_OBJECT
    public:
        Bullet(int _x, int _y, int _arrow, Side _army);
        Bullet(const Bullet &_b);
        ~Bullet();
        bool operator==(const Bullet &_obj);
        void move(); //�������� �������
        bool popal(Map *_m, QList<Tank*> _T, QList<Bullet*> _B); //������������ ������� � ������������ (�����, ����)
        int X() {return x;}
        int Y() {return y;}
        int id() {return ID;}
        QString IMG() {return img;}
    protected:
        void central(); //�������� ���������� ������� ������������ ����� (����� �� ������� �� ����, � �� �� �����)
        int x; //��� �
        int y; //��� �
        int speed; //��������
        int arrow; //������
        Side army; //�������, ������� ����������� ����, ����������� ������
        QString img; //�����������
        int ID; //
    signals:
        void popal_stena(Cell *_pos); //������ ����� � �����
        void popal_tank(Tank *_t); //������ ����� � ����
};

class BulletTimer: public QObject  //������ ��� ��������� �������� �������
{
    Q_OBJECT
    public:
        BulletTimer(Bullet *_b, QGraphicsPixmapItem *_p);
        ~BulletTimer();
        void start(); //����
        void stop();  //����
    protected:
        QTimer *t;    //���������� ������
        Bullet *b;  //��������������� ����
        QGraphicsPixmapItem *p;//� �� ��������
        //<--- ��� ��������� �� �������, ������� ���������� �������� �������� � ����
    signals:
        void takt(Bullet *_b, QGraphicsPixmapItem *_p, BulletTimer *_tmr); //���������� ������
    protected slots:
        void on_takt() {emit takt(b, p, this);} //��� ����, ������� ������ ���� ������� �������� ������ takt
};

#endif // BULLET_H
