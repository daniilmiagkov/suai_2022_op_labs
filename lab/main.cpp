#include <iostream>// ����������
#include <Windows.h> // ����������
#include "main_header.h"
#include "various_functions.h"

int main()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    double task_number;
    boolean debugging = true;
    if (debugging == true)
    {
        //lab_2_1();
        //lab_5_1();
        //lab_2_2();
        //lab_4_2();
        //lab_4_1();
        //dop_task_1();
        //lab_3_1();
        lab_3_2();
        //lab_3_2_copy();
    }
    else
    {
        std::cout 
            << "������� ������������ ������: " << std::endl
            << std::endl
            << "    1.1 ����� ����. ����� ���� ��������� " << std::endl
            << "    1.2 ���� � ����������� ������� " << std::endl
            << "    1.3 ����� ��������������� �������� �� ������� " << std::endl
            << "    2.1 ���������� ������ " << std::endl
            << "    2.2 �������� ����� ������ �� ���� " << std::endl
            << "    3.1 �������� " << std::endl
            << "    4.1 ������ ��������� (�����) " << std::endl
            << "    4.2 ���� ������ " << std::endl
            << "    5.1 ������� ������������������ " << std::endl
            << std::endl
            << "������� ����� ������������ ������: ";

        while (true)
        {
            task_number = get_number<double>();
            if (task_number == 1.1 ||
                task_number == 1.2 ||
                task_number == 1.3 ||
                task_number == 2.1 ||
                task_number == 2.2 ||
                task_number == 3.1 ||
                task_number == 4.1 ||
                task_number == 4.2 ||
                task_number == 5.1)
            {
                system("cls");
                std::cout << "������������ ������ � " << task_number << std::endl;
                break;
            }
            else std::cout << "����� ������������ ������ ���, ������� ������ �����: ";
        }
        if (task_number == 1.1)
        {
            lab_1_1();
        }
        else if (task_number == 1.2)
        {
            lab_1_2();
        }
        else if (task_number == 1.3)
        {
            lab_1_3();
        }
        else if (task_number == 2.1)
        {   
            lab_2_1();
        } 
        else if (task_number == 2.2)
        {
            lab_2_2();
        }
        else if (task_number == 3.1)
        {
            lab_3_1();
        }
        else if (task_number == 4.1)
        {
            lab_4_1();
        }
        else if (task_number == 4.2)
        {
            lab_4_2();
        }
        else if (task_number == 5.1)
        {
            lab_5_1();
        }
     
    }
    return 0;
}