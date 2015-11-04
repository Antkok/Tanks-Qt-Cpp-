#ifndef GAMEPLAYING_H
#define GAMEPLAYING_H

#include "header.h"
#include "QString"

class gamePlaying
{
    public:
        gamePlaying(int _tanks_count, bool _alive);
        ~gamePlaying();
        void dec_tanks() {tanks_count--;} //��������� ����� ������
        QString map(int _i) {return lev[_i];} //������� �����
        bool win() {return tanks_count == 1 && alive;} //������
        bool lose() {return alive == false;} //���������
        void dead() {alive = false;} //����� ���������
    private:
        int tanks_count; //����� ������
        bool alive; //��� �� �����
        QString lev[8]; //������
};

#endif // GAMEPLAYING_H
