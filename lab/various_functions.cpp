#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "various_functions.h"
#include <vector>

using namespace std;

string char_to_string(char ch)
{
    string s = {};
    s += ch;
    return s;
}

template <typename T>
string number_to_str(T a)
{
    string type = typeid(a).name();
    string S = {}, s = {};
    if (type == "int")
    {
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