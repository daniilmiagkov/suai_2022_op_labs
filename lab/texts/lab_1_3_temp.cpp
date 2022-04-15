#include <iostream>// ����������
#include <Windows.h> // ����������
#include "various_functions.h"
#include "main_header.h"
#include <fstream>
#include <string>

int* search_for_an_array_of_residuals(int* array_A, int& length)
{
    int* array_of_residuals = new int[length * 3];
    int* array_of_non_repeating_residues = new int[length];
    int array_of_divisors[3] = { 2,3,5 };
    int length_array_dop_2 = 0;

    std::cout << std::endl;
    
    for (int i = 0; i < length * 3; i += 3)
    {
        std::cout << "����� = " << array_A[i / 3] << ";";
        for (int k = 0; k < 3; k++)
        {
            int temp = array_A[i / 3] % array_of_divisors[k];
            array_of_residuals[i + k] = temp;
            std::cout
                << " ������� �� ������� �� " << array_of_divisors[k]
                << " = " << temp << "; ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "������ ���� ��������: ";

    int l = 0;
    for (int i = 0; i < length * 3; i++)
    {
        int k = 0;

        for (int j = 0; j < length * 3; j++)
        {
            if (array_of_residuals[i] == array_of_residuals[j])
                k++;
        }

        if (k == 1)
        {
            
            std::cout << " !" << array_of_residuals[i] << "! ";
            array_of_non_repeating_residues[l] = array_of_residuals[i];
            l++;
        }
        else std::cout << array_of_residuals[i] << ", ";

    }
    std::cout << std::endl;
    length = l;
    return array_of_non_repeating_residues;
}

void lab_1_3_temp()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    
    int length;

    std::fstream file_input, file_output;

    file_input.open("D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_input_text.txt",
        std::ios::out);

    // ������ ������ � �������� ����
    if (file_input) {    // ��������� ������ �� ����
        std::cout << "������� ���������� ��������� ��������� �������" << std::endl;
        while (true)
        {
            length = get_number<int>();
            if (length >= 0)
            {
                file_input << length << std::endl;
                for (int i = 0; i < length; i++) //���� �������� ���������  
                {
                    std::cout << "������� " << i + 1 << " �����: ";
                    file_input << get_number<int>() << " "; // ���������� ����� � ����
                }
                break;
            }
            else std::cout
                << "���������� ��������� �� ����� ���� �������������, ������� ������������� �����: ";
        }
        file_input.close(); // �������� ����a
    }
    else // ���� ���� �� ������� �������, ����� ������ ������
        std::cout << "���� �� ��������!" << std::endl;



    file_input.open("D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_input_text.txt",
        std::ios::in);
    file_output.open("D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_output_text.txt",
        std::ios::out);
    
    
    // ���������� ������ �� ��������� �����
    if (file_input) {    // ��������� ������ �� ����
        if (file_output) {    // ��������� ������ �� ����
        
            int temp, i = 0, k = 0;
            file_input >> length;
            int* array_A = new int[length];
            int* array_B = new int[4]; 

            for (int i = 0; i < length; i ++)
            {
                file_input >> temp;
                array_A[i] = temp;
            }

            array_B = search_for_an_array_of_residuals(array_A, length);

            file_output << length << std::endl;
            for (int i = 0; i < length; i++) {
                file_output << array_B[i] << " "; // ���������� ����� � ����
            }

            file_input.close(); // �������� ����� 
            file_output.close(); // �������� �����

        }
        else // ���� ���� �� ������� �������, ����� ������ ������
            std::cout << "���� output �� ��������!" << std::endl;
    }
    else // ���� ���� �� ������� �������, ����� ������ ������
        std::cout << "���� input �� ��������!" << std::endl;
    
    
    
}