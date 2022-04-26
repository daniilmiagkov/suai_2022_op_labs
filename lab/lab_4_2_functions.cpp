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
    int i_max = 0;
    for (int i = 0; i < P.size(); i++)
    {

        if (P[i].first > salary_max && P[i].second < Z_max)
        {
            i_max = i;
            salary_max = P[i].first;
        }
    }
    return i_max;
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
        lS = rand() % (lS_max + 1);
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
    for (int j = 0; j <= 7; j++)
    {
        cout << '-';
    }
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

void push(int n, vector <int>& indexes, set <set<int>>& sets_indexes)
{
    set <int> s;
    Values value;
    if (value.debugging == 1)
    {
        for (int i = 0; i < indexes.size(); i++)
        {
            s = {};
            for (int j = 0; j < indexes.size(); j++)
            {
                s.insert(indexes[j]);
                cout << indexes[j];
            }
            sets_indexes.insert(s);
            cout << endl;
            indexes[n]++;
        }
    }
    else
    {
        for (int i = 0; i < indexes.size(); i++)
        {
            s = {};
            for (int j = 0; j < indexes.size(); j++)
            {
                s.insert(indexes[j]);
            }
            sets_indexes.insert(s);
            indexes[n]++;
        }
    }
}

void sochetaniya(int n, int size_a, set <set<int>>& sets_indexes, vector <int>& indexes)
{
    cout << n << endl;
    if (n == size_a - 1)
    {
        push(n, indexes, sets_indexes);
        indexes[n] = 0;
    }
    else
        if (n < size_a - 1)
        {
            for (int i = 0; i < size_a; i++)
            {
                indexes[n] = i;
                sochetaniya(n + 1, size_a, sets_indexes, indexes);
            }
        }

}

void calculation(set <set<int>>& sets_indexes, vector < pair < int, int> >& skills_and_salaries, vector < pair < set <int>, int> > P)
{
    set <int> ::iterator it;
    set<set <int>> ::iterator it_it;
    Values value;
    int sum_salaries = 0;
    set <int> unification = {};
    for (it_it = sets_indexes.begin(); it_it != sets_indexes.end(); it_it++)
    {
        sum_salaries = 0;
        unification = {};
        for (it = it_it->begin(); it != it_it->end(); it++)
        {
            if (value.debugging == 1)
                cout << *it;
            copy(P[*it].first.begin(), P[*it].first.end(), inserter(unification, unification.begin()));
            sum_salaries += P[*it].second;
        }
        if (value.debugging == 1)
            cout << endl;
        skills_and_salaries.push_back(make_pair(unification.size(), sum_salaries));
    }
}

void print_vector_pair(vector < pair < int, int> > skills_and_salaries)
{
    for (int i = 0; i < skills_and_salaries.size(); i++)
    {
        cout << setw(8) << skills_and_salaries[i].first << setw(4) << skills_and_salaries[i].second << endl;
    }
}
