#include <iostream>// ����������
#include <Windows.h> // ����������


static double getNumber()
{
    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        double a;
        std::cin >> a;

        if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
        {
            std::cout << "�� ����� �� �����" << std::endl;
            std::cin.clear(); // �� ���������� cin � '�������' ����� ������
            std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
        }
        else // ���� �� ������, �� ���������� a
            return a;
    }
}

double calculation_function(int N, int x)
{
    double result = 0;
    if (N == 0)
    {
        result = pow(x + 1, 0.5);
    }
    else
    {
        result = pow((x + N * int(calculation_function(N - 1, x))), 0.5);
    }
    std::cout << N << " " << result << std::endl ;
    // 3 + 1.5 * 
    // 3 + 0.5 * 
    return result;
}

void main()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    double N, x;
    std::cout << "������� ����� N" << std::endl;
    N = getNumber();
    std::cout << "������� ����� x " << std::endl;
    x = getNumber();
    std::cout << calculation_function(N, x);
}