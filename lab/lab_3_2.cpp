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
struct Values
{
    bool print_or_not_print = 1, print_or_not_print_find_array = 1;
};
struct Routes
{
    vector <Point> route;
    vector <Point> step;
};
void print_vector_of_vectors(vector <Routes> array);
string Point_to_string(Point A);
void print_string(int call_count, int deep_level, vector<Point> memory);
void print_vector_of_point(vector<Point> T);
void print_string(int deep_level, Point A);
bool in_route(vector<Point> memory, Point A);
void print_area(int height, int  width, Point A);
void print_route(vector<Point> memory);
vector<vector<Point>> fill_variants();
void rec_fill_variants(int i, vector<vector<Point>>& variants, vector<Point> T, int size, vector<Point>& P);
bool find_route(vector <Routes>& routes, int wight, int height, vector<Point> T, Routes route, Point A, int count, int& call_count, vector<Point>& memory, int deep_level, vector<int>& levels, int& max_deep_level);

void lab_3_2()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    Values values;

    int call_count = 0, deep_level = 0, max_deep_level = 0, height = 4, width = 1, count = 0;
    /*
    cout << "Введите размеры поля \nВведите height: ";
    int height = get_number<int>();
    cout << "Введите width: ";
    int width = get_number<int>();
    */
    vector <Point> T, memory = {};
    Routes route = {};
    vector <int> levels = {};
    vector <Routes> routes = {};
    //T = { {2, 1},{-2, -1},{1, 2},{-1, -2} };
        //T = { {0, 1},{0, -1},{1, 0},{-1, 0} };
    T = { {0, 1}, {0, -1},{1,0} };


        
    /*cout << "Введите (Ax,Ay)\nВведите A.x: ";
        A.x = get_number<int>();
        cout << "Введите A.x: ";
        A.x = get_number<int>();
        */
    Point A = { 1,1 };
    /*for (int y = 0; y < 4; y++)
    {
        vector<int> tmp;
        for (int y = 0; y < 2; y++)
        {
            cout << "Введите " << y << " элемент " << y << "элемента массива T: ";
            tmp.push_back(get_number<int>());
        }
        T.push_back(tmp);
    }*/
    print_area(height, width, A);
    cout << "Поиск массивов ходов (1) или проверка работы (0): ";
    bool task;
    task = get_number < bool>();
    //task = 1;
    if (task == 0)
    {
        


        

        if (values.print_or_not_print == 1)
            cout << "\nКоличество вызовов:| Глубина:| Значение:\n";
        find_route(routes, width, height, T, route, A, count, call_count, memory, deep_level, levels, max_deep_level);
        if (routes.size() != 0)
        {
            if (values.print_or_not_print == 1)
                print_vector_of_vectors(routes);
        }
        else 
            if (values.print_or_not_print == 1)
                cout << "Невозможно";
    }
    else
    {
        cout << "Условие: ходы в диапазоне [-2;2], размер массива [1;4]\n";
        vector<vector<Point>> variants = fill_variants();
        int j = 1;
        for (int i = 0; i < variants.size(); i++)
        {
            T = variants[i];
            routes = {};
            levels = {};
            memory = {};
            route = {};
            

            find_route(routes, width, height, T, route, A, count, call_count, memory, deep_level, levels, max_deep_level);
            if (routes.size() != 0)
            {
                if (values.print_or_not_print_find_array == 1)
                {
                    cout << "Массив ходов: " << endl;
                    print_vector_of_point(T);
                    print_vector_of_vectors(routes);

                }
            }
            

        }
    }
    

}

void print_area(int height,int  width, Point A)
{
    vector <vector <char>> P(height * 2 + 3);
    P[0].push_back(' ');
    P[0].push_back('|');
    for (int j = 0; j < width; j++)
    {
        P[0].push_back(number_to_str(j)[0]);
        P[0].push_back('|');
    }
    for (int j = 0; j < width * 2 + 2; j++)
    {
        P[1].push_back('-');
    }
    for (int i = 2; i < height * 2 + 2; i++)
    {            
        P[i].push_back(number_to_str((i - 1)/2)[0]);

        P[i].push_back('|');
        for (int j = 0; j < width; j++)
        {
            P[i].push_back(' ');
            P[i].push_back('|');
        }
        i++;
        for (int j = 0; j < width * 2 + 2; j++)
        {
            P[i].push_back('-');
        }

    }
    if (A.x > 0 && A.y > 0)
    {
        P[A.y + 1][A.x + 1] = '.';
    }
    for (int i = 0; i < P.size(); i++)
    {
        for (int j = 0; j < P[i].size(); j++)
        {
            cout << P[i][j];
        }
        cout << endl;
    }
}


bool find_route(vector <Routes>& routes, int width, int height, vector<Point> T, Routes route, Point A,  int count, int& call_count, vector<Point>& memory, int deep_level, vector<int>& levels, int& max_deep_level)
{
    Values values;
    values.print_or_not_print = 0;
    call_count++;
    deep_level++;
    //print_vector_of_vectors(route); 

    levels.push_back(deep_level - 1);//запись в массив уровня глубины 

    route.route.push_back(A);//запись в массив значения числа 
    //запись в массив значения числа 
    memory.push_back(A);
    if (values.print_or_not_print == 1)
        print_string(call_count, deep_level - 1, route.route);

    if (A.x < 1 || A.y < 1 || A.x > width || A.y > height)
    {
        //levels.pop_back();
        //route.pop_back();
        if (values.print_or_not_print == 1)
            cout << "\nВышли за границы. \n";
        return 0;
    }

    if (deep_level > max_deep_level)
    {
        max_deep_level = deep_level - 1;//нахождение максимальной глубины 
    }

    if (in_route(route.route, A))
    {
        //A.x -= T[y].x;
        //A.x -= T[y].x;
        if (values.print_or_not_print == 1)
            cout << "\nВернулись в одну из предыдущих точек. \n";
        return 0;
    }

    if (width * height == route.route.size())
    {
        if (values.print_or_not_print == 1)
            cout << "\nНашли путь!";

        return 1;
    }



    for (int i = 0; i < T.size(); i++)
    {

        A.x += T[i].x;
        A.y += T[i].y;
        route.step.push_back(T[i]);
        if (find_route(routes, width, height, T, route, A, count, call_count, memory, deep_level, levels, max_deep_level))
        {
            

            route.route.push_back(A);
            route.step.push_back(T[i]);//запись в массив значения числа 
            if (values.print_or_not_print == 1)
            {
                cout << "\nПуть:\n";
                print_route(route.route);
            }
            routes.push_back(route);
            
            route.route.pop_back();
            route.step.pop_back();
            if (i != T.size() - 1)
                if (values.print_or_not_print == 1)
                {
                    cout << "Идем на предыдущий шаг: \n";
                    //cout << "Точка в которую вернулись:" << endl;
                    print_string(call_count, deep_level - 1, route.route);
                    cout << "Идем дальше:" << endl;

                }
            //route.pop_back();
            //route.push_back(A);
            //break;

        }
        else
        {

            if (i < T.size() - 1)
            {
                if (values.print_or_not_print == 1)
                {
                    
                    cout << "\nВесь маршрут:" << endl;
                    print_route(route.route);

                    cout << "Идем дальше:" << endl;
                }
            }


        }

        //deep_level--;
        A.x -= T[i].x;
        A.y -= T[i].y;

    }
    if (values.print_or_not_print == 1)
        cout << "Закончились варианты следующего пути для точки " << Point_to_string(A) << ".  \n\n";
    return 0;
}

void print_vector_of_vectors(vector <Routes> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        int unique = 1;
        for (int k = i + 1; k < array.size(); k++)
        {
            int m = 0;
            while (array[i].route.size() != m && array[k].route.size() != m)
            {
                if (array[i].route[m].x == array[i].route[m].x && array[i].route[m].y == array[i].route[m].y)
                    unique++;
                m++;
            }
            
        }
        if (unique == 1)
        {
            cout << "Маршрут " << i + 1 << endl;
            for (int j = 0; j < array[i].route.size(); j++)
            {
                cout << j << ": point: " << setw(6) << Point_to_string(array[i].route[j]) << "|     step:" << setw(6) << Point_to_string(array[i].step[j]) << endl;
            }
            cout << endl;
        }
        
    }
}

string Point_to_string(Point A)
{
    string S = number_to_str<int>(A.x) + ", " + number_to_str<int>(A.y);
    return S;
}

void print_string(int call_count, int deep_level, vector<Point> memory)
{
    cout
        << setw(19) << call_count << "|"
        << setw(9) << deep_level << "|"
        << setw(9) << Point_to_string(memory[deep_level]) << "|"
        << endl;
}

void print_vector_of_point(vector<Point> T)
{
    cout << "{";
    for (int i = 0; i < T.size(); i++)
    {
        cout << "{" << Point_to_string(T[i]) << "}";
        if (i != T.size() - 1)
        {
            cout << ',';
        }
    }
    cout << "}" << endl;

}

void print_string(int deep_level, Point A)
{
    cout
        << setw(20) << "|"
        << setw(9) << deep_level << "|"
        << setw(9) << Point_to_string(A) << "|"
        << endl;
}

bool in_route(vector <Point> memory, Point A)
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

void print_route(vector <Point> memory)
{
    for (int i = 0; i < memory.size(); i++)
    {
        print_string(i, memory[i]);
    }
    cout << endl;
}

vector<vector<Point>>  fill_variants()
{
    vector<vector<Point>> variants;

    vector<Point> T;
    for (int x = -2; x <= 2; x++)
    {
        for (int y = -2; y <= 2; y++)
        {
            T.push_back({ x, y });       
        }
    }        
    vector<Point> P = {};

    for (int size = 1; size <= 4; size++)
    {
        rec_fill_variants(0, variants, T, size, P);
    }

    return variants;
}

void rec_fill_variants(int i, vector<vector<Point>>& variants, vector<Point> T, int size, vector <Point>& P)
{
    if (variants.size() == 649)
    {
        cout << endl;
    }
    if (P.size() == size)
    {
        return;
    }
    else
    {
        for (int i = 0; i < T.size(); i++)
        {
            P.push_back(T[i]);
            rec_fill_variants(i, variants, T, size, P);
            if (P.size() == size)
            {
                variants.push_back(P);
            }
            P.pop_back();
        }
    }
}