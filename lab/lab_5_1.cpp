#include <iostream>// ����������
#include <iomanip>
#include <Windows.h> // ����������
#include "various_functions.h"
#include "main_header.h"
#include <string>
#include <vector>

using namespace std; //����������� ������������ ���� std

string check_bool(int N);

void print_sequence(vector<unsigned char> bytes);

vector<bool> fill_array_bits(string s);

void lab_5_1()
{
    srand(clock());
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    string s = "", k;
    cout << "������� ������ ������������������: ";
    int N = get_number<int>(); //�������� � ��������������� � ������� ������� get_number
    vector <bool> sequence(N);

    cout << "����(0) ��� ������(1): ";
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
        cout << "������� ������� ������������������: ";
        getline(cin, s);
        if (s.size() != N)
        {
            m = 0;
            cout << "�� ����� ������������������ �������� �������! " << endl;
        }
        else
        {
            for (int i = 0; i < s.size(); i++)
            {
                k = s[i];
                if (!check_without_print<bool>(k))
                {
                    m = 0;
                    cout << "�� ����� �� ������� ������������������! " << endl;
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
        cout << "������ ���, ������ ��� ��� ���� ����� ����!";
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
    for (int i = 0; i < s.size(); i++) //���� �� ����� ������ 
    {
        str = s[i];
        bits.push_back(str_to_number < bool> (str));
    }
    
    return bits;
}