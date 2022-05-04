#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "lab_4_2_functions.h"
#include "string"
#include "vector"
#include "Skills_and_salaries.h"
#include <set>
#include <iterator>

using namespace std; //подключение пространства имен std

int find_time(unsigned int size, bool print)
{
    
    int start_time, end_time;

    srand(clock());

    // N = количество претендетов 
    // lS = количество навыков у претендента
    // lS_max = максимальное количество навыков
    // M_max = общее максимальное количество неповторяющихся навыков
    // Z_max = бюджет

    bool debugging = 1;

    //unsigned short N = input_count_people();
    unsigned short N = size;
    //unsigned short lS_max = in_count_ckills();
    unsigned short lS_max = 30;

    unsigned short Z_max = N * (lS_max * 8) + rand() % 10;

    vector < pair < set <int>, int> > P(N);
    set <set<int>> sets_indexes;
    vector < Skills_and_salaries > skills_and_salaries;
    vector <int> indexes = {};

    fill_pair(P, N, lS_max, Z_max);
    unsigned short l_void = sqrt(N) + 1;

    if (print == 1)
    {
        cout << "Бюджет = " << setw(l_void) << Z_max << endl;
        print_three_vector(P, lS_max);
    }


    int count = 0;
    int time_start = clock();
    combinations(count, 0, indexes, skills_and_salaries, P);
    int time_end = clock();
    //cout << count;
    if (print == 1)
        print_vector_pair(skills_and_salaries, P.size());

    find(skills_and_salaries, Z_max);

    if (print == 1)
    {
        cout << endl << "Ответ:" << endl;
        print_vector_pair(skills_and_salaries, P.size());
    }

    return time_end - time_start;
}

void find(vector < Skills_and_salaries >& skills_and_salaries, int Z_max)
{
    int salary_max = 0;
    int skills_max = 0;
    vector < Skills_and_salaries > array;
    for (int i = 0; i < skills_and_salaries.size(); i++)
    {
        if (skills_and_salaries[i].sum_skills > skills_max && skills_and_salaries[i].sum_salaries < Z_max)
        {
            skills_max = skills_and_salaries[i].sum_skills;
        }
    }
    for (int i = 0; i < skills_and_salaries.size(); i++)
    {
        if (skills_and_salaries[i].sum_skills == skills_max)
        {
            array.push_back(skills_and_salaries[i]);
        }
    }
    skills_and_salaries = array;
}

int in_count_ckills()
{
    cout << "Введите максимальное количество навыков у человека: ";
    unsigned short lS_max = input_value(rand() % 8 + 4);
    cout << "Максимальное количество навыков у человека: " << lS_max << endl;
    return lS_max;
}

int input_count_people()
{
    cout << "Введите количество человек: ";
    unsigned short N = input_value(rand() % 8 + 4);
    cout << "Количество человек: " << N << endl;
    return N;
}

void fill_pair(vector < pair < set <int>, int> > & P, unsigned short N, unsigned short lS_max, unsigned short Z_max)
{
    unsigned short lS, M_max = lS_max + 2;

    for (int i = 0; i < N; i++)
    {
        lS = rand() % (lS_max) + 1;
        set <int> S;
        for (int j = 0; j != lS; j++)
        {
            S.insert(rand() % M_max + 1);
        }

        P[i] = make_pair(S, ((Z_max - 10) / (M_max)) * lS + rand() % 10);
    }
}

void print_dash(int count)
{
    cout << '|';
    for (int j = 0; j < 2; j++)
    {
        cout << '-';
    }
    cout << '|';
    for (int j = 0; j <= 4 * (count) - 2; j++)
    {
        cout << '-';
    }
    cout << '|';
}

void print_three_vector(vector < pair < set <int>, int> > P, unsigned short lS_max)
{
    print_dash(lS_max);
    cout << endl;
    set <int> ::iterator it;
    for (int i = 0; i < P.size(); i++)
    {
        cout << '|' << setw(2) << i << '|';
        for (it = P[i].first.begin(); it != P[i].first.end(); it++)
        {
            cout << setw(3) << *it << '|';
        }
        for (int j = 0; j < lS_max - P[i].first.size(); j++)
        {
            cout << setw(4) << '|';
        }
        //cout << setw(4 * (N - skills_and_salaries[i].first.size() + 3)) << "| зп = " << skills_and_salaries[i].second << endl;
        cout << " зп =" << setw(4) << P[i].second << endl;

        print_dash(lS_max);
        cout << endl;
    }
}

void combinations(int& count, int last, vector <int> indexes, vector < Skills_and_salaries >& skills_and_salaries, vector < pair < set <int>, int> > P)
{
    set <int> unification = {};
    int sum_salaries = 0;
    for (int index = 0; index < indexes.size(); index++)
    {
        copy(P[indexes[index]].first.begin(), P[indexes[index]].first.end(), inserter(unification, unification.begin()));
        sum_salaries += P[indexes[index]].second;
        count++;
    }
    if (indexes.size() != 0)
    {
        Skills_and_salaries sk_and_sa;
        sk_and_sa.index = skills_and_salaries.size();
        sk_and_sa.push(indexes, sum_salaries, unification.size());
        skills_and_salaries.push_back(sk_and_sa);
    }
    
    for (int index = last + 1; index <= P.size(); index++)
    {
        indexes.push_back(index - 1);
        combinations(count, index, indexes, skills_and_salaries, P);
        indexes.pop_back();
    }
    
}

void print_vector_pair(vector < Skills_and_salaries > skills_and_salaries, int size)
{
    if (size > 9)
    {      
        size += (size - 9);
        cout << setw(size - 1) << "Элементы:" << '|' << setw(8) << "Индекс:" << '|' << setw(15) << "Сумма навыков:" << '|' << setw(15) << "Сумма зарплат:" << '|' << endl;

        for (int i = 0; i < skills_and_salaries.size(); i++)
        {        
            int k = 0;
            for (int j = 0; j < skills_and_salaries[i].indexes.size(); j++)
            {
                if (skills_and_salaries[i].indexes[j] > 9)
                    k++;
                cout << skills_and_salaries[i].indexes[j];
            }
            cout << setw(size - skills_and_salaries[i].indexes.size() - k) << '|' << setw(8) << skills_and_salaries[i].index << '|' << setw(15) << skills_and_salaries[i].sum_skills << '|' << setw(15) << skills_and_salaries[i].sum_salaries << '|' << endl;
        }
    }

    else
    {
        cout << setw(9) << "Элементы:" << '|' << setw(8) << "Индекс:" << '|' << setw(15) << "Сумма навыков:" << '|' << setw(15) << "Сумма зарплат:" << '|' << endl;

        for (int i = 0; i < skills_and_salaries.size(); i++)
        {
            for (int j = 0; j < skills_and_salaries[i].indexes.size(); j++)
            {
                cout << skills_and_salaries[i].indexes[j];
            }
            cout << setw(size - skills_and_salaries[i].indexes.size() + 1 + 9 - size) << '|' << setw(8) << skills_and_salaries[i].index << '|' << setw(15) << skills_and_salaries[i].sum_skills << '|' << setw(15) << skills_and_salaries[i].sum_salaries << '|' << endl;
        }
    }
    
    
}

