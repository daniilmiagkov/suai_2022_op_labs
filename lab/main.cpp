#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "main_header.h"
#include "various_functions.h"

int main()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    double task_number;
    boolean debugging = true;
    if (debugging == true)
    {
        //lab_2_1();
        //lab_5_1();
        //lab_2_2();
        //lab_4_2();
        //lab_4_1();
        //dop_task_1();
        //lab_3_1();
        lab_3_2();
        //lab_3_2_copy();
    }
    else
    {
        std::cout 
            << "Готовые лабораторные работы: " << std::endl
            << std::endl
            << "    1.1 Поиск макс. суммы двух элементов " << std::endl
            << "    1.2 Цикл с вычислением функции " << std::endl
            << "    1.3 Поиск неповторяющихся остатков от деления " << std::endl
            << "    2.1 Количество скобок " << std::endl
            << "    2.2 Бинарный поиск строки по хэшу " << std::endl
            << "    3.1 Рекурсия " << std::endl
            << "    4.1 Оценка алгоритма (Гаусс) " << std::endl
            << "    4.2 База данных " << std::endl
            << "    5.1 Битовая последовательность " << std::endl
            << std::endl
            << "Введите номер лабораторной работы: ";

        while (true)
        {
            task_number = get_number<double>();
            if (task_number == 1.1 ||
                task_number == 1.2 ||
                task_number == 1.3 ||
                task_number == 2.1 ||
                task_number == 2.2 ||
                task_number == 3.1 ||
                task_number == 4.1 ||
                task_number == 4.2 ||
                task_number == 5.1)
            {
                system("cls");
                std::cout << "Лабораторная работа № " << task_number << std::endl;
                break;
            }
            else std::cout << "Такой лабораторной работы нет, введите другой номер: ";
        }
        if (task_number == 1.1)
        {
            lab_1_1();
        }
        else if (task_number == 1.2)
        {
            lab_1_2();
        }
        else if (task_number == 1.3)
        {
            lab_1_3();
        }
        else if (task_number == 2.1)
        {   
            lab_2_1();
        } 
        else if (task_number == 2.2)
        {
            lab_2_2();
        }
        else if (task_number == 3.1)
        {
            lab_3_1();
        }
        else if (task_number == 4.1)
        {
            lab_4_1();
        }
        else if (task_number == 4.2)
        {
            lab_4_2();
        }
        else if (task_number == 5.1)
        {
            lab_5_1();
        }
     
    }
    return 0;
}