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

vector<unsigned char> fill_array_bytes(string s);

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

vector<unsigned char> fill_array_bytes(string s)
{
    vector<unsigned char> bytes;
    int byteIndex; //������ ����� � �������
    for (int i = 0; i < s.size(); i++) //���� �� ����� ������ 
    {
        if (i % 8 == 0) //���� ������� �����, ��������� � ������ ������� ������
            bytes.push_back('\0');
        byteIndex = i / 8;
        bytes[byteIndex] = (bytes[byteIndex] << 1) | (s[i] - '0');
        //�������� ���� ����� �������� ������� 0000 0000 
        //����� �� �������� ��� �� 1 ����� 0000 0000
        //����� ���������� � ��������� ������, �� ������� ����� '0'. '9' = 57 - '0' = 57 - 49 = 9
        //���������� 0000 0001
        //��� ��� 
        //�������� ���� ������ ����� 0000 0001
        //�������� 0000 0010. ����� + 1
        //�������� 0000 0011
    }
    if (s.size() % 8 != 0) //���� ��������� ���� ���������� �� ���������, �������� ��� �� �����, �������� �� ������� �� ������� ����������. 8 - 6 = 2
        bytes[byteIndex] = bytes[byteIndex] << (8 - s.size() % 8);
    return bytes;
}