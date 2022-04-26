#include <iostream>// ����������
#include <iomanip>
#include <Windows.h> // ����������
#include "various_functions.h"
#include "main_header.h"
#include "string"
#include <vector>

using namespace std; //����������� ������������ ���� std

int find(int x, int count, int& call_count, vector<int> memory, int deep_level, vector<int> levels, int& max_deep_level);

void lab_3_1()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    cout << "������� �����: ";
    int number; //��������������� � ������� ������� get_number_int
    cin >> number;
    int call_count = 0, deep_level = 0, max_deep_level = 0;
    //�������� ���� ��������
    vector <int> memory = {};
    vector <int> levels = {};

    cout
        << "\n���������� �������: | ���������� ������: | ����� � �������� ������ | �������: | ��������: "
        << endl;

    cout
        << endl
        << "���������� ������: " << find(number, 0, call_count, memory, deep_level, levels, max_deep_level) << endl
        << "���������� �������: " << call_count << endl
        << "������������ �������: " << max_deep_level << endl;
}

int find(int x, int count, int& call_count, vector<int> memory, int deep_level, vector<int> levels, int& max_deep_level)
{
    
    levels.push_back(deep_level);//������ � ������ ������ ������� 
    memory.push_back(x);//������ � ������ �������� �����
    if (deep_level > max_deep_level)
    {
        max_deep_level = deep_level;//���������� ������������ ������� 
    }
    //����� 
    cout 
        << setw(20) << call_count + 1 << "|"
        << setw(20) << count << "|"
        << setw(25) << x % 2 << "|"
        << setw(10) << levels[call_count] << "|"
        << setw(11) << memory[call_count] << "|"
        << endl;
    call_count++;
    if (x % 2 == 1)
        count++; //���������� ���������� ������
    if (x == 0)
        return count;
    return find(x /= 2, count, call_count, memory, deep_level + 1, levels, max_deep_level);
}
