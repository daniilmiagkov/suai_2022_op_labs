#pragma once
#include "string"
#include "vector"
#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека

using namespace std;

class Characters
{
public:

    unsigned short
        number, damage, rival,
        time_fight = 0, in_ranks = 1;
    int health, time, interval;
    double percent = 1;
};

char in_task(); 

vector <Characters> in_team_enemy(vector <Characters>& characters);

unsigned short number_enemy_input(vector <Characters> characters);

short find_vec(vector <Characters> characters, unsigned short temp);

string rang_my();

unsigned short in_count_people();

unsigned short in_character_number(unsigned short n);

unsigned short count_char(unsigned short a);

void print_enter(unsigned short n);

void sort(vector < Characters > &characters, string parametr);

void fill_vector(vector < Characters > &characters);

void print_dash();

void print_max(unsigned short n);

void print_line(Characters character);

void print_table(vector < Characters > characters);

void find_winner(vector < Characters > &P, Characters character_enemy);