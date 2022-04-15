#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include "dop_task_1_functions.h"
#include "string"
#include "vector"

void dop_task_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    srand(clock());

    unsigned short n = in_count_people();// n = количество персонажей  

    vector < Characters > characters(n); // массив персонажей

    fill_vector(characters);
    print_max(n);
    print_table(characters);

    //команда или один человек
    char task = in_task();
    if (task == 'A')
    {
        cout << "Игра 1x1" << endl;
        unsigned short character_number = in_character_number(n);//получение номера противника
        Characters character_enemy = characters[character_number];//создание персонажа противника 
        print_dash();//печать разграничительной строки
        print_line(character_enemy);//печать свойств персонажа противника
        print_enter(1);//перенос каретки 
        characters.erase(characters.begin() + character_number);//удаление из массива персонажа противника
        print_table(characters);//печать таблицы с нашими перснонажами 

        string parametr = rang_my();//получение параметра 

        find_winner(characters, character_enemy);//нахождение списка победителей
        sort(characters, parametr);//сортировка списка
        print_table(characters);//печать списка
    }
    else
    {
        cout << "Игра 3х3" << endl;
        vector <Characters> enemy_team = in_team_enemy(characters);
        
        print_table(characters);

        
    }
    

    
}

