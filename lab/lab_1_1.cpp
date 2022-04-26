#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "main_header.h"
#include "various_functions.h"

void sorting(double array_of_sources[]) //сортировка массива
{
    int j = 0;
    double tmp = 0;
    for (int i = 0; i < 4; i++) 
    {
        j = i;
        for (int k = i; k < 4; k++) 
        {
            if (array_of_sources[j] > array_of_sources[k])
            {
                j = k;
            }
        }
        tmp = array_of_sources[i];
        array_of_sources[i] = array_of_sources[j];
        array_of_sources[j] = tmp;
    } 
}

void lab_1_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)
    
    double array_of_sources[4];
    std::cout << "Введите числа по одному" << std::endl;

    for (int i = 0; i < 4; i++) //ввод исходных элементов  
    {
        std::cout << "Введите " << i + 1 << " число: ";
        array_of_sources[i] = get_number<double>();
        std::cout << "число = " << array_of_sources[i] << std::endl;

    }
    sorting(array_of_sources);
    std::cout << array_of_sources[2] + array_of_sources[3];
}
