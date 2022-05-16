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

vector<unsigned char> fill_array_bytes(string s);

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

    s = "1110101111000000011111";

    vector<unsigned char> bytes = fill_array_bytes(s);

    bool sum;
    if (bytes[0] >> 7 == 0)
    {
        for (int i = 0; i < bytes.size(); i++)
            bytes[i] = ~bytes[i];
        unsigned char byte = bytes[0] << 1;
        sum = (bytes[0] >> 7) ^ (byte >> 7);

        print_sequence(bytes);
        cout << endl << sum << endl;

        bytes[0] = bytes[0] << 1;
    
        for (int i = 1; i < s.size(); i++)
        {
            byte = bytes[i / 8] << 1;
            cout << (bytes[i / 8] >> 7) << "; ";
            if (bytes[i / 8] >> 7 != 1 && byte >> 7 != 1)
            {
                sum = sum ^ (byte >> 7);
                cout << sum;
            }
            cout << endl;
            bytes[i / 8] = bytes[i / 8] << 1;

        }    
    }
    else
    {
        print_sequence(bytes);

        unsigned char byte = bytes[0] << 1;
        sum = (bytes[0] >> 7) ^ (byte >> 7);

        cout << endl << sum << endl;

        bytes[0] = bytes[0] << 1;

        for (int i = 1; i < s.size(); i++)
        {
            byte = bytes[i / 8] << 1;
            cout << (bytes[i / 8] >> 7) << "; ";
            if (bytes[i / 8] >> 7 != 0 && byte >> 7 != 0)
            {
                sum = sum ^ (byte >> 7);
                cout << sum;
            }
            cout << endl;
            bytes[i / 8] = bytes[i / 8] << 1;

        }
    }

    cout << sum;
    
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

vector<unsigned char> fill_array_bytes(string s)
{
    vector<unsigned char> bytes;
    int byteIndex; //индекс байта в векторе
    for (int i = 0; i < s.size(); i++) //идем до конца строки 
    {
        if (i % 8 == 0) //если условие верно, добавляем в вектор нулевой символ
            bytes.push_back('\0');
        byteIndex = i / 8;
        bytes[byteIndex] = (bytes[byteIndex] << 1) | (s[i] - '0');
        //исходный байт равен нулевому символу 0000 0000 
        //затем мы сдвигаем его на 1 влево 0000 0000
        //затем складываем с элементом строки, из которой вычли '0'. '9' = 57 - '0' = 57 - 49 = 9
        //получается 0000 0001
        //ещё раз 
        //исходный байт теперь равен 0000 0001
        //сдвигаем 0000 0010. потом + 1
        //получаем 0000 0011
    }
    if (s.size() % 8 != 0) //если последний байт заполнился не полностью, сдвигаем его на число, которого не хватает до полного заполнения. 8 - 6 = 2
        bytes[byteIndex] = bytes[byteIndex] << (8 - s.size() % 8);
    return bytes;
}