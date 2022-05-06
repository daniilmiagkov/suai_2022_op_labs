#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include "string"
#include "vector"
#include <set>
#include <iterator>

using namespace std; //подключение пространства имен std

struct Point
{
    int x, y;
};

void print_vector(vector <Point> array);
string print_Point(Point A);
void print_string(vector<Point> memory, int call_count, vector<int> levels);
bool find_route(int last, int M, int N, vector<Point> T, vector<Point>& answer, Point A, Point last_A, int count, int& call_count, vector<Point> memory, int deep_level, vector<int> levels, int& max_deep_level);

void lab_3_2()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    int call_count = 0, deep_level = 0, max_deep_level = 0, N = 4, M = 4;
    /*
    cout << "Введите размеры поля \nВведите N: ";
    int N = get_number<int>();
    cout << "Введите M: ";
    int M = get_number<int>();
    */
    vector <Point> T, answer = {};
    
    /*for (int i = 0; i < 4; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < 2; j++)
        {
            cout << "Введите " << j << " элемент " << i << "элемента массива T: ";
            tmp.push_back(get_number<int>());
        }
        T.push_back(tmp);
    }*/

    T = { {2, 1},{-2, -1},{1, 2},{-1, -2} };
    //T = { {0, 1},{0, -1},{1, 0},{-1, 0} };

    //создание двух массивов
    vector <Point> memory = {};
    vector <int> levels = {};
    
    Point A = {1,1};
    Point last_A = {0,0};
    /*cout << "Введите (Ax,Ay)\nВведите A.x: ";
    A.x = get_number<int>();
    cout << "Введите A.y: ";
    A.y = get_number<int>();
    */

    int count = 0;
    int i = 0;
    cout
        << "\nКоличество вызовов:| Глубина:| Значение:"
        << endl;
    if (find_route(i, M, N, T, answer, A, last_A, count, call_count, memory, deep_level, levels, max_deep_level))
    {
        print_vector(answer);
    }
    else cout << "Невозможно";

}

bool find_route(int last, int M, int N, vector<Point> T, vector<Point>& answer, Point A, Point last_A, int count, int& call_count, vector<Point> memory, int deep_level, vector<int> levels, int& max_deep_level)
{
    
    call_count++;
    deep_level++;
    //print_vector(answer); 
    levels.push_back(deep_level);//запись в массив уровня глубины 
    memory.push_back(A);//запись в массив значения числа        
    print_string(memory, call_count, levels);

    if (A.x < 1 || A.y < 1 || A.x > M || A.y > N)
    {
        levels.pop_back();
        memory.pop_back();
        cout << "Вышли за границы, идем на предыдущий шаг" << endl;
        deep_level--;
        return 0;
    }

    if (deep_level > max_deep_level)
    {
        max_deep_level = deep_level;//нахождение максимальной глубины 
    }

    if (M * N == answer.size())
    {
        cout << "Нашли путь" << endl;

        return 1;
    }
    if (last_A.x == A.x && last_A.y == A.y)
    {
        //A.x -= T[i].x;
        //A.y -= T[i].y;
        cout << "Вернулись в предыдущую точку" << endl;

        deep_level--;
        return 0;
    }    
    if (memory.size() != 0)
    {
        last_A = memory[memory.size() - 2];
    }
    

    for (int i = 0; i < T.size(); i++)
    {            
        A.x += T[i].x;
        A.y += T[i].y;
        
        if (find_route(i, M, N, T,  answer, A,last_A, count, call_count, memory, deep_level, levels, max_deep_level))
        {   
            answer.push_back(A);
        }   

        A.x -= T[i].x;
        A.y -= T[i].y;

    }
}

void print_vector(vector <Point> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << i << ": " << print_Point(array[i]) << endl;
    }
    cout << endl;
}

string print_Point(Point A)
{
    string S = number_to_str<int>(A.x) + ", " + number_to_str<int>(A.y);
    return S;
}

void print_string(vector<Point> memory, int call_count, vector<int> levels)
{
    cout
            << setw(19) << call_count << "|"
            << setw(9) << levels[call_count - 1] << "|"
            << setw(9) << print_Point(memory[call_count - 1]) << "|"
            << endl;
}