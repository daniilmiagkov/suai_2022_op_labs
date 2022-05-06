#pragma once
#include "string"
#include "vector"
#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "Character.h"
#include "Team.h"

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::setw;
using std::make_pair;
using std::endl;
using std::fixed;
using std::setprecision;

char input_task();

Character fill_max(unsigned short n);

vector <Character> input_team_enemy(vector <Character>& characters, pair <int, int>& x_y);

unsigned short input_number_enemy(vector <Character> characters);

short find_vec(vector <Character> characters, unsigned short temp);

void erase_past_output(pair <int, int> x_y);

void print_title();

void rang(vector < Character >& characters);

unsigned short input_count_people();

pair <int, int> cursor_position();

unsigned short input_character_number(unsigned short n);

void print_enter(unsigned short n);

void sort(vector < Character >& characters_1, vector < Character >& characters_2, char parametr);

void sort(vector < Character >& characters_1, char parametr);

void fill_vector(vector < Character >& characters, Character max_values);

void print_dash();

void print_max(Character max_values);

void print_line(Character character);

void set_cursor_position(int x, int y);

void print_enemy_team(vector < Character > enemy_team, pair <int, int> x_y);

void print_table(vector < Character > characters);

void combinations(int last, vector < Character >& team, vector <vector < Character >>& teams, vector < Character >& characters);

void print_all_teams(vector <vector < Character >>& teams);

void find_winner_team(vector <vector < Character >>& teams, vector < Character >& enemy_team);

unsigned short find_max_in_vector(vector < Character > characters);

void decrease_health(vector < Character >& team_fantom, vector < Character >& team_fantom_enemy, vector < Character >& team_intermediate, vector < Character >& team_const);

void print_teams(vector < Character >& team_fantom, vector < Character >& team_enemy_fantom);

bool Print_or_not_print();

void die(Character& character);

void find_winner_solo(vector < Character > &characters, Character character_enemy);