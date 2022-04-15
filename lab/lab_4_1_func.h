#pragma once
#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "string"
#include "vector"

using namespace std;

struct Values
{
    boolean debugging = 0;
};

void calculation(vector <vector <long long>> &matrix);

int find_time(unsigned int n, unsigned int size);

void print_vector_two_dimensional(vector <vector <long long>> matrix);

void print_vector(vector <double> matrix);

vector <double> decision(vector <vector <long long>> matrix);

void decrease(vector <vector <long long>>& matrix);

void fill(vector <vector <long long>>& matrix);
