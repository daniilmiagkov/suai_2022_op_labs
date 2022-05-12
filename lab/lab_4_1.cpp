#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include "string"
#include "lab_4_1_func.h"

using std::endl;

void lab_4_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    unsigned int N, size;
    double average_time = 0;

    cout << "Введите количество измерений: ";
    N = get_number<int>();
    cout << "Введите размер матриц или введите ноль, чтобы посмотреть время: ";
    size = get_number<int>();
    if (size == 0)
    {
        for (int size = 1; size < 10; size++)
        {
            for (int i = 0; i < N; i++)
            {
                average_time += find_time(size);
            }    
            cout << "среднее время для " << N << " измерений " << "матриц размером " << size << " = " << average_time / N << "мc" << endl;

        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            average_time += find_time(size);
        }
        cout << "среднее время для " << N << " измерений " << "матриц размером " << size << " = " << average_time / N << "мc" << endl;

    }
}




