#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "lab_4_2_functions.h"
#include "string"
#include "vector"
#include <set>
#include <iterator>

using namespace std; //подключение пространства имен std


int find(vector < pair < int, int> > P, int Z_max)
{
    int salary_max = 0;
    int skills_max = 0;
    for (int i = 0; i < P.size(); i++)
    {
        if (P[i].first > salary_max && P[i].second < Z_max)
        {
            skills_max = ;
        }
    }
    for (int i = 0; i < P.size(); i++)
    {
        if (P[i].first == )

        {
            skills_max = i;
        }
    }
    return skills_max;
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

        P[i] = make_pair(S, lS * 20 + rand() % 10);
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
        cout << '|' << setw(2) << i + 1 << '|';
        for (it = P[i].first.begin(); it != P[i].first.end(); it++)
        {
            cout << setw(3) << *it << '|';
        }
        for (int j = 0; j < lS_max - P[i].first.size(); j++)
        {
            cout << setw(4) << '|';
        }
        //cout << setw(4 * (N - P[i].first.size() + 3)) << "| зп = " << P[i].second << endl;
        cout << " зп =" << setw(4) << P[i].second << endl;

        print_dash(lS_max);
        cout << endl;
    }
}

void repetitions(int& count, int last, vector <int> indexes, vector < pair < int, int> >& skills_and_salaries, vector < pair < set <int>, int> > P)
{
    set <int> unification = {};
    int sum_salaries = 0;

    for (int index = 0; index < indexes.size(); index++)
    {
        copy(P[indexes[index]].first.begin(), P[indexes[index]].first.end(), inserter(unification, unification.begin()));
        sum_salaries += P[indexes[index]].second;
        count++;
        cout << indexes[index];
    }
    if (indexes.size() != 0)
    {
        skills_and_salaries.push_back(make_pair(unification.size(), sum_salaries));
        cout << endl;
    }
    
    for (int index = last + 1; index <= P.size(); index++)
    {
        indexes.push_back(index - 1);
        repetitions(count, index, indexes, skills_and_salaries, P);
        indexes.pop_back();
    }
}

void print_vector_pair(vector < pair < int, int> > skills_and_salaries)
{
    for (int i = 0; i < skills_and_salaries.size(); i++)
    {
        cout << setw(3) << i << setw(8) << skills_and_salaries[i].first << setw(4) << skills_and_salaries[i].second << endl;
    }
}
