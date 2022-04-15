#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "dop_task_1_functions.h"
#include "string"
#include "vector"

using namespace std;

string bufer = "";

struct max_values
{    
public:
    // rival_max = максимальное количество соперников
    // health_max = максимальное здоровье 
    // health = здоровье персонажа
    // time = время на которое соперник выводится из строя
    // time_max 
    // interval = интервал вывода из строя 
    // interval_max
    // damage = количество наносимого им урона противнику в секунду.
    // damage_max = макс. урон
    unsigned short const rival_max = 3;
    unsigned short damage_max;
    unsigned short health_max;
    unsigned short time_max;
    unsigned short interval_max;
    void values(unsigned short n)
    {
        damage_max = 4 * ((n / 2) + (n / 5)) + rand() % n;
        health_max = (rand() % 2 + n * 8) * damage_max + rand() % n;
        time_max = health_max / n / 8;
        interval_max = time_max * 2;
    }

    byte array_of_sizes[3] = { 4,11,7 };
};

unsigned short in_count_people()
{
    short n, n_max = 30;
    cout << "Введите количество человек, не менее 10: ";
    bufer += "Введите количество человек, не менее 10: ";
    while (true)
    {
        n = input_value(rand() % n_max + 10);
        if (n > 0)
            break;
        else
            cout << "Количество человек не может быть <= 0, \nвведите положительное число: ";
            bufer += "Количество человек не может быть <= 0, \nвведите положительное число: ";
    }
    
    cout << "Количество человек =" << setw(count_char(n_max)) << n << endl;
    //cin.ignore(1, '\n');
    return n;
}

string rang_my()
{
    string parametr;
    cout << "Ранжирование возможно по времени сражению (t) и по проценту оставшегося здоровья (%). \nВыберите вариант: ";
    while (true)
    {
        cin >> parametr;
        if (parametr == "t" || parametr == "%")
            break;
        else
            cout << "Такого параметра нет, введите другой параметр: ";
    }
    return parametr;
}



char in_task()
{
    string ch;        
    cout << "Введите букву варианта задания (А - 1x1, B - 3x3): ";

    while (true)
    {
        getline(cin, ch);
        if (ch == "A" || ch == "B")
            break;
        else cout << "Такого варианта нет, введите другую букву: ";
    }
    
    //cin.ignore(1,'\n');

    return ch[0];
}

short find_vec(vector <Characters> characters, unsigned short temp)
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

unsigned short number_enemy_input(vector <Characters> characters)
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

vector <Characters> in_team_enemy(vector <Characters> &characters)
{
    cout << "Введите номера персонажей из команды противника по одному. \n";
    string str, s;
    unsigned short a, i = 1;
    short in_vec;
    vector <Characters> team;
    boolean final = 1;
    cout << "Введите номер " << i << " персонажа: ";
    while (true)
    {
        
        
        a = input_value(number_enemy_input(characters));

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

unsigned short in_character_number(unsigned short n)
{
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

    cout
        << "Номер персонажа =" << setw(count_char(n))
        << character_number << endl
        << "Его свойства: " << endl;

    character_number -= 1;
    return character_number;
}

unsigned short count_char(unsigned short a)
{
    unsigned short count = 0;
    while (a > 0)
    {
        count++;
        a /= 10;
    }
    return count + 1;
}

void print_enter(unsigned short n)
{
    for (int i = 0; i < n; i++)
        cout << endl;
}

void sort(vector < Characters >& characters, string parametr)
{
    if (parametr == "t")
    {
        for (int i = 0; i < characters.size(); i++)
        {
            for (int j = 0; j < characters.size(); j++)
            {
                if (characters[j].time_fight > characters[i].time_fight)
                    swap_notstd(characters[j], characters[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < characters.size(); i++)
        {
            for (int j = 0; j < characters.size(); j++)
            {
                if (characters[j].percent < characters[i].percent)
                    swap_notstd(characters[j], characters[i]);
            }
        }
    }
}

void fill_vector(vector < Characters >& characters)
{
    max_values values;
    values.values(characters.size());
    for (int i = 0; i < characters.size(); i++)
    {
        Characters character;
        short temp;
        
        character.number = i + 1;
        character.damage = (rand() % (values.damage_max / 2)) * 2 + 2;
        character.rival = rand() % (values.rival_max) + 1;
        character.health =
            (((values.health_max - values.damage_max * 2) / //уменьшаем диапазон 
            values.damage_max) * (values.damage_max - character.damage)) + //умножнаем на разность макс урона и урона
            // тем самым получается, что чем больше урон тем меньше здоровье, и наоборот
            rand() % values.damage_max - 1 + values.damage_max * 2;
        temp = rand() % values.time_max - values.time_max / 4;
        if (temp <= 0)
        {
            character.time = 0;
            character.interval = 0;
        }
        else
        {
            character.time = temp;
            character.interval = character.time * 2 + rand() % values.time_max / 4;
        }

        characters[i] = character;
    }
}

void print_enemy_team(vector < Characters > enemy_team)
{
    cout << "Команда противника: \n";
    print_table(enemy_team);
}

void print_dash()
{
    max_values values;
    cout << '|';
    for (int j = 0; j < values.array_of_sizes[0]; j++)
    {
        cout << '-';
    }

    for (int j = 0; j < values.array_of_sizes[2]; j++)
    {
        cout << '|';
        for (int i = 0; i < values.array_of_sizes[1]; i++)
        {
            cout << '-';
        }
    }
    cout << '|';
    cout << endl;
}

void print_max(unsigned short n)
{

    print_dash();
    max_values values;
    values.values(n);
    cout
        << '|' << setw(values.array_of_sizes[0]) << "max" << '|'
        << setw(values.array_of_sizes[1]) << values.damage_max << '|'
        << setw(values.array_of_sizes[1]) << values.rival_max << '|'
        << setw(values.array_of_sizes[1]) << values.health_max << '|'
        << setw(values.array_of_sizes[1]) << values.time_max << '|'
        << setw(values.array_of_sizes[1]) << values.interval_max << '|'
        << setw(values.array_of_sizes[1] + 1) << '|'
        << setw(values.array_of_sizes[1] + 1) << '|';
    print_enter(1);
}

void print_line(Characters character)
{
    max_values values;

    cout
        << '|' << setw(values.array_of_sizes[0]) << character.number << '|'
        << setw(values.array_of_sizes[1]) << character.damage << '|'
        << setw(values.array_of_sizes[1]) << character.rival << '|'
        << setw(values.array_of_sizes[1]) << character.health << '|'
        << setw(values.array_of_sizes[1]) << character.time << '|'
        << setw(values.array_of_sizes[1]) << character.interval << '|'
        << setw(values.array_of_sizes[1]) << character.time_fight << '|'
        << setw(values.array_of_sizes[1]) << fixed << setprecision(4) << character.percent << '|';

    print_enter(1);
    print_dash();
}

void print_table(vector < Characters > characters)
{
    max_values values;
    print_dash();

    cout
        << '|' << setw(values.array_of_sizes[0]) << '#' << '|'
        << setw(values.array_of_sizes[1]) << "damage" << '|'
        << setw(values.array_of_sizes[1]) << "rival" << '|'
        << setw(values.array_of_sizes[1]) << "health" << '|'
        << setw(values.array_of_sizes[1]) << "time" << '|'
        << setw(values.array_of_sizes[1]) << "interval" << '|'
        << setw(values.array_of_sizes[1]) << "time fight" << '|'
        << setw(values.array_of_sizes[1]) << "percent" << '|'
        ;

    print_enter(1);
    print_dash();

    for (int i = 0; i < characters.size(); i++)
    {
        print_line(characters[i]);
    }
    print_enter(1);
}

void find_winner(vector < Characters >& P, Characters character_enemy)
{
    int time;
    Characters character_enemy_fantom, character_fantom;
    for (int i = 0; i < P.size(); i++)
    {
        time = 0;
        character_enemy_fantom = character_enemy, character_fantom = P[i];

        while (
            character_fantom.health - character_enemy_fantom.damage > 0 &&
            character_enemy_fantom.health - character_fantom.damage > 0)
        {
            time++;

            if (P[i].time > 0)
            {
                if (character_fantom.interval == character_fantom.time)
                {
                    character_fantom.time = P[i].time;
                }
                if (character_fantom.time > 0)
                {
                    character_fantom.time--;
                    character_enemy_fantom.in_ranks = 0;
                    character_enemy_fantom.damage = 0;
                    character_fantom.interval = P[i].interval;
                }
                else
                {
                    character_enemy_fantom.in_ranks = 1;
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
                    character_fantom.in_ranks = 0;
                    character_fantom.damage = 0;
                    character_enemy_fantom.interval = character_enemy.interval;
                }
                else
                {
                    character_fantom.in_ranks = 1;
                    character_fantom.damage = P[i].damage;
                    character_enemy_fantom.interval--;
                }

            }
            //cout << "time = " << setw(5) << time << endl;

            P[i].time_fight = time;
            character_fantom.time_fight = time;
            //P[i].health -= character_enemy_fantom.damage;
            character_fantom.health -= character_enemy_fantom.damage;
            character_enemy_fantom.health -= character_fantom.damage;
            //print_line(character_fantom);
            //print_line(character_enemy_fantom);
            //cout << endl;

        }
        if (character_fantom.health - character_enemy_fantom.damage <= 0)
        {

            P.erase(P.begin() + i);
            i--;
        }
        else
        {
            P[i].percent = static_cast<double>(character_fantom.health) / P[i].health;
            P[i].health = character_fantom.health;
        }
    }
}