#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include <fstream>
#include <string>

std::pair <int*, int> search_for_an_array_of_residuals(int* array_A_f , int size)
{
    int length = 0;
    int* array_dop_1 = new int[length];
    int* array_dop_2 = new int[length];
    int array_of_divisors[3] = {2,3,5};
    int length_array_dop_2 = 0;

    std::cout << std::endl;
    //может ли остаток 
    for (int i = 0; i < size; i++)
    {
        std::cout << "число = " << array_A_f[i] << ";";
        for (int k = 0; k < 3; k++)
        {
            array_dop_1 = push_back(array_A_f[i] % array_of_divisors[k], length, array_dop_1);
            std::cout 
                << " остаток от деления на " << array_of_divisors[k] 
                << " = " << array_A_f[i] % array_of_divisors[k] << "; ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Массив всех остатков: ";

    for (int i = 0; i < length; i++)
    {
        
        int k = 0;
        for (int j = 0; j < length; j++)
        {
            
            if (array_dop_1[i] == array_dop_1[j])
            {
                k++;
            }
        }

        if (k == 1)
        {
            std::cout << " !" << array_dop_1[i] << "! ";
            array_dop_2 = push_back(array_dop_1[i], length_array_dop_2, array_dop_2);
        }
        else std::cout << array_dop_1[i] << ", ";
        
    }
    std::cout << std::endl;
    return std::pair <int*, int>(array_dop_2, length_array_dop_2);
}

void lab_1_3()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)
    
    int length;
    
    int length_A = 0, length_B = 0;
    int* array_A = new int[length_A];
    int* array_B = new int[length_B];

    std::fstream file_input, file_output;

    file_input.open("D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_input_text.txt", 
        std::ios::out); 
    
    // Запись данных в исходный файл
    if (file_input) {    // Проверяем открыт ли файл
        std::cout << "Введите количество элементов исходного массива" << std::endl;
        while (true)
        {
            length = get_number_int();
            if (length >= 0)
            {
                file_input << length << std::endl;
                for (int i = 0; i < length; i++) //Ввод исходных элементов  
                {
                    std::cout << "Введите " << i + 1 << " число: ";
                    file_input << get_number_int() << " "; // Записываем текст в файл
                }
                break;
            }
            else std::cout 
                << "Количество элементов не может быть отрицательным, введите положительное число: ";
        }
                   
        file_input.close(); // Закрытие файла
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        std::cout << "Файл не открылся!" << std::endl;



    file_input.open("D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_input_text.txt", 
        std::ios::in);
    // Считывание данных из исходного файла
    if (file_input) {    // Проверяем открыт ли файл
        while(!file_input.eof()) { 
            int temp;
            file_input >> temp;
            array_A = push_back(temp, length_A, array_A);
        }
        file_input.close(); // Закрытие файла
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        std::cout << "Файл не открылся!" << std::endl;

    array_A = erase(0, length_A, array_A);
    array_A = erase(length_A - 1, length_A, array_A);

    auto p = search_for_an_array_of_residuals(array_A, length_A);

    array_B = p.first;
    length_B = p.second;

    file_output.open("D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_output_text.txt", 
        std::ios::out);
    if (file_output) {    // Проверяем открыт ли файл
        file_output << length_B << std::endl;
        for (int i = 0; i < length_B; i++) {
            file_output << array_B[i] << " "; // Записываем текст в файл
        }
        file_output.close(); // Закрытие файла
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        std::cout << "Файл не открылся!" << std::endl;
}