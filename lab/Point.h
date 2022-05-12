#pragma once
struct Point
{
	int x, y;
};
/*
#include <iostream>
#include <string>
#include "functions.h"
#include <iomanip>
#include <fstream>
#include <Windows.h> 
#include "main.h"

using namespace std;//����������� ������������ ���� 

int* fill_array(int N, int k);
void fill_file(int* array, int k, int length, string file_name);
//int* get_array(int &k, int&N);
//int* counting(int* A, int N, int& k);
int* calc(int& k);

void lab_1_3()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    int k = 0;
    //
    /*
    *
    srand(clock());
    int N = rand() % 10 + 10; //���������� ��������� ��������� �������
    //cout << "������� k: ";
    //k = check_input<int>();
    k = rand() % 10 + 10;

    //�������� ��������� �������
    int* A = fill_array(N, k);

    //���������� ��������� �����
    fill_file(A, k, N, "text_input");
    
    //
    //������ 26-36 ������� ��������� �������� ������ � ������ �� � ���� "text_input", ����� ���� ��������� ��� ������� ����� ��� ������




    //�������� ��������� ������� � ���������� ���
    int* B = calc(k);

    //���������� ��������� �����
    fill_file(B, 0, k, "text_output");
}



void fill_file(int* array, int k, int length, string name)
{
    //�������� ����� �����
    string file_name = "D:\\lab_sale\\Vlad_Voronov\\texts\\" + name + ".txt";
    //�������� ���������� �����
    fstream file;

    file.open(file_name, ios::out); //�������� ����� �� ������ � ����
    if (name == "text_input") //���� �������� ����, �� ������ � ���� k
    {
        file << k << endl;
    }
    if (file) // ��������� ������ �� ����
    {
        file << length << std::endl; //������ �����

        for (int i = 0; i < length; i++) //���� �������� ���������  
        {
            file << array[i] << ","; // ���������� ����� � ����
        }

        file.close(); //�������� �����
    }
    else // ���� ���� �� ������� �������, ����� ������ ������
        cout << "���� �� ��������!" << endl;
}

int* fill_array(int N, int k)
{
    int* A = new int[N];//�������� ������������� �������
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % k;//���������� ��������� � ��������� [0;k)
    }
    return A;
}

int* calc(int& k)
{
    //�������� ���������� �����
    fstream file_input;
    //�������� �����
    file_input.open("D:\\lab_sale\\Vlad_Voronov\\texts\\text_input.txt", ios::in); //��������� �� ���������� �� ����� 
    if (file_input) //���� ��������
    {
        //���������� �� ���� k � �����
        int N;
        file_input >> k;
        file_input >> N;

        k++;//��� ����� ��������� [0..9] ��� ������

        int* B = new int[k]; //������� ���. ������ � ������ k

        string s = {}; //������ ������, ����� ����� �� ��� �������� �����
        int number; //�����, ������� �� ��������
        char ch; //������, ������� ��������� �� �����

        for (int i = 0; i < k; i++) //���������� ������
        {
            B[i] = 0;
        }

        //���������� ������ �� �����
        while (file_input >> ch)
            //�������� ������� ������ �� �����, ���� ����������, �� ���� ������
            //���� �� ����������, �� �� ����
            //���� �������� ���� ����� ������� ������.
            //����� �� ����� �� � ����������� ��������� ������ � ���������� ch
        {

            if (ch >= '0' && ch <= '9') //���� �����, �� ���������� � ������
            {
                s += ch;
            }
            if (ch == ',') //���� , �� ��������� � ������ ��������������� ������
            {
                number = str_to_number<int>(s);
                for (int j = 0; j < k; j++) //������ �� ����� ��������� 
                {
                    if (number == j)
                        //���� ������� ��������� ������� ����� ������-�� ����� �� ���������, 
                        //�� ����������� �������������� ������� � ����� �������
                    {

                        B[j]++;

                    }
                }
                s = {};
            }
        }

        file_input.close();
        return B;
    }
    else cout << "���� �� ��������";

}


/*
int* get_array(int &k, int& N)
{
    //�������� ���������� �����
    fstream file_input;
    //�������� �����
    file_input.open("D:\\lab op\\texts\\text_input.txt", ios::in);
    //���������� �� ���� k � �����
    file_input >> k;
    file_input >> N;


    int* A = new int[N];
    string s = {};
    int m = 0;//������
    char ch;
    //���������� ������ �� �����
    while (!file_input.eof())
    {
        ch = file_input.get(); //���������� �� ������ ������� �� �����
        if (ch >= '0' && ch <= '9') //���� ����� �� ���������� � ������
        {
            s += ch;
        }
        if (ch == ',') //���� , �� ��������� � ������ ��������������� ������
        {
            A[m] = str_to_number<int>(s);
            s = {};
            m++;
        }
    }
    file_input.close();
    return A;
}

int* counting(int* A, int N, int& k)
{
    k++; //����������� �����, ����� ��������� ���� ��������
    int* B = new int[k];
    for (int i = 0; i < k; i++) //���������� ������
    {
        B[i] = 0;
    }
    for (int i = 0; i < N; i++) //������ �� ���� ��������� ��������� �������
    {
        for (int j = 0; j < k; j++) //������ �� ����� ���������
        {
            if (A[i] == j)
                //���� ������� ��������� ������� ����� ������-�� ����� �� ���������,
                //�� ����������� �������������� ������� � ����� �������
            {
                B[j]++;
            }
        }
    }
    return B;
}




#pragma once
#include <string>
#include <typeinfo>
using std::string;
using std::cout;
using std::cin;

void test();

//���������
template <typename T>
bool check(string str);

template <typename T>
T str_to_number(std::string str);

template <typename T>
T check_input();



//������ ������� ��� �������� ��������� ���������
template <typename T>
T check_input()
{
    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        string str;
        cin >> str; //���������� ������ �� ������� �������
        if (check<T>(str) == 1) //�������� �� �����
        {
            return str_to_number<T>(str); //�������������� ������ � �����
        }
    }
}

template <typename T>
bool check(string str)
{
    bool k = 1;
    //�������� �� ����������� ������������� ������ �����
    if ((str.find('-') < 1 || str.find('-') == -1) && ((str.find('.') < str.size() - 1 && str.find('.') > 0) || str.find('.') == -1))
    {
        //���� ����� ������ 
        if (str.length() > 1)
        {
            //�������� �� ����������� ������������� ������ �����
            //����� ���� ������ ����� ��� ������, ���� ���� ������
            //����� - ���� ����, �� ������ ���� ����� ��� ������ 
            int count_minus = 0, count_point = 0;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '-')
                {
                    count_minus++;
                }
                if (str[i] == '.')
                {
                    count_point++;
                } //���� � ��� ����� ���� ������ �� �� �� ����� ���� ������ ��� �������
            }
            if ((str[0] == '0' && str[1] != '.') || count_point > 1 ||
                (str[0] == '-' && str[1] == '.') ||
                (str[0] == '-' && str[1] == '0' && str[2] != '.') || count_minus > 1)
            {
                k *= 0;
                std::cout << "!!�� ����� �� �����!!" << std::endl << "������e �����: ";
            } //���� 1� ������ "0" � 2� �� "." ��� ����� ������ 1 ��� 1� ���� "-" � ������ "." ��� 1� ���� "-" � 2� "0" � 3� �� "." ��� ����� ������ 1,
              //�� ��������� ������� ������ "�� ����� �� �����" � ������ ����� ������ �����
        }
        else
            if (str == "-")
            {
                k *= 0;
                std::cout << "!!�� ����� �� �����!!" << std::endl << "������e �����: ";
            } //���� ������ ������� ������ �� ������, ��������� ������
        if (k == 1)
        {
            string s = typeid(T).name();
            if (s == "double")
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-')
                    {
                        k *= 0;
                        std::cout << "!!�� ����� �� �����!!" << std::endl << "������e �����: ";
                        break;
                    } //���� � ������ ������ �� �� 0 �� 9 � ��� ����� ��� ������, �� ������� ������ (�� ���������� ����� � ������ �������)
                }
            }
            if (s == "int")
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
                    {
                        k *= 0;
                        std::cout << "!!�� ����� �� �����!!" << std::endl << "������e �����: ";
                        break;
                    } //�� �� �����, ��� � ����, ������ ��� �������������
                }
            }
        }
    }
    else
    {
        k *= 0;
        std::cout << "!!�� ����� �� �����!!" << std::endl << "������e �����: ";
    } //���� � ����� ����� �� ����������, ��������� ������

    return k;
}

//�������� ��� ������
template <typename T>
bool check_without_print(string str)
{
    bool k = 1;
    //�������� �� ����������� ������������� ������ �����
    if ((str.find('-') < 1 || str.find('-') == -1) && ((str.find('.') < str.size() - 1 && str.find('.') > 0) || str.find('.') == -1))
    {
        //���� ����� ������ 
        if (str.length() > 1)
        {
            //�������� �� ����������� ������������� ������ �����
            //����� ���� ������ ����� ��� ������, ���� ���� ������
            //����� - ���� ����, �� ������ ���� ����� ��� ������ 
            int count_minus = 0, count_point = 0;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '-')
                {
                    count_minus++;
                }
                if (str[i] == '.')
                {
                    count_point++;
                } //���� � ��� ����� ���� ������ �� �� �� ����� ���� ������ ��� �������
            }
            if ((str[0] == '0' && str[1] != '.') || count_point > 1 ||
                (str[0] == '-' && str[1] == '.') ||
                (str[0] == '-' && str[1] == '0' && str[2] != '.') || count_minus > 1)
            {
                k *= 0;
            } //���� 1� ������ "0" � 2� �� "." ��� ����� ������ 1 ��� 1� ���� "-" � ������ "." ��� 1� ���� "-" � 2� "0" � 3� �� "." ��� ����� ������ 1,
              //�� ��������� ������� ������ "�� ����� �� �����" � ������ ����� ������ �����
        }
        else
            if (str == "-")
            {
                k *= 0;
            } //������ �� ����� ���� �������
        if (k == 1)
        {
            string s = typeid(T).name();
            if (s == "double")
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-')
                    {
                        k *= 0;
                        break;
                    } //���� � ������ ������ �� �� 0 �� 9 � ��� ����� ��� ������, �� ������� ������ (�� ���������� ����� � ������ �������)
                }
            }
            if (s == "int")
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
                    {
                        k *= 0;
                        break;
                    } //�� �� �����, ��� � ����, ������ ��� �������������
                }
            }
        }
    }
    else
    {
        k *= 0;
    }

    return k;
}

template <typename T>
T str_to_number(std::string str)
{

    int  k = 1; //���������� �� ������� ���� �������� ����� 
    if (str[0] == '-') //���� ������ ������� ������ = -, ��
    {
        k = -1; //k = -1
        str.erase(0, 1); //������� 1 ������ � �������� ����.
    }

    int index = str.length(); //index ����� ����� ������ str
    if (str.find('.') != -1)  //���� ����� ����� (������ ��������� ����� � ������ str �� ����� -1)
    {
        index = str.find('.'); //index = ������� ��������� . � ������ str
        str.erase(index, 1); // ������� 1 ������ � �������� index
    }

    int divider = pow(10, (str.length() - index)); // ��, �� ��� ����� ������ �, ����� �������� ������� ���������� �����
    //����� 100.54
    //����� ����� ������ 3
    //divider = 10 ^ (5 - 3) = 100
    //����� � = 10054 / 100 = 100.54
    // 
    //����� -5.643
    //k = -1, 5.643
    //����� ����� ������ 1
    //10 ^ (4 - 1) = 1000
    //a = -1 * 5643 / 1000 = -5.643
    // 
    //a = 10
    //10 ^ (2 - 2) = 1
    //a = 10 / 1 = 10
    //

    T a = 0; //���� �����
    for (int i = 0; i < str.length(); i++)
    {
        a = a * 10 + (str[i] - '0');
        //a = "10054"
        //a = 0 * 10 + '1' - '0' = 1
        //a = 1 * 10 + '0' - '0' = 10
        //a = 10 * 10 + '0' - '0' = 100
        //a = 100 * 10 + '5' - '0' = 1005
        //a = 1005 * 10 + '4' - '0' = 10054
        //
    }

    return k * (a / divider);
}
*/