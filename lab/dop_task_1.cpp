#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include "dop_task_1_functions.h"
#include "string"
#include "vector"
#include "Character.h"
#include "Team.h"

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

void dop_task_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    srand(clock());
    pair <int, int> x_y;//пара координатов курсора

    
    unsigned short n = input_count_people();// n = количество персонажей  
    

    vector < Character > characters(n); // массив персонажей

    Character max_values = fill_max(n);
    fill_vector(characters, max_values);
    print_max(max_values);
    print_table(characters);

    //команда или один человек
    x_y = cursor_position();
    char task = input_task();
    
    if (task == 'A')
    {
        erase_past_output(x_y);
        cout << "Игра 1x1" << endl;
        
        unsigned short character_number = input_character_number(n);//получение номера противника
        Character character_enemy = characters[character_number];//создание персонажа противника 
        print_title();
        print_dash();//печать разграничительной строки
        print_line(character_enemy);//печать свойств персонажа противника
        print_enter(1);//перенос каретки 
        characters.erase(characters.begin() + character_number);//удаление из массива персонажа противника
        cout << "\nПерсонажи с которыми он будет биться: \n";
        print_table(characters);//печать таблицы с нашими перснонажами 
        find_winner_solo(characters, character_enemy);//нахождение списка победителей
        
        rang(characters);//сортировка списка
        print_table(characters);//печать списка
    }
    else
    {
        erase_past_output(x_y);
        cout << "Игра 3х3" << endl;
        
        vector <Character> enemy_team = input_team_enemy(characters, x_y);
        
        print_enemy_team(enemy_team, x_y);
        print_table(characters);
        vector <Character> team;
        vector <vector < Character >> teams;
        combinations(0, team, teams, characters);
        //print_teams(teams);
        find_winner_team(teams, enemy_team);
        
    }
    

    
}

