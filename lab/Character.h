#pragma once
#include <Windows.h> // библиотека

class Character
{
public:
    int  time, interval, damage;
    unsigned short
        number, rival,
        time_fight = 0, disable = 1, die = 0;
    
    double health, percent = 1;
    
    
    // health = здоровье персонажа
    // time = время на которое соперник выводится из строя
    // interval = интервал вывода из строя 
    // damage = количество наносимого им урона противнику в секунду.
   
    byte number_text = 4,
         damage_text = 8,
         rival_text = 7,
         health_text = 8,
         time_text = 6,
         interval_text = 10,
         time_fight_text = 14,
         percent_text = 11;
};


