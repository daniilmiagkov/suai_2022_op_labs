#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include "string"

using namespace std; //подключение пространства имен std

int find(int x, int count, int& CallCount,int* memory, int deep_level, int* levels, int& max_deep); //прототип функции

void lab_3_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    cout << "Введите число: ";
    int number = get_number_int(); //проверка и присваиваивание с помощью функции get_number_int
    int call_count = 0, deep_level = 0, max_deep_level = 0;
    //создание двух массивов
    int* memory = new int[call_count];
    int* levels = new int[deep_level];

    cout
        << "\nКоличество вызовов: | Количество единиц: | Число в двоичной записи | Глубина: | Значение: "
        << endl;

    cout
        << endl
        << "Количество единиц: " << find(number, 0, call_count, memory, deep_level, levels, max_deep_level) << endl
        << "Количество вызовов: " << call_count << endl
        << "Максимальная глубина: " << max_deep_level << endl;
}

int find(int x, int count, int& call_count, int* memory, int deep_level, int* levels, int& max_deep_level)
{
    levels = push_back(deep_level, call_count, levels);//запись в массив уровня глубины 
    call_count--;
    memory = push_back(x, call_count, memory);//запись в массив значения числа
    if (deep_level > max_deep_level)
    {
        max_deep_level = deep_level;//нахождение максимальной глубины 
    }
    //вывод 
    cout 
        << setw(20) << call_count << "|"
        << setw(20) << count << "|"
        << setw(25) << x % 2 << "|"
        << setw(10) << levels[call_count - 1] << "|"
        << setw(11) << memory[call_count - 1] << "|"
        << endl;
    if (x % 2 == 1)
        count++; //нахождение количества единиц
    if (x == 0)
        return count;
    return find(x /= 2, count, call_count, memory, deep_level + 1, levels, max_deep_level);
}


/*
int find(int x, int count, int& call_count, int deep_level, int& max_deep_level)
{
    if (deep_level > max_deep_level)
    {
        max_deep_level = deep_level;
    }

    if (x != 0)
    {
        cout
            << setw(20) << call_count << "|"
            << setw(20) << count << "|"
            << setw(25) << x % 2 << "|"
            << setw(10) << deep_level << "|"
            << setw(11) << x << "|"
            << endl;
        if (x % 2 == 1)
            count++;
        return find(x /= 2, count, call_count, deep_level + 1, max_deep_level);
    }
    cout
        << setw(20) << call_count << "|"
        << setw(20) << count << "|"
        << setw(25) << "" << "|"
        << setw(10) << deep_level << "|"
        << setw(11) << x << "|"
        << endl;
    return count;
}*/