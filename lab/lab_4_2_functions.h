#pragma once
#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "string"
#include "vector"
#include <set>
#include <iterator>

using namespace std; //подключение пространства имен std
struct Values
{
    boolean debugging = 1;
};
int find(vector < pair < int, int> > P, int Z_max);

int in_count_ckills();

int in_count_people();

void fill_pair(vector < pair < set <int>, int> >& P, unsigned short N, unsigned short lS_max, unsigned short Z_max);

void print_dash(int count);

void print_three_vector(vector < pair < set <int>, int> > P, unsigned short lS_max);

void push(int n, vector <int>& indexes, set <set<int>>& sets_indexes);

void sochetaniya(int n, int size_a, set <set<int>>& sets_indexes, vector <int>& indexes);

void calculation(set <set<int>>& sets_indexes, vector < pair < int, int> >& skills_and_salaries, vector < pair < set <int>, int> > P);

void print_vector_pair(vector < pair < int, int> > skills_and_salaries);
