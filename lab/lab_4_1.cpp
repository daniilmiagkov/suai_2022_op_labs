#include <iostream>// ����������
#include <iomanip>
#include <Windows.h> // ����������
#include "various_functions.h"
#include "main_header.h"
#include "string"
#include "lab_4_1_func.h"


using namespace std; //����������� ������������ ���� std


void lab_4_1()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    unsigned int N,  n, size;
    double average_time = 0;

    cout << "������� ���������� ���������: ";
    N = get_number_int();
    cout << "������� ���������� ������ � ���������: ";
    n = get_number_int();
    cout << "������� ������ ������: ";
    size = get_number_int();
    for (int i = 0; i < N; i++)
    {
        average_time += find_time(n, size);
    }

    cout << "������� ����� ��� " << N << " ��������� " << n << " ������ �������� " << size << " = " << average_time / N / n << "�c";

}




