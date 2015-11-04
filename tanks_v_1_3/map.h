#ifndef MAP_H
#define MAP_H

#include "header.h"
#include "QString"
#include "stdio.h"

struct Cell         //���� ������ ����
{
    int x;          //���������� �
    int y;          //���������� �
    QString pic;    //�����������
    CellType type;  //���
};

class Map
{
    public:
        Map(QString _path) {path = _path;}
        ~Map();
        int create();                                               //�������� �����
        Cell* posXY(int _x, int _y);                                //��������� ������ �� �� �����������
        Cell* get_cell(int _i, int _j) {return mapa[_i][_j];}       //������� ������ � ���������
        bool is_road(int _x, int _y);                               //����� �� �������� �� ���� ������ (��� �����)
        bool is_shot(int _x, int _y);                               //����� �� ����������� ������ (��� �������)
        bool is_wc(int _x, int _y);                                 //����� �� ������� (��� �����)
    protected:
        FILE *fmapa;                                                //���� � ��������� �����
        Cell *mapa[MAXROW][MAXCOL];                                 //������ ��������, ������������ �����
        QString path;                                               //���� � �����
};

#endif // MAP_H
