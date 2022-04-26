#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "various_functions.h"
#include <vector>

using namespace std;

char* get_random_array_of_char()
{
    int len = rand() % 20 + 10;
    char* array = new char[len];

    for (int i = 0; i < len; i++)
    {

    }
    return array;
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