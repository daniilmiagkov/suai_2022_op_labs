#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "Point.h"
using std::string;
using std::cout;
using std::cin;
using std::pair;

template <typename T>
T get_number_input_after(string str);

template <typename T>
T input_value(T a);

template <typename T>
T get_number();

template <typename T>
bool check(string str);

template <typename T>
bool check_without_print(string str);

template <typename T>
T str_to_number(string str);

string char_to_string(char ch);

Point cursor_position();

void set_cursor_position(Point A);

void erase_past_output(Point A);

template <typename T>
string number_to_str(T a)
{
    string type = typeid(a).name();
    string S = {}, s = {};
    if (type == "int")
    { 
        if (a < 0)
        {
            a = a * -1;
            s += '-';
        }
        while (true)
        {
            S += (a % 10) + '0';
            a /= 10;
            if (a == 0)
                break;
        }
            
        for (int i = S.size() - 1; i != -1; i--)
        {
            s += S[i];
        }
    }
    return s;
}

template <typename T>
T input_value(T a)
{
    string str;
    getline(cin, str);
    if (str[0] == '\0')
        return a;
    return get_number_input_after<T>(str);
}

template <typename T>
T get_number_input_after(string str)
{
    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        if (check<T>(str) == 1)
        {
            return str_to_number<T>(str);
        }
        getline(cin, str);
    }
    
}

template <typename T>
T get_number()
{
    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        string str;
        getline(cin, str);
        if (check<T>(str) == 1) //�������� �� �����
        {
            return str_to_number<T>(str); //�������������� ������ � �����
        }
    }
}

template <typename T>
bool check(string str)
{
    bool k = 1;
    string s = typeid(T).name();

    if ((str.find('-') < 1 || str.find('-') == -1) && ((str.find('.') < str.size() - 1 && str.find('.') > 0) || str.find('.') == -1))
    {
        if (str.length() > 1)
        {
            int count_minus = 0, count_point = 0;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '-')
                {
                    count_minus++;
                }
                if (str[i] == '.')
                {
                    count_point++;
                }
            }
            if ((str[0] == '0' && str[1] != '.') || count_point > 1 ||
                (str[0] == '-' && str[1] == '.') ||
                (str[0] == '-' && str[1] == '0' && str[2] != '.') || count_minus > 1)
            {
                k *= 0;
                std::cout << "!!�� ����� �� �����!!" << std::endl << "������e �����: ";
            }
        }
        else
            if (str == "-")
            {
                k *= 0;
                std::cout << "!!�� ����� �� �����!!" << std::endl << "������e �����: ";
            }
        if (k == 1)
        {
            if (s == "double")
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-')
                    {
                        k *= 0;
                        std::cout << "!!�� ����� �� �����!!" << std::endl << "������e �����: ";
                        break;
                    }
                }
            }
            if (s == "int")
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
                    {
                        k *= 0;
                        std::cout << "!!�� ����� �� ����� �����!!" << std::endl << "������e ����� �����: ";
                        break;
                    }
                }
            }
                
        }
        
    }
    else
    {
        k *= 0;
        std::cout << "!!�� ����� �� �����!!" << std::endl << "������e �����: ";
    }
    
    if (s == "bool")
    {
        if ((str[0] < '0' || str[0] > '1') || str.size() > 1)
        {
            k *= 0;
            std::cout << "!!�� ����� �� ������ �����!!" << std::endl << "������e ������ �����: ";
        }
    }
    return k;
}

template <typename T>
bool check_without_print(string str)
{
    bool k = 1;
    string s = typeid(T).name();

    // 67642.5423
    //�������� �� ����������� ������������� ������ �����
    if ((str.find('-') < 1 || str.find('-') == -1) && ((str.find('.') < str.size() - 1 && str.find('.') > 0) || str.find('.') == -1))
    {
        //���� ����� ������ 
        if (str.length() > 1)
        {
            //�������� �� ����������� ������������� ������ �����
            //����� ���� ������ ����� ��� ������, ���� ���� ������
            //����� - ���� ����, �� ������ ���� ����� ��� ������ 
            int count_minus = 0, count_point = 0;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '-')
                {
                    count_minus++;
                }
                if (str[i] == '.')
                {
                    count_point++;
                }
            }
            if ((str[0] == '0' && str[1] != '.') || count_point > 1 ||
                (str[0] == '-' && str[1] == '.') ||
                (str[0] == '-' && str[1] == '0' && str[2] != '.') || count_minus > 1)
            {
                k *= 0;
            }
        }
        else
            if (str == "-")
            {
                k *= 0;
            }
        if (k == 1)
        {
            if (s == "double")
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-')
                    {
                        k *= 0;
                        break;
                    }
                }
            }
            if (s == "int")
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
        }
    }
    else
    {
        k *= 0;
    }
    if (s == "bool")
    {
        if ((str[0] < '0' || str[0] > '1') && str.size() > 1)
        {
            k *= 0;
            std::cout << "!!�� ����� �� ������ �����!!" << std::endl << "������e ������ �����: ";
        }
    }
    return k;
}

template <typename T>
T str_to_number(std::string str)
{
    T a = 0; //���� �����
    int index = 0, k = 1;
    if (str[0] == '-')
    {
        k = -1;
        str.erase(0, 1);
    }

    if (str.find('.') != -1)
    {
        index = str.find('.');
        str.erase(str.find('.'), 1);
    }
    else
        index = str.length();
    for (int i = 0; i < str.length(); i++)
    {
        a = a * 10 + (str[i] - '0');
    }
    return k * (a / pow(10, (str.length() - index)));
}

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

template <typename T>
T count_char(T a)
{
    T count = 0;
    while (a > 0)
    {
        count++;
        a /= 10;
    }
    return count + 1;
}

