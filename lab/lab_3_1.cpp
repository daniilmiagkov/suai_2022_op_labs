#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include "string"
#include <vector>

using namespace std; //подключение пространства имен std

int find(int x, int count, int& call_count, vector<int> memory, int deep_level, vector<int> levels, int& max_deep_level);

void lab_3_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    cout << "Введите число: ";
    int number; //присваиваивание с помощью функции get_number_int
    cin >> number;
    int call_count = 0, deep_level = 0, max_deep_level = 0;
    //создание двух массивов
    vector <int> memory = {};
    vector <int> levels = {};

    cout
        << "\nКоличество вызовов: | Количество единиц: | Число в двоичной записи | Глубина: | Значение: "
        << endl;

    cout
        << endl
        << "Количество единиц: " << find(number, 0, call_count, memory, deep_level, levels, max_deep_level) << endl
        << "Количество вызовов: " << call_count << endl
        << "Максимальная глубина: " << max_deep_level << endl;
}

int find(int x, int count, int& call_count, vector<int> memory, int deep_level, vector<int> levels, int& max_deep_level)
{
    
    levels.push_back(deep_level);//запись в массив уровня глубины 
    memory.push_back(x);//запись в массив значения числа
    if (deep_level > max_deep_level)
    {
        max_deep_level = deep_level;//нахождение максимальной глубины 
    }
    //вывод 
    cout 
        << setw(20) << call_count + 1 << "|"
        << setw(20) << count << "|"
        << setw(25) << x % 2 << "|"
        << setw(10) << levels[call_count] << "|"
        << setw(11) << memory[call_count] << "|"
        << endl;
    call_count++;
    if (x % 2 == 1)
        count++; //нахождение количества единиц
    if (x == 0)
        return count;
    return find(x /= 2, count, call_count, memory, deep_level + 1, levels, max_deep_level);
}
