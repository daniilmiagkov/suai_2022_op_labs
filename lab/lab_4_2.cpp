#include <iostream>// ����������
#include <iomanip>
#include <Windows.h> // ����������
#include "various_functions.h"
#include "lab_4_2_functions.h"
#include "main_header.h"
#include "string"
#include "vector"
#include <set>
#include <iterator>

using namespace std; //����������� ������������ ���� std

void lab_4_2()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    srand(clock());

    // N = ���������� ����������� 
    // lS = ���������� ������� � �����������
    // lS_max = ������������ ���������� �������
    // M_max = ����� ������������ ���������� ��������������� �������
    // Z_max = ������

    Values value;

    unsigned short N = in_count_people();
    unsigned short lS_max = in_count_ckills();

    unsigned short Z_max = N * (lS_max * 10)  + rand() % 10;

    vector < pair < set <int>, int> > P(N);
    set <set<int>> sets_indexes;
    vector < pair < int, int> > skills_and_salaries;
    vector <int> indexes(P.size(), 0);

    fill_pair(P, N, lS_max, Z_max);
    unsigned short l_void = sqrt(N) + 1;
    cout << "������ = " << setw(l_void) << Z_max << endl;
    print_three_vector(P, lS_max);

    


    sochetaniya(0, P.size(), sets_indexes, indexes);
    calculation(sets_indexes, skills_and_salaries, P);
    if (value.debugging == 1)
        print_vector_pair(skills_and_salaries);
    
    cout << endl
         << "���-�� ����" << setw(l_void) << skills_and_salaries.size() << "; "
         << setw(l_void) << skills_and_salaries[find(skills_and_salaries, Z_max)].first
         << setw(l_void) << skills_and_salaries[find(skills_and_salaries, Z_max)].second;
}
