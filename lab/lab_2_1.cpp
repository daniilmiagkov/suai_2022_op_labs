#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "main_header.h"

using namespace std;

void check(int* array, int length);

void lab_2_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    int length = 6;
    int* array = new int[length];

    for (int i = 0; i < length; i++)
    {
        array[i] = 0;
    }

    std::cout << "¬ведите исходную строку " << std::endl;

    char ch;
    while (true)
    {
        std::cin.get(ch);
        switch (ch)
        {
        case ('('):
            array[0]++;
            break;
        case (')'):
            array[1]++;
            break;
        case ('{'):
            array[2]++;
            break;
        case ('}'):
            array[3]++;
            break;
        case ('['):
            array[4]++;
            break;
        case (']'):
            array[5]++;
            break;
        }
        if (ch == '\n')
            break;
    }

    check(array, length);

}
void check(int* array, int length)
{
    for (int i = 0; i < length - 1; i += 2)
    {
        switch (i)
        {
        case (0):
            std::cout << "()";
            break;
        case (2):
            std::cout << "{}";
            break;
        case (4):
            std::cout << "[]";
            break;
        }

        if (array[i] == array[i + 1])
        {
            std::cout << "True" << std::endl;
        }
        else
        {
            std::cout << "False" << std::endl;
        }
    }
}