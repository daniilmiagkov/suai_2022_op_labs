#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include "string"
#include "lab_4_1_func.h"


using namespace std; //подключение пространства имен std


void lab_4_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    unsigned int N,  n, size;
    double average_time = 0;

    cout << "¬ведите количество измерений: ";
    N = get_number_int();
    cout << "¬ведите количество матриц в измерении: ";
    n = get_number_int();
    cout << "¬ведите размер матриц: ";
    size = get_number_int();
    for (int i = 0; i < N; i++)
    {
        average_time += find_time(n, size);
    }

    cout << "среднее врем€ дл€ " << N << " измерений " << n << " матриц размером " << size << " = " << average_time / N / n << "мc";

}




