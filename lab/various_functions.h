#pragma once
#include <string>
using std::string;
using std::cout;
using std::cin;

double get_number_double();
int get_number_int();
int get_number_int_without_input(std::string str);
boolean check_int(string str);
boolean check_double(string str);

int input_value(int a);

template <typename T>
T str_to_number(std::string str)
{
    T a = 0;
    int k = 0, m = 1;
    if (str[0] == '-')
    {
        m = -1;
        str.erase(0, 1);
    }
    if (str.find('.') != -1)
    {
        k = str.find('.');
        str.erase(str.find('.'), 1);
    }
    else k = str.length();
    for (int i = 0; i < str.length(); i++)
    {
        a = a * 10 + (str[i] - '0');
    }
    return m * (a / pow(10, (str.length() - k)));
}

boolean check_int(string str);

boolean check_int_without_print(string str);

template <typename T>
T* push_back(T x, int& length, T* array)
{
    length++;
    T* array_dop = new T[length];
    for (int i = 0; i < length - 1; i++)
    {
        array_dop[i] = array[i];
    }
    array_dop[length - 1] = x;
    return array_dop;
}

template <typename T>
T* erase(int index, int& length, T* array)
{
    length--;
    T* array_dop = new T[length];
    for (int i = 0; i < index; i++)
    {
        array_dop[i] = array[i];
    }
    for (int i = index; i < length; i++)
    {
        array_dop[i] = array[i + 1];
    }
    return array_dop;
}

template <typename T>
T** erase_two_dimensional(int index, int& length, T** array)
{
    length--;
    T** array_dop = new T*[length];
    for (int i = 0; i < index; i++)
    {
        array_dop[i] = array[i];
    }
    for (int i = index; i < length; i++)
    {
        array_dop[i] = array[i + 1];
    }
    return array_dop;
}

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void sorting(int& length, T*& array)
{
    for (int i = 1; i < length; i++)
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
            swap(array[j - 1], array[j]);
}

template <typename T>
void sorting_two_dimensional(int& length, T**& array)
{
    unsigned long long* temp = new unsigned long long[2];
    for (int i = 1; i < length; i++)
        for (int j = i; j > 0 && array[j - 1][0] > array[j][0]; j--)
            swap(array[j - 1], array[j]);
}
/*
template <typename T>
T get_number()
{
    T a;
    while (!(std::cin >> a))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
        std::cout << "\aОшибка ввода! Возможно вы ввели не число, введите число: ";
    }
    return a;
}*/
/*
template <typename T>
T get_number()
{
    while (true)
    {
        T x;
        std::cin >> x;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(9999999999, '\n');
            std::cout << "Please try again to set the number \n";
        }
        else
        {
            return x;
        }
    }
}

/*
template <typename T>
T get_number()
{
    std::string input_s;
    while (true)
    {
        std::cin >> input_s;
        try {
            T res = stoi(input_s);
            return res;
        }
        catch (std::invalid_argument e) {
            std::cout << "Ошибка ввода. Возможно вы ввели не число, введите число: \n";
        }
    }
}
*/