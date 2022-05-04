#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "lab_4_2_functions.h"
#include "main_header.h"
#include "string"
#include "vector"
#include "Skills_and_salaries.h"
#include <set>
#include <iterator>

using namespace std; //подключение пространства имен std

void lab_4_2()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    unsigned int N, size;
    bool mode, print;
    double average_time = 0;
    cout << "Ручной режим (1) или автоматический (0): ";
    mode = get_number<int>();
    if (mode == 1)
    {
        cout << "Введите количество измерений: ";
        N = get_number<int>();
        cout << "Введите количество человек: ";
        size = get_number<int>();
        cout << "Печатать? Да(1), нет(0): ";
        print = get_number<bool>();
        for (int i = 0; i < N; i++)
        {
            average_time += find_time(size, print);
        }
        cout << "среднее время для " << N << " измерений" << " = " << average_time / N << "мc" << ", кол-во человек = " << size;

    }
    else
    {
        N = 1000;
        for (int j = 2; j < 12; j++)
        {
            for (int i = 0; i < N; i++)
            {
                average_time += find_time(j, 0);
            }
            cout << "среднее время для " << N << " измерений" << " = " << setw(9) << average_time / N << " мc" << ", кол-во человек = " << j << endl;
        }
    }
}
