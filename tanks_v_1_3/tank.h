#ifndef TANK_H
#define TANK_H

#include "header.h"
#include "QObject"
#include "QKeyEvent"
#include "map.h"
#include "bullet.h"
#include "bonus.h"

class Bullet;

class Tank: public QObject                  //����, ���� ��� �����������
{
    Q_OBJECT
    public:
        Tank();
        Tank(const Tank &_tank);
        ~Tank();
        bool operator==(const Tank &obj);
        void move();                                           //�������� �����
        void fire();                                           //��������
        void set_speed(CellType _cell);                        //������ �������� ��������, � ����������� �� �����������
        bool can_move(Map *_m, QList<Tank*> _T);                     //���������, ����� �� ��������
        bool pluh(Map *_m);                                    //���� ������
        bool boundary(int _x, int _y);                         //���������� �������, ���������� ������
        bool is_kill() {return armour<=0;}                     //���������, ��������� �� ����
        void set_dammage(int _dammage);                        //�����������
        void found_bonus(Bonus *_b);                           //����� �����
        void set_lives(int _lives) {lives += _lives;}          //������ ����� ������
        void repair() {armour = 100;}                          //��������������� ����
        void set_pos(int _x, int _y) {pos_x = _x; pos_y = _y;} //����������� ����
        int X() {return pos_x;}                                //�������� ���������� �
        int Y() {return pos_y;}                                //�������� ���������� �
        int nearestX();                                        //�������� ���������� � ����� ������
        int nearestY();                                        //�������� ���������� � ����� ������
        QString IMG() {return img;}                            //���������� ���� �� ������� ����
        int get_speed() {return speed;}                        //������ ��������
        int get_arrow() {return arrow;}                        //������ �����������
        int get_armour() {return armour;}                      //������ �����
        int get_ammo() {return ammo;}                          //������ ���������� �����������
        int get_order() {return order;}                        //������ ���������� �����
        int get_lives() {return lives;}                        //������ ����� ������
        Side get_army() {return army;}                         //������ �������
        virtual void control(QKeyEvent *e, Map *_m, QList<Tank*> _T, Bonus *_b) = 0; //���������� ������ (����� � ��������� ��������� �� ��-�������)
    protected:
        int speed;      //��������
        int pos_x;      //���������� x
        int pos_y;      //���������� �
        int arrow;      //�����������
        int armour;     //�����
        int ammo;       //����������
        int order;      //���������� ����� ����� �� �����
        int reload;     //�����������
        int lives;      //�����
        Side army;      //�������
        QString img;    //����������� �����
        QString s1;     //����� ���������
    signals:
        void shot(Bullet *_b);       //���� ���������
        void kill(Tank *_t);         //���� ����������
        void found(Bonus *_b);       //���� ����� �����
};

class AITank: public Tank           //��� �������� ����, ����������� �����������
{
    public:
        AITank(int _pos_x, int _pos_y, int _arrow, int _armour, int _ammo, int _lives, int _order, Side _army);
        AITank(const AITank& _tank);
        ~AITank();
        void control(QKeyEvent *e, Map *_m, QList<Tank*> _T, Bonus *_b); //�� ��� ��������� ������ (���. ������ 2 ���������, ������� � ��������
            //������ �� ���������� ����� ������� NULL)
    protected:
        bool seek(Tank *_t); //����� ����
        bool is_water(Map *_m) {return _m->is_wc(nearestX(),nearestY());} //������ �����������
        void domove(Map *_m, QList<Tank*> _T, Bonus *_b); //��������� � ������� ��������� ����
        int compas[4]; //��������� ����������� �������� �����
        int stamina;    //����������, ������� ������� ����
        bool combatRed;  //������� ���� - ������� ����� �� ���������
        bool combatBlue; //��� ���� � ���� ������ - �� ��������
};

class PlayerTank: public Tank       //��� �������� ����, ����������� ���������
{
    public:
        PlayerTank(int _pos_x, int _pos_y, int _arrow, int _armour, int _ammo, int _lives,  int _order, Side _army);
        PlayerTank(const PlayerTank& _tank);
        ~PlayerTank();
        void control(QKeyEvent *e, Map *_m, QList<Tank*> _T, Bonus *_b); //���������� ������ �������������� ��� ������ ������
};

class Artillery: public AITank        //��������������� �������, ����������� �����������
{
    public:
        Artillery(int _pos_x, int _pos_y, int _arrow, int _armour, int _ammo, int _lives, int _order, Side _army);
        ~Artillery();
};

#endif // TANK_H
