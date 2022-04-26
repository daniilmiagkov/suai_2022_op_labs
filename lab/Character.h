#pragma once
#include <Windows.h> // ����������

class Character
{
public:
    int health, time, interval;
    unsigned short
        number, damage, rival,
        time_fight = 0, disable = 1, die = 0;
    
    double percent = 1;
    
    
    // health = �������� ���������
    // time = ����� �� ������� �������� ��������� �� �����
    // interval = �������� ������ �� ����� 
    // damage = ���������� ���������� �� ����� ���������� � �������.
   
    byte number_text = 4,
         damage_text = 8,
         rival_text = 7,
         health_text = 8,
         time_text = 6,
         interval_text = 10,
         time_fight_text = 14,
         percent_text = 11;
};


