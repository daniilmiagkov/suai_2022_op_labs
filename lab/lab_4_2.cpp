#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "lab_4_2_functions.h"
#include "main_header.h"
#include "string"
#include "vector"
#include <set>
#include <iterator>

using namespace std; //подключение пространства имен std

void lab_4_2()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    srand(clock());

    // N = количество претендетов 
    // lS = количество навыков у претендента
    // lS_max = максимальное количество навыков
    // M_max = общее максимальное количество неповторяющихся навыков
    // Z_max = бюджет

    bool debugging = 1;

    unsigned short N = input_count_people();
    unsigned short lS_max = in_count_ckills();

    unsigned short Z_max = N * (lS_max * 10)  + rand() % 10;

    vector < pair < set <int>, int> > P(N);
    set <set<int>> sets_indexes;
    vector < pair < int, int> > skills_and_salaries;
    vector <int> indexes = {};

    fill_pair(P, N, lS_max, Z_max);
    unsigned short l_void = sqrt(N) + 1;
    cout << "Бюджет = " << setw(l_void) << Z_max << endl;
    print_three_vector(P, lS_max);

    
    int count = 0;
    int time_start = clock();
    repetitions(count, 0, indexes, skills_and_salaries, P);
    int time_end = clock();

    if (debugging == 1)
        print_vector_pair(skills_and_salaries);
    
    cout << endl
         << "кол-во сумм: " << skills_and_salaries.size() << endl
         << "максимально возможная сумма навыков" << skills_and_salaries[find(skills_and_salaries, Z_max)].first
         << setw(5) << skills_and_salaries[find(skills_and_salaries, Z_max)].second;
}
