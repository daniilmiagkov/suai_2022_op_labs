#pragma once
#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "string"
#include "vector"

using std::string;
using std::cout;
using std::cin;
using std::vector;

struct Value
{
    bool debugging = 0;
};

void calculation(vector <vector <long long>> &matrix);

int find_time(unsigned int size);

void print_vector_two_dimensional_4_1(vector <vector <long long>> matrix);

void print_vector_4_1(vector <double> matrix);

vector <double> decision(vector <vector <long long>> matrix);

void decrease(vector <vector <long long>>& matrix);

void fill(vector <vector <long long>>& matrix);
