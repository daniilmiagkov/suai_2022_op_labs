#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include "string"
#include "lab_4_1_func.h"

void lab_4_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    unsigned int N,  n, size;
    double average_time = 0;

    cout << "Введите количество измерений: ";
    N = get_number<int>();
    cout << "Введите количество матриц в измерении: ";
    n = get_number<int>();
    cout << "Введите размер матриц: ";
    size = get_number<int>();
    for (int i = 0; i < N; i++)
    {
        average_time += find_time(n, size);
    }

    cout << "среднее время для " << N << " измерений " << n << " матриц размером " << size << " = " << average_time / N / n << "мc";

}




