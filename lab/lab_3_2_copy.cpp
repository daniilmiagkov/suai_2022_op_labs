/*#include <iostream>// ����������
#include <iomanip>
#include <Windows.h> // ����������
#include "various_functions.h"
#include "main_header.h"
#include "string"
#include "vector"
#include <set>
#include <iterator>

using namespace std; //����������� ������������ ���� std

void print_vector_of_vectors(vector <vector <Point>> array);
string print_Point(Point A);
void print_string_old(int call_count, int deep_level, vector<Point> memory);
void print_string_old(int deep_level, Point A);
bool in_memory_old(vector<Point> memory, Point A);
void print_route_old(vector<Point> memory);
bool find_route_old(vector <vector <Point>>& routes, int wight, int height, vector<Point> T, vector<Point> route, Point A, int count, int& call_count, vector<Point>& memory, int deep_level, vector<int>& levels, int& max_deep_level);

void lab_3_2_copy()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    int call_count = 0, deep_level = 0, max_deep_level = 0, height = 3, wight = 3;
    /*
    cout << "������� ������� ���� \n������� height: ";
    int height = get_number<int>();
    cout << "������� wight: ";
    int wight = get_number<int>();
    
    vector <Point> T, answer = {};

    /*for (int j = 0; j < 4; j++)
    {
        vector<int> tmp;
        for (int j = 0; j < 2; j++)
        {
            cout << "������� " << j << " ������� " << j << "�������� ������� T: ";
            tmp.push_back(get_number<int>());
        }
        T.push_back(tmp);
    }

    //T = { {2, 1},{-2, -1},{1, 2},{-1, -2} };
    //T = { {0, 1},{0, -1},{1, 0},{-1, 0} };
    T = { {0, 1}, {0, -1},{1,0} };
    //�������� ���� ��������
    vector <Point> memory = {};
    vector <int> levels = {};
    vector <vector <Point>> routes = {};
    Point A = { 1,1 };
    /*cout << "������� (Ax,Ay)\n������� A.x: ";
    A.x = get_number<int>();
    cout << "������� A.y: ";
    A.y = get_number<int>();
    

    int count = 0;
    int i = 0;
    cout
        << "\n���������� �������:| �������:| ��������:"
        << endl;
    find_route_old(routes, wight, height, T, answer, A, count, call_count, memory, deep_level, levels, max_deep_level);
    if (routes.size() != 0)
    {
        print_vector_of_vectors(routes);
    }
    else cout << "����������";

}

bool find_route_old(vector <vector <Point>>& routes, int wight, int height, vector<Point> T, vector<Point> route, Point A, int count, int& call_count, vector<Point>& memory, int deep_level, vector<int>& levels, int& max_deep_level)
{

    call_count++;
    deep_level++;
    //print_vector_of_vectors(route); 

    levels.push_back(deep_level - 1);//������ � ������ ������ ������� 

    route.push_back(A);//������ � ������ �������� ����� 
    memory.push_back(A);
    print_string_old(call_count, deep_level - 1, route);

    if (A.x < 1 || A.y < 1 || A.x > wight || A.y > height)
    {
        //levels.pop_back();
        //route.pop_back();
        cout << "\n����� �� �������. \n";
        return 0;
    }

    if (deep_level > max_deep_level)
    {
        max_deep_level = deep_level - 1;//���������� ������������ ������� 
    }

    if (in_memory_old(route, A))
    {
        //A.x -= T[j].x;
        //A.y -= T[j].y;
        cout << "\n��������� � ���� �� ���������� �����. \n";
        return 0;
    }

    if (wight * height == route.size())
    {
        cout << "\n����� ����!";

        return 1;
    }



    for (int i = 0; i < T.size(); i++)
    {

        A.x += T[i].x;
        A.y += T[i].y;

        if (find_route_old(routes, wight, height, T, route, A, count, call_count, memory, deep_level, levels, max_deep_level))
        {
            cout << "\n����:\n";

            route.push_back(A);
            print_route_old(route);
            routes.push_back(route);
            route.pop_back();

            if (i != T.size() - 1)

                cout << "���� ������:" << endl;
            //route.pop_back();
            //route.push_back(A);
            //break;

        }
        else
        {

            if (i < T.size() - 1)
            {
                cout << "���� �� ���������� ���: \n";
                //cout << "����� � ������� ���������:" << endl;
                print_string_old(call_count, deep_level - 1, route);
                cout << "\n���� �������:" << endl;
                print_route_old(route);

                cout << "���� ������:" << endl;
            }


        }

        //deep_level--;
        A.x -= T[i].x;
        A.y -= T[i].y;

    }
    cout << "����������� �������� ���������� ���� ��� ����� " << print_Point(A) << ".  \n\n";
    return 0;
}

void print_vector_of_vectors(vector <vector <Point>> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << "������� " << i + 1 << endl;
        for (int j = 0; j < array[i].size(); j++)
        {
            cout << j << ": " << print_Point(array[i][j]) << endl;
        }
        cout << endl;
    }
}

string print_Point(Point A)
{
    string S = number_to_str<int>(A.x) + ", " + number_to_str<int>(A.y);
    return S;
}

void print_string_old(int call_count, int deep_level, vector<Point> memory)
{
    cout
        << setw(19) << call_count << "|"
        << setw(9) << deep_level << "|"
        << setw(9) << print_Point(memory[deep_level]) << "|"
        << endl;
}

void print_string_old(int deep_level, Point A)
{
    cout
        << setw(20) << "|"
        << setw(9) << deep_level << "|"
        << setw(9) << print_Point(A) << "|"
        << endl;
}

bool in_memory_old(vector <Point> memory, Point A)
{
    bool m = 0;
    for (int i = 0; i < memory.size() - 1; i++)
    {
        if (memory[i].x == A.x && memory[i].y == A.y)
        {
            m = 1;
        }
    }
    return m;
}

void print_route_old(vector <Point> memory)
{
    for (int i = 0; i < memory.size(); i++)
    {
        print_string_old(i, memory[i]);
    }
    cout << endl;
}*/