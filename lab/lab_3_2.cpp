#include <iostream>// ����������
#include <iomanip>
#include <Windows.h> // ����������
#include "various_functions.h"
#include "main_header.h"
#include "string"
#include "vector"
#include <set>
#include <iterator>

using namespace std; //����������� ������������ ���� std

struct Point
{
    int x, y;
};

int find(vector<Point> P, Point A, int count, int& call_count, vector<int> memory, int deep_level, vector<int> levels, int& max_deep_level);

void lab_3_2()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)


    cout << "������� ������� ���� \n������� N: ";
    int N = get_number<int>();
    cout << "������� M: ";
    int M = get_number<int>();
    int call_count = 0, deep_level = 0, max_deep_level = 0;

    vector <Point> T;
    
    /*for (int i = 0; i < 4; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < 2; j++)
        {
            cout << "������� " << j << " ������� " << i << "�������� ������� T: ";
            tmp.push_back(get_number<int>());
        }
        T.push_back(tmp);
    }*/

    T = { {2, 1},{-2, -1},{1, 2},{-1, -2} };

    //�������� ���� ��������
    vector <int> memory = {};
    vector <int> levels = {};

    cout << "������� (Ax,Ay): ";
    Point A;
    A.x = get_number<int>();
    A.y = get_number<int>();


}

int find(vector<Point> P, Point A, int count, int& call_count, vector<int> memory, int deep_level, vector<int> levels, int& max_deep_level)
{
    /*if (A.x < 0 || A.y < 0 || A.x >= WIDTH || A.y >= HIGHT)
        return false;
    if (B[x][y]) return false;
    B[x][y] = ++C;
    if (C == WIDTH * HIGHT) return true;

    if (KnM(B, C, A.x, A.y)) return true;
    
    B[x][y] = 0;
    */return false;
}
