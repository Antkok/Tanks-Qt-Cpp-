#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QMainWindow>
#include "QDialog"
#include "QGraphicsScene"
#include "QGraphicsPixmapItem"
#include "header.h"
#include "map.h"
#include "tank.h"
#include "gamePlaying.h"
#include "score.h"
#include "bonus.h"
#include "bomber.h"

namespace Ui {
class Mediator;
}

class Mediator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Mediator(QWidget *parent, int _level, int _mode, int _side);
    ~Mediator();
    
private:
    virtual void keyPressEvent(QKeyEvent *e); //���������� ������� ������� �������
    virtual void mousePressEvent(QMouseEvent *e); //���������� ������� ������� ����
    void create_new_game();
    void delete_game();
    void renew();
    void pause();
    void respawn_bonus();                                       //���������� �������
    void set_game_settings(int _mode, int _side);
    QGraphicsPixmapItem* add_texture(QString _texture, int _size_x, int _size_y, int _pos_x, int _pos_y);
    Ui::Mediator *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *p[MAXROW][MAXCOL];
    QGraphicsPixmapItem *tank[20];
    QGraphicsPixmapItem *b; //�����
    QGraphicsPixmapItem *pl;
    Bonus *bon;
    Map *m;
    QTimer *driver;     //������, ����������� �������
    QTimer *resp;       //������, ����������� �����
    QTimer *pilot;
    gamePlaying *Game;
    QList<Tank*> T;     // �������
    QList<Bullet*> B;   //������
    Bomber *air;       //��������������
    int num_tanks;      //����� ������
    int created_tanks;  //����� ������, �������������� �� ���� ���
    int wave;           //����� ������ (4 �����)
    int level;          //�����
    int mode;           //������� ���������
    bool stopped; //��������� ����

    int arm;      //����� ��������� ������
    int lvs;      //���������� ������
    int lvs_curr; //������� ���������� ������
    int airstrike; //����� ����������
    Side gamer_side;
    Side ai_side;

    Score *rec;
    bool paused;    //�����
signals:
    void win();
    void lose();
protected slots:
    void on_shot(Bullet *_b);                                   //��������� �������� �����
    void on_tick(Bullet*,QGraphicsPixmapItem*,BulletTimer*);    //��������� ������ ����
    void on_popal_stena(Cell*);                                 //��������� ��������� ���� � �����
    void on_popal_tank(Tank*);                                  //��������� ��������� ���� � ����
    void drive_tanks();                                         //��������� �������� ������-�����������
    void on_win();                                              //������
    void on_lose();                                             //���������
    void on_tank_kill(Tank *_t);                                //��������� ����������� �����
    void on_found_bonus(Bonus *_b);                             //������ �����
    void respawn();                                             //���������� ������
    void bomber_fly();                                          //����������� ���������������
    void on_bombing(Bomb *_b);                                  //��������
private slots:
    void on_pushButton_clicked();
};

#endif // MEDIATOR_H
