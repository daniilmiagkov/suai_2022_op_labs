#pragma once
#include <iostream>// ����������
#include <iomanip>
#include <Windows.h> // ����������
#include "various_functions.h"
#include "string"
#include "vector"
#include <set>
#include <iterator>

using namespace std; //����������� ������������ ���� std
struct Values
{
    boolean debugging = 1;
};
int find(vector < pair < int, int> > P, int Z_max);

void repetitions(int& count, int last, vector <int> b, vector < pair < int, int> >& skills_and_salaries, vector < pair < set <int>, int> > P);

int in_count_ckills();

int input_count_people();

void fill_pair(vector < pair < set <int>, int> >& P, unsigned short N, unsigned short lS_max, unsigned short Z_max);

void print_dash(int count);

void print_three_vector(vector < pair < set <int>, int> > P, unsigned short lS_max);

void print_vector_pair(vector < pair < int, int> > skills_and_salaries);
