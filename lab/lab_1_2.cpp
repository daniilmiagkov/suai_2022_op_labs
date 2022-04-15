#include <iostream>// ����������
#include <Windows.h> // ����������
#include "main_header.h"
#include "various_functions.h"

void calculation_function(double x, int N) {
    double result = pow(x + 1, 0.5);
    for (int i = 1; i <= N; i++)
        result = pow(x + i * int(result), 0.5);
    std::cout << result;
}

/*
double calculation_function(double x, int N)
{
    if (N > 0)
        return pow(x + N * int(calculation_function(x, N-1)), 0.5);
    return pow(x + 1, 0.5);
}*/

void lab_1_2()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    int N;
    double x;
    std::cout << "������� ����� ����� N" << std::endl;
    N = get_number_int();
    std::cout << "������� ����� x " << std::endl;
    x = get_number_double();
    calculation_function(x, N);
}
