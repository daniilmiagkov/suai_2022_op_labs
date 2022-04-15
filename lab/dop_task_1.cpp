#include <iostream>// ����������
#include <iomanip>
#include <Windows.h> // ����������
#include "various_functions.h"
#include "main_header.h"
#include "dop_task_1_functions.h"
#include "string"
#include "vector"

void dop_task_1()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    srand(clock());

    unsigned short n = in_count_people();// n = ���������� ����������  

    vector < Characters > characters(n); // ������ ����������

    fill_vector(characters);
    print_max(n);
    print_table(characters);

    //������� ��� ���� �������
    char task = in_task();
    if (task == 'A')
    {
        cout << "���� 1x1" << endl;
        unsigned short character_number = in_character_number(n);//��������� ������ ����������
        Characters character_enemy = characters[character_number];//�������� ��������� ���������� 
        print_dash();//������ ����������������� ������
        print_line(character_enemy);//������ ������� ��������� ����������
        print_enter(1);//������� ������� 
        characters.erase(characters.begin() + character_number);//�������� �� ������� ��������� ����������
        print_table(characters);//������ ������� � ������ ������������ 

        string parametr = rang_my();//��������� ��������� 

        find_winner(characters, character_enemy);//���������� ������ �����������
        sort(characters, parametr);//���������� ������
        print_table(characters);//������ ������
    }
    else
    {
        cout << "���� 3�3" << endl;
        vector <Characters> enemy_team = in_team_enemy(characters);
        
        print_table(characters);

        
    }
    

    
}

