#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "dop_task_1_functions.h"
#include "string"
#include "vector"
#include "Character.h"

//ввод количества людей
unsigned short input_count_people()
{
    
    short n = 10, n_max = 10;
    cout << "Введите количество человек, не менее 10 и не более 20: ";
    while (true)
    {
        n = input_value(rand() % n_max + 10);
        if (n >= 10&& n <= 20)
            break;
        else
            cout << "Количество человек не может быть < 10 и > 20, \nвведите другое число: ";
    }
    erase_past_output({0,0});
    cout << "Количество человек =" << setw(count_char(n_max)) << n << endl;
    return n;
}

//ранжирование
void rang(vector < Character >& characters)
{
    string parametr;
    char par = ' ';
    Point A = cursor_position();
    cout << "Ранжирование возможно по времени сражению (t) и по проценту оставшегося здоровья (%). \nВыберите вариант: ";
    while (true)
    {
        cin >> parametr;
        if (parametr == "t")
        {
            erase_past_output(A);
            cout << "Вы выбрали ранжирование по времени сражению" << endl;
            par = parametr[0];
            break;
        }
        if (parametr == "%")
        {            
            erase_past_output(A);
            cout << "Вы выбрали ранжирование по по проценту оставшегося здоровья" << endl;
            par = parametr[0];
            break;
        }
        else
            cout << "Такого параметра нет, введите другой параметр: ";
    }
    
    sort(characters, par);
}

//ввод номера задания
char input_task()
{
    string ch = "B";
    cout << "Введите букву варианта задания (А - 1x1, B - 3x3): ";

    while (true)
    {
        getline(cin, ch);
        if (ch == "A" || ch == "B")
            break;
        else cout << "Такого варианта нет, введите другую букву: ";
    }

    return ch[0];
}

//возвращает индекс или -1 если человека с таким номером нет в массиве
short find_vec(vector <Character> characters, unsigned short temp)
{
    short f = -1;
    for (int i = 0; i < characters.size(); i++)
    {
        if (characters[i].number == temp)
        {
            f = i;
            break;
        }
    }
    return f;
}

//рандомное получение номера персонажа 
unsigned short rand_input_number_enemy(vector <Character> characters)
{
    unsigned short n;
    boolean final;
    while (true)
    {
        final = 1;
        n = rand() % characters.size() + 1;
        for (int i = 0; i < characters.size(); i++)
        {
            if (characters[i].number == n)
            {
                final = 1;
                break;
            }
            else final = 0;
        }
        if (final == 1)
            break;
    }
    return n;
}

//ввод номеров персонажей команды противника
vector <Character> input_team_enemy(vector <Character>& characters, Point& A)
{
    CONSOLE_SCREEN_BUFFER_INFO bi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
    A = { bi.dwCursorPosition.X, bi.dwCursorPosition.Y };
    cout << "Введите номера персонажей из команды противника по одному. \n";
    string str, s;
    unsigned short a, i = 1;
    short in_vec;
    vector <Character> team;
    boolean final = 1;
    cout << "Введите номер " << i << " персонажа: ";
    while (true)
    {
        a = input_value(rand_input_number_enemy(characters));

        in_vec = find_vec(characters, a);
        if (in_vec != -1)
        {
            team.push_back(characters[in_vec]);
            characters.erase(characters.begin() + in_vec);
            if (team.size() == 3)
                break;
            cout << "Введите номер " << i + 1 << " персонажа: ";
            i++;
        }
        else
        {
            cout << "Персонажа с таким номером нет \nвведите другое число: ";
        }
    }
    return team;
}

//ввод номера персонажа
unsigned short input_character_number(unsigned short n)
{
    Point A = cursor_position();
    cout << "Выберите персонажа противника, напишите его номер: ";
    unsigned short character_number;
    
    while (true)
    {
        character_number = input_value(rand() % n + 1);
        if (character_number >= 0 && character_number <= n)
            break;
        else
            cout << "Такого номера нет, введите другое число: ";
    }
    erase_past_output(A);
    cout
        << "Номер персонажа =" << setw(count_char(n))
        << character_number << endl
        << "Его свойства: " << endl;

    character_number -= 1;
    return character_number;
}

//перенос строки
void print_enter(unsigned short n)
{
    for (int i = 0; i < n; i++)
        cout << endl;
}

//сортировка двух массивов
void sort(vector < Character >& characters_1, vector < Character >& characters_2, char parametr)
{
        switch (parametr)
        {
        case ('d'):
            for (int i = 0; i < characters_1.size(); i++)
            {
                for (int j = 0; j < characters_1.size(); j++)
                {
                    if (characters_1[i].damage > characters_1[j].damage)
                    {
                        swap(characters_1[j], characters_1[i]);
                        swap(characters_2[j], characters_2[i]);
                    }
                }
            }
            break;
        case ('h'):
            for (int i = 0; i < characters_1.size(); i++)
            {
                for (int j = 0; j < characters_1.size(); j++)
                {
                    if (characters_1[j].health < characters_1[i].health)
                    {
                        swap(characters_1[j], characters_1[i]);
                        swap(characters_2[j], characters_2[i]);
                    }
                }
            }
            break;
        
        }
}

//сортировка одного массива
void sort(vector < Character >& characters, char parametr)
{
    switch (parametr)
    {
    case ('t'):
        cout << "Ранжирование по времени: \n";
        for (int i = 0; i < characters.size(); i++)
        {
            for (int j = 0; j < characters.size(); j++)
            {
                if (characters[j].time_fight > characters[i].time_fight)
                    swap(characters[j], characters[i]);
            }
        }
        break;
    case ('%'):
        cout << "Ранжирование по проценту оставшегося здоровья: \n";
        for (int i = 0; i < characters.size(); i++)
        {
            for (int j = 0; j < characters.size(); j++)
            {
                if (characters[j].percent < characters[i].percent)
                    swap(characters[j], characters[i]);
            }
        }
        break;
    case ('#'):
        for (int i = 0; i < characters.size(); i++)
        {
            for (int j = 0; j < characters.size(); j++)
            {
                if (characters[j].number > characters[i].number)
                    swap(characters[j], characters[i]);
            }
        }
        break;
    case ('d'):
        for (int i = 0; i < characters.size(); i++)
        {
            for (int j = 0; j < characters.size(); j++)
            {
                if (characters[j].damage < characters[i].damage)
                    swap(characters[j], characters[i]);
            }
        }
        break;
    case ('h'):
        for (int i = 0; i < characters.size(); i++)
        {
            for (int j = 0; j < characters.size(); j++)
            {
                if (characters[j].health < characters[i].health)
                    swap(characters[j], characters[i]);
            }
        }
        break;
    }
}

//заполнение максимальных значений 
Character fill_max(unsigned short n)
{
    Character max_values;
    // rival_max = максимальное количество соперников
    // health_max = максимальное здоровье  
    // time_max 
    // interval_max
    // damage_max = макс. урон
    unsigned short rival_max, damage_max, health_max, time_max, interval_max;
    rival_max = 3;
    damage_max = 4 * ((n / 2) + (n / 5)) + rand() % n;
    health_max = (rand() % 2 + n * 8) * damage_max + rand() % n;
    time_max = health_max / n / 8;
    interval_max = time_max * 2;
    max_values.rival = rival_max;
    max_values.damage = damage_max;
    max_values.health = health_max;
    max_values.time = time_max;
    max_values.interval = interval_max;

    return max_values;
}

//заполнение массива персонажей
void fill_vector(vector < Character >& characters, Character max_values) 
{
    for (int i = 0; i < characters.size(); i++)
    {
        Character character;
        short temp;
        
        character.number = i + 1;
        character.damage = (rand() % (max_values.damage) + 1);
        character.rival = rand() % (max_values.rival) + 1;
        character.health =
            (((max_values.health - max_values.damage * 2) / //уменьшаем диапазон 
            max_values.damage) * (max_values.damage - character.damage)) + //умножнаем на разность макс урона и урона
            // тем самым получается, что чем больше урон тем меньше здоровье, и наоборот
            rand() % max_values.damage - 1 + max_values.damage * 2;
        temp = rand() % max_values.time - max_values.time / 4;
        if (temp <= 0)
        {
            character.time = 0;
            character.interval = 0;
        }
        else
        {
            character.time = temp;
            character.interval = character.time * 2 + rand() % max_values.time / 4;
        }

        characters[i] = character;
    }
}

//печать команды противника
void print_enemy_team(vector < Character > enemy_team, Point A)
{
    
    erase_past_output(A);
    cout << "Команда противника: " << endl;
    sort(enemy_team, '#');
    print_table(enemy_team);
} 

//печать тире
void print_dash()
{
    Character values;
    cout << '|';
    for (int j = 0; j < values.number_text; j++)
    {
        cout << '-';
    }

    cout << '|';
    for (int i = 0; i < values.damage_text; i++)
    {
        cout << '-';
    }
    
    cout << '|';
    for (int i = 0; i < values.rival_text; i++)
    {
        cout << '-';
    }

    cout << '|';
    for (int i = 0; i < values.health_text; i++)
    {
        cout << '-';
    }

    cout << '|';
    for (int i = 0; i < values.time_text; i++)
    {
        cout << '-';
    }
    
    cout << '|';
    for (int i = 0; i < values.interval_text; i++)
    {
        cout << '-';
    }

    cout << '|';
    for (int i = 0; i < values.time_fight_text; i++)
    {
        cout << '-';
    }

    cout << '|';
    for (int i = 0; i < values.percent_text; i++)
    {
        cout << '-';
    }
    cout << '|';
    cout << endl;
}

//печать максимальных значений 
void print_max(Character max_values)
{

    print_dash();

    cout
        << '|'
        << setw(max_values.number_text) << "max" << '|'
        << setw(max_values.damage_text) << max_values.damage << '|'
        << setw(max_values.rival_text) << max_values.rival << '|'
        << setw(max_values.health_text) << max_values.health << '|'
        << setw(max_values.time_text) << max_values.time << '|'
        << setw(max_values.interval_text) << max_values.interval << '|'
        << setw(max_values.time_fight_text) << ' ' << '|'
        << setw(max_values.percent_text) << ' ' << '|';
    print_enter(1);
}

//печать линии 
void print_line(Character character)
{
    cout
        << '|'
        << setw(character.number_text) << character.number << '|'
        << setw(character.damage_text) << character.damage << '|'
        << setw(character.rival_text) << character.rival << '|'
        << setw(character.health_text) << character.health << '|'
        << setw(character.time_text) << character.time << '|'
        << setw(character.interval_text) << character.interval << '|'
        << setw(character.time_fight_text) << character.time_fight << '|'
        << setw(character.percent_text) << fixed << setprecision(0) << character.percent * 100 << '|';

    print_enter(1);
    print_dash();
}

//печать заголовка
void print_title()
{
    Character character;
    print_dash();

    cout
        << '|' 
        << setw(character.number_text) << '#' << '|'
        << setw(character.damage_text) << "damage" << '|'
        << setw(character.rival_text) << "rival" << '|'
        << setw(character.health_text) << "health" << '|'
        << setw(character.time_text) << "time" << '|'
        << setw(character.interval_text) << "interval" << '|'
        << setw(character.time_fight_text) << "time fight(t)" << '|'
        << setw(character.percent_text) << "percent(%)" << '|'
        ;

    print_enter(1);
}

//печать массива персонажей
void print_table(vector < Character > characters)
{
    print_title();
    print_dash();

    for (int i = 0; i < characters.size(); i++)
    {
        print_line(characters[i]);
    }
    print_enter(1);
}

void print_all_teams(vector <vector < Character >>& teams)
{
    for (int i = 0; i < teams.size(); i++)
    {
        cout << "Команда с номером " << i << endl;
        print_table(teams[i]);
        cout << endl;
    }
}

//нахождение победителя при одиночном бое
void find_winner_solo(vector < Character >& characters, Character character_enemy)
{
    int time;
    Character character_enemy_fantom, character_fantom;
    for (int i = 0; i < characters.size(); i++)
    {
        time = 0;
        character_enemy_fantom = character_enemy, character_fantom = characters[i];

        while (
            character_fantom.health - character_enemy_fantom.damage > 0 &&
            character_enemy_fantom.health - character_fantom.damage > 0)
        {
            time++;

            if (characters[i].time > 0)
            {
                if (character_fantom.interval == character_fantom.time)
                {
                    character_fantom.time = characters[i].time;
                }
                if (character_fantom.time > 0)
                {
                    character_fantom.time--;
                    character_enemy_fantom.disable = 0;
                    character_enemy_fantom.damage = 0;
                    character_fantom.interval = characters[i].interval;
                }
                else
                {
                    character_enemy_fantom.disable = 1;
                    character_enemy_fantom.damage = character_enemy.damage;
                    character_fantom.interval--;
                }

            }
            if (character_enemy.time > 0)
            {
                if (character_enemy_fantom.interval == character_enemy_fantom.time)
                {
                    character_enemy_fantom.time = character_enemy.time;
                }
                if (character_enemy_fantom.time > 0)
                {
                    character_enemy_fantom.time--;
                    character_fantom.disable = 0;
                    character_fantom.damage = 0;
                    character_enemy_fantom.interval = character_enemy.interval;
                }
                else
                {
                    character_fantom.disable = 1;
                    character_fantom.damage = characters[i].damage;
                    character_enemy_fantom.interval--;
                }

            }
            cout << "time = " << setw(5) << time << endl;

            characters[i].time_fight = time;
            character_fantom.time_fight = time;
            character_fantom.health -= character_enemy_fantom.damage;
            character_enemy_fantom.health -= character_fantom.damage;
            print_line(character_fantom);
            print_line(character_enemy_fantom);
            cout << endl;

        }
        if (character_fantom.health - character_enemy_fantom.damage <= 0)
        {
            characters.erase(characters.begin() + i);
            i--;
        }
        else
        {
            characters[i].percent = character_fantom.health / characters[i].health;
            characters[i].health = character_fantom.health;
        }
    }
}

//нахождение массива комманд 
void find_array_team(int last, vector < Character >& team, vector <vector < Character >>& teams, vector < Character >& characters)
{
    if (team.size() == 3)
    {
        teams.push_back(team);
    }
    for (int index = last + 1; index <= characters.size(); index++)
    {
        team.push_back(characters[index - 1]);
        find_array_team(index, team, teams, characters);
        team.pop_back();
    }
}

//нахождение персонажа с максимальной силой
unsigned short find_max_in_vector(vector < Character > characters)
{
    unsigned short max_index = 0;
    for (int i = 0; i < characters.size(); i++)
    {
        if (characters[i].damage > max_index)
            max_index = i;
    }
    return max_index;
}

//проверка на все нули
bool all_equal_to_zero(vector < Character >& team, string parametr)
{
    short temp = 0;
    bool all = 1;
    if (parametr == "damage")
    {
        for (int k = 0; k < team.size(); k++)
        {
            if (team[k].damage != 0)
            {
                all = 0;
                break;
            }
            
        }
    }
    
    if (parametr == "health")
    {
        for (int k = 0; k < team.size(); k++)
        {
            if (team[k].health != 0)
            {
                all = 0;
                break;
            }
        }
    }
    return all;
}

//печатать или не печатать
bool print_or_not_print()
{
    int a;
    Point A = cursor_position();
    cout << "Введите 1, если печатать, и 0, если нет: ";
    while (true)
    {
        a = input_value(0);
        if (a == 0)
        {
            erase_past_output(A);
            cout << "Вы выбрали не печатать\n";
            return a;
        } 
        else if (a == 1)
        {
            erase_past_output(A);
            cout << "Вы выбрали печатать\n";
            return a;
        }
        else
            cout << "Вы ввели не 0 и не 1, введите 0 или 1: ";
    }
}

//нахождение комманд которые победили
void find_winner_team(vector <vector < Character >>& teams, vector < Character >& team_enemy)
{
    int time;
     
    //Team team_fantom, team_enemy_fantom;
    vector < Character >
        team_fantom,
        team_fantom_enemy;

    
    bool p_o_n_p = print_or_not_print();
    cout << "Какое количество комманд посмотреть: ";
    int count_teams = input_value(0);
    Point B = cursor_position();

    for (int i = 0; i < teams.size(); i++)
    {
        time = 0;
        team_fantom = teams[i];
        team_fantom_enemy = team_enemy;
        
        cout << "Команда с номером " << i << endl;
        Point A = cursor_position();
        while (true)
        {
            //getline(cin, input_command);
            if (p_o_n_p == 0 && i < count_teams)
            {
                if (time % 10 == 0)
                {
                    erase_past_output(A);
                    cout << "time =" << setw(5) << time << endl;

                    print_teams(team_fantom, team_fantom_enemy);
                    Sleep(500);
                }
            }
            time++;

            

            
            for (int j = 0; j < team_fantom.size(); j++) //перебираем всех в нашей команде
            {   
                if (all_equal_to_zero(team_fantom_enemy, "damage"))
                {
                    sort(team_enemy,team_fantom_enemy, 'd');
                }
                else
                {
                    sort(team_fantom_enemy, team_enemy, 'd');
                }

                if (teams[i][j].time > 0 && team_fantom[j].die == 0)
                {
                    if (team_fantom[j].interval == team_fantom[j].time)
                    {
                        team_fantom[j].time = teams[i][j].time;
                        team_fantom[j].disable = 1;
                    }
                    
                    if (team_fantom[j].time > 0 && 
                        team_fantom[j].disable == 1)
                    {
                        team_fantom[j].disable = 1;
                        for (int k = 0; k < team_fantom[j].rival; k++)
                        {
                            if (k == team_fantom_enemy.size())
                                break;
                            if (!team_fantom_enemy[k].die)
                                team_fantom_enemy[k].damage = 0;
                            //team_enemy_fantom[find_max_in_vector(team_enemy_fantom)].damage = 0;
                        }
                        team_fantom[j].interval = teams[i][j].interval;
                    }
                    if (team_fantom[j].disable == 1)
                    {
                        team_fantom[j].time--;
                    }
                    if (team_fantom[j].time == 0)
                    {
                        team_fantom[j].disable = 0;
                        for (int k = 0; k < team_fantom[j].rival; k++)
                        {
                            if (!team_fantom_enemy[k].die)
                                team_fantom_enemy[k].damage = team_enemy[k].damage;
                            if (k == team_fantom_enemy.size() - 1)
                                break;
                        }
                        team_fantom[j].interval--;
                    }
                }
                
                if (p_o_n_p == 1)
                {
                    cout << "наш " << j + 1 << endl;
                    print_table(team_fantom);
                    cout << "не наши" << endl;
                    print_table(team_fantom_enemy);
                }
                

                
            }
            if (p_o_n_p == 1)
                print_teams(team_fantom, team_fantom_enemy);

            for (int j = 0; j < team_fantom_enemy.size(); j++) //перебираем всех в нашей команде
            {
                if (all_equal_to_zero(team_fantom, "damage"))
                {
                    sort(teams[i], team_fantom, 'd');
                }
                else
                {
                    sort(team_fantom, teams[i], 'd');
                }

                if (team_enemy[j].time > 0 && team_fantom_enemy[j].die == 0)
                {
                    if (team_fantom_enemy[j].interval == team_fantom_enemy[j].time)
                    {
                        team_fantom_enemy[j].time = team_enemy[j].time;
                        team_fantom_enemy[j].disable = 1;
                    }

                    if (team_fantom_enemy[j].time > 0 &&
                        team_fantom_enemy[j].disable == 1)
                    {
                        team_fantom_enemy[j].disable = 1;
                        for (int k = 0; k < team_fantom_enemy[j].rival; k++)
                        {
                            if (k == team_fantom.size())
                                break;
                            if (!team_fantom[k].die)
                                team_fantom[k].damage = 0;
                        }
                        team_fantom_enemy[j].interval = team_enemy[j].interval;
                    }
                    if (team_fantom_enemy[j].disable == 1)
                    {
                        team_fantom_enemy[j].time--;
                    }
                    if (team_fantom_enemy[j].time == 0)
                    {
                        team_fantom_enemy[j].disable = 0;
                        for (int k = 0; k < team_fantom_enemy[j].rival; k++)
                        {

                            if (!team_fantom[k].die)
                                team_fantom[k].damage = teams[i][k].damage;
                            if (k == team_fantom.size() - 1)
                                break;
                        }
                        team_fantom_enemy[j].interval--;
                    }
                }
                
                if (p_o_n_p == 1)
                {
                    cout << "не наш " << j + 1 << endl;
                    print_table(team_fantom_enemy);
                    cout << "наши" << endl;
                    print_table(team_fantom);
                }
                
                
            }
            
            if (p_o_n_p == 1)
                print_teams(team_fantom, team_fantom_enemy);

            decrease_health( team_fantom, team_fantom_enemy, team_enemy);
            decrease_health( team_fantom_enemy, team_fantom, teams[i]);


            for (int j = 0; j < team_fantom.size(); j++)
            {
                if (!team_fantom[j].die)
                    team_fantom[j].time_fight = time;
            }

            if (p_o_n_p == 1)
                print_teams(team_fantom, team_fantom_enemy);
            
            if (all_equal_to_zero(team_fantom_enemy, "health") == 1 or all_equal_to_zero(team_fantom, "health") == 1)
            {
                break;
            }

        }
        if (all_equal_to_zero(team_fantom, "health"))
        {                        
            if (i < count_teams)
            {
                cout << "Победил противник :(" << endl;

                print_teams(team_fantom, team_fantom_enemy);
                Sleep(3000);
            }
            teams.erase(teams.begin() + i);
            
            erase_past_output(B);
        }
        else
        {     
            if (i < count_teams)
            {
                cout << "Победили мы ;)" << endl;
                print_teams(team_fantom, team_fantom_enemy);
                Sleep(3000);
            }                
            teams[i] = team_fantom;
            erase_past_output(B);

        }
    }
}

//уменьшение здоровья
void decrease_health(vector < Character >& team_1, vector < Character >& team_2, vector < Character > team_const)
{
    for (int j = 0; j < team_1.size(); j++) //перебираем всех в нашей команде
    {
        for (int k = 0; k < team_1[j].rival; k++) //отнимаем здоровье у противников
        {     
            if (team_2[k].health > 0)
            {
                team_2[k].health -= team_1[j].damage;
                team_2[k].percent = (team_2[k].health / team_const[k].health);
                if (team_2[k].health <= 0)
                {
                    die(team_2[k]);
                    k++;
                }
            }
        }
    }
}

//смерть
void die(Character& character)
{
    character.damage = -1;
    character.rival = 0;
    character.health = 0;
    character.time = 0;
    character.interval = 0;
    character.percent = 0;
    character.die = 1;
}

//печать комманд 
void print_teams(vector < Character >& team_fantom, vector < Character >& team_fantom_enemy)
{
    cout << "наши" << endl;
    print_table(team_fantom);
    cout << "не наши" << endl;
    print_table(team_fantom_enemy);
}