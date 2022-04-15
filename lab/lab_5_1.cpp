#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include "string"

using namespace std; //подключение пространства имен std

int find(int x, int count, int& CallCount, int* memory, int deep_level, int* levels, int& max_deep); //прототип функции

void lab_5_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    cout << "\n¬ведите размер последовательности: ";
    int N = get_number_int(); //проверка и присваиваивание с помощью функции get_number

    for (int i = 0; i < N; i++)
    {

    }

}