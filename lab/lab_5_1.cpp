#include <iostream>// ����������
#include <iomanip>
#include <Windows.h> // ����������
#include "various_functions.h"
#include "main_header.h"
#include "string"

using namespace std; //����������� ������������ ���� std

int find(int x, int count, int& CallCount, int* memory, int deep_level, int* levels, int& max_deep); //�������� �������

void lab_5_1()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    cout << "\n������� ������ ������������������: ";
    int N = get_number_int(); //�������� � ��������������� � ������� ������� get_number

    for (int i = 0; i < N; i++)
    {

    }

}