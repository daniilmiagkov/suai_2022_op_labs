#include <iostream>// ����������
#include <iomanip>
#include <Windows.h> // ����������
#include "various_functions.h"
#include "main_header.h"
#include <string>
#include <vector>

using namespace std; //����������� ������������ ���� std

string check_bool();

void lab_5_1()
{
    //1110101111000000011111
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)
    
    string s, k;
    cout << "������� ������ ������������������: ";
    int N = get_number<int>(); //�������� � ��������������� � ������� ������� get_number
    vector <bool> sequence(N);
    
    cout << "����(0) ��� ������(1): ";
    bool m = get_number<bool>();
    if (m == 1)
    {
        for (int i = 0; i < N; i++)
        {
            sequence[i] = rand() % 2;
            cout << sequence[i];
        }
    }
    else
    {
        s = check_bool();
        for (int i = 0; i < N; i++)
        {
            sequence[i] = s[i] - '0';
        }
    }
    cout << endl;
    bool sum;
    int index;
    
    
}

string check_bool()
{
    string s, k;
    bool m = 1;
    while (true)
    {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++)
        {
            k = s[i];
            if (!check<bool>(k))
                m = 0;
        }
        if (m == 1)
            break;
        else
            cout << "�� ����� �� ������� ������������������";
    }
    return s;
}