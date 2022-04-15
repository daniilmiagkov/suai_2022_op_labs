#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include <fstream>
#include <string>

int* search_for_an_array_of_residuals(int* array_A, int& length)
{
    int* array_of_residuals = new int[length * 3];
    int* array_of_non_repeating_residues = new int[length];
    int array_of_divisors[3] = { 2,3,5 };
    int length_array_dop_2 = 0;

    std::cout << std::endl;
    
    for (int i = 0; i < length * 3; i += 3)
    {
        std::cout << "число = " << array_A[i / 3] << ";";
        for (int k = 0; k < 3; k++)
        {
            int temp = array_A[i / 3] % array_of_divisors[k];
            array_of_residuals[i + k] = temp;
            std::cout
                << " остаток от деления на " << array_of_divisors[k]
                << " = " << temp << "; ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Массив всех остатков: ";

    int l = 0;
    for (int i = 0; i < length * 3; i++)
    {
        int k = 0;

        for (int j = 0; j < length * 3; j++)
        {
            if (array_of_residuals[i] == array_of_residuals[j])
                k++;
        }

        if (k == 1)
        {
            
            std::cout << " !" << array_of_residuals[i] << "! ";
            array_of_non_repeating_residues[l] = array_of_residuals[i];
            l++;
        }
        else std::cout << array_of_residuals[i] << ", ";

    }
    std::cout << std::endl;
    length = l;
    return array_of_non_repeating_residues;
}

void lab_1_3_temp()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    
    int length;

    std::fstream file_input, file_output;

    file_input.open("D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_input_text.txt",
        std::ios::out);

    // Запись данных в исходный файл
    if (file_input) {    // Проверяем открыт ли файл
        std::cout << "Введите количество элементов исходного массива" << std::endl;
        while (true)
        {
            length = get_number<int>();
            if (length >= 0)
            {
                file_input << length << std::endl;
                for (int i = 0; i < length; i++) //Ввод исходных элементов  
                {
                    std::cout << "Введите " << i + 1 << " число: ";
                    file_input << get_number<int>() << " "; // Записываем текст в файл
                }
                break;
            }
            else std::cout
                << "Количество элементов не может быть отрицательным, введите положительное число: ";
        }
        file_input.close(); // Закрытие файлa
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        std::cout << "Файл не открылся!" << std::endl;



    file_input.open("D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_input_text.txt",
        std::ios::in);
    file_output.open("D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_output_text.txt",
        std::ios::out);
    
    
    // Считывание данных из исходного файла
    if (file_input) {    // Проверяем открыт ли файл
        if (file_output) {    // Проверяем открыт ли файл
        
            int temp, i = 0, k = 0;
            file_input >> length;
            int* array_A = new int[length];
            int* array_B = new int[4]; 

            for (int i = 0; i < length; i ++)
            {
                file_input >> temp;
                array_A[i] = temp;
            }

            array_B = search_for_an_array_of_residuals(array_A, length);

            file_output << length << std::endl;
            for (int i = 0; i < length; i++) {
                file_output << array_B[i] << " "; // Записываем текст в файл
            }

            file_input.close(); // Закрытие файла 
            file_output.close(); // Закрытие файла

        }
        else // Если файл не удалось открыть, тогда выдаем ошибку
            std::cout << "Файл output не открылся!" << std::endl;
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        std::cout << "Файл input не открылся!" << std::endl;
    
    
    
}