#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "various_functions.h"
#include <vector>
#include "dop_task_1_functions.cpp"

using namespace std;

template <typename T>
T str_to_number(std::string str);

double get_number_double()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::string str;
        getline(cin, str);
        if (check_int(str) == 1)
        {
            return str_to_number<int>(str);
        }
    }
}

int input_value(int a)
{
    string str;
    getline(cin, str);
    bufer += str;
    if (str[0] == '\0')
        return a;

    return get_number_int_without_input(str);
}

int get_number_int()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::string str;
        getline(cin, str);
                
        if (check_int(str) == 1)
        {
            return str_to_number<int>(str);
        } 
    }
}

char* get_random_array_of_char()
{
    int len = rand() % 20 + 10;
    char* array = new char[len];

    for (int i = 0; i < len; i++)
    {

    }
    return array;
}

boolean check_int(string str)
{
    boolean k = 1;

    if (str.length() > 1)
    {
        if (((str[0] == '-') && (str[1] == '.' || (str[1] == '0' && str[2] != '.'))) ||
            str[0] == '.' || (str[0] == '0' && str[1] != '.' && str[1] != '\n'))
        {
            k *= 0;
            std::cout << "!!Вы ввели не число!!" << std::endl << "Введитe число: ";
        }
        else
        {
            for (int i = 0; i < str.length(); i++)
            {

                if ((str[i] < '0' || str[i] > '9') && str.find('-') > 0 && str.find('-') != '-1')
                {
                    k *= 0;
                    std::cout << "!!Вы ввели не целое число!!" << std::endl << "Введите целое число: ";
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            {
                k *= 0;
                std::cout << "!!Вы ввели не целое число!!" << std::endl << "Введите целое число: ";
                break;
            }
        }
    }
    return k;
}

boolean check_int_without_print(string str)
{
    boolean k = 1;

        if (str.length() > 1)
        {
            if (((str[0] == '-') && (str[1] == '.' || (str[1] == '0' && str[2] != '.'))) ||
                str[0] == '.' || (str[0] == '0' && str[1] != '.' && str[1] != '\n'))
            {
                k *= 0;
            }
            else
            {
                for (int i = 0; i < str.length(); i++)
                {

                    if ((str[i] < '0' || str[i] > '9') && str.find('-') > 0 && str.find('-') != '-1')
                    {
                        k *= 0;
                        break;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < str.length(); i++)
            {
                if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
                {
                    k *= 0;
                    break;
                }
            }
        }
    return k;
}

int get_number_int_without_input(std::string str)
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        if (check_int(str) == 1)
        {
            return str_to_number<int>(str);
        }
        getline(cin, str);
    }
    
}

void output_vector_int(std::vector<int>& array)
{
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << std::endl;
    }
}

void output_vector_string(std::vector<std::string>& array)
{
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << std::endl;
    }
}