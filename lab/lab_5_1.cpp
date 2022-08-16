#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include <string>
#include <vector>

using namespace std; //подключение пространства имен std

string check_bool(int N);

void print_sequence(vector<unsigned char> bytes);

vector<bool> fill_array_bits(string s);

void lab_5_1()
{
    srand(clock());
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    string s = "", k;
    cout << "Введите размер последовательности: ";
    int N = get_number<int>(); //проверка и присваиваивание с помощью функции get_number
    vector <bool> sequence(N);

    cout << "Ввод(0) или рандом(1): ";
    bool m = get_number<bool>();
    if (m == 1)
    {
        for (int i = 0; i < N; i++)
        {
            s += number_to_str(rand() % 2);
        }
    }
    else
    {
        s = check_bool(N);
    }

    //s = "1110101111000000011111";

    cout << s << endl;
    int index = 0;
    bool sum;

    vector <bool> bits = fill_array_bits(s);

    for (int i = 0; i < bits.size() - 1; i++)
    {
        if (bits[i + 1] == 1)
        {
            index = i;
            sum = (bits[i]) ^ (bits[i + 1]);
            break;
        }
    }
        

    cout << endl << "sum = " << sum << endl;

    for (int i = index + 1; i < bits.size() - 1; i++)
    {
        cout << "i = " << i << "; bit1 = " << bits[i] << "; bit2 = " << bits[i + 1] << endl;
        if ((bits[i] | bits[i + 1]) != 0)
        {                                      
            cout << "sum (" << sum << ") + " << "bit (" << bits[i + 1] << ") = ";

            sum = sum ^ bits[i + 1];
      
            cout << sum << endl;
        }               
    }

    cout << "sum = " << sum;
    
}

string check_bool(int N)
{
    string s, k;
    int l;
    bool m = 1;
    while (true)
    {
        l = 0;
        m = 1;
        cout << "Введите битовую последовательность: ";
        getline(cin, s);
        if (s.size() != N)
        {
            m = 0;
            cout << "Вы ввели последовательность большего размера! " << endl;
        }
        else
        {
            for (int i = 0; i < s.size(); i++)
            {
                k = s[i];
                if (!check_without_print<bool>(k))
                {
                    m = 0;
                    cout << "Вы ввели не битовую последовательность! " << endl;
                }
                if (s[i] == '0')
                    l++;
            }
        }
        if (m == 1)
            break;

    }
    if (l == s.size())
    {
        cout << "Ответа нет, потому что все биты равны нулю!";
        exit(0);
    }
    return s;
}

void print_sequence(vector <unsigned char> bytes)
{
    for (int i = 0; i < bytes.size(); i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << (bytes[i] >> 7);
            bytes[i] = bytes[i] << 1;
        }
        cout << ' ';
    }
}

vector<bool> fill_array_bits(string s)
{
    vector<bool> bits;
    string str;
    for (int i = 0; i < s.size(); i++) //идем до конца строки 
    {
        str = s[i];
        bits.push_back(str_to_number < bool> (str));
    }
    
    return bits;
}