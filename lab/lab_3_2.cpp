#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "main_header.h"
#include "string"
#include "vector"
#include "Point.h"

using namespace std; //подключение пространства имен std

struct Values
{
    bool p_o_n_p_intermediate_values = 0,
        print_or_not_print_find_array = 1,
        p_o_n_p_final_values = 1;

};
struct Routes
{
    vector <Point> route;
    vector <Point> step;
};

void print_vector_of_vectors(int height, int width, vector <Routes> array, bool print_table_route, bool print_on_place, int speed);
string Point_to_string(Point A);


void print_string(int call_count, int deep_level, vector<Point> memory);
void print_vector_of_step(vector<Point> T);
void print_string(int deep_level, Point A);
bool in_route(vector<Point> memory, Point A);
void print_area(int height, int  width, vector <Point> route, int size);
void print_route(vector<Point> memory);
vector<vector<Point>> fill_variants();
void rec_fill_variants(int last, int m, vector<int> indexes, vector<vector<Point>>& variants, vector<Point> T);
bool find_route(Point step, vector <Routes>& routes, int width, int height, vector<Point> T, Routes route, Point A, int count, int& call_count, vector<Point>& memory, int deep_level, vector<int>& levels, int& max_deep_level);

void lab_3_2()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    Values values;

    int call_count = 0, deep_level = 0, max_deep_level = 0, height = 2, width = 3, count = 0;
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
    T = { {0, 1},{0, -1},{1, 0},{-1, 0} };
   // T = { {0, 1}, {0, -1},{-1, 0},{2, 1} };

        
    /*cout << "Введите (Ax,Ay)\nВведите A.x: ";
        A.x = get_number<int>();
        cout << "Введите A.x: ";
        A.x = get_number<int>();
        */
    Point A = { 1,1 };
    /*for (int i = 0; i < 4; i++)
    {
        Point tmp;
        
        cout << "Введите x " << i << " элемента массива T: ";
        tmp.x = (get_number<int>());
        cout << "Введите y " << i << " элемента массива T: ";
        tmp.y = (get_number<int>());
        T.push_back(tmp);
    }
    */

    route.route.push_back(A);
    print_area(height, width, route.route, route.route.size());
    route.route.pop_back();

    
    cout << "Поиск массивов ходов (1) или проверка работы (0): ";
    bool task;
    task = get_number < bool>();
    //task = 1;
    if (task == 0)
    {
        cout << "Массив ходов: " << endl;
        print_vector_of_step(T);
        if (values.p_o_n_p_intermediate_values == 1)
            cout << "\nКоличество вызовов:| Глубина:| Значение:\n";
        find_route({}, routes, width, height, T, route, A, count, call_count, memory, deep_level, levels, max_deep_level);
        if (routes.size() != 0)
        {
            cout << "Найдены маршруты! Количество: " << routes.size() << endl;

            if (values.p_o_n_p_final_values == 1)
            {
                cout << "Печатать (1) или не печатать (0) путь графически: ";
                bool print_table_route, print_on_place = 0;
                int speed = 36;
                print_table_route = get_number < bool>();
                if (print_table_route)
                {
                    cout << "Печатать на одном месте (1) или нет (0): ";
                    print_on_place = get_number < bool>();
                    if (print_on_place)
                    {
                        
                        cout << "Введите скорость печатания (от 30 до 50 или другую) или нажмите пробел: ";
                        speed = input_value<int>(36);
                    }
                }
                cout << endl;
                print_vector_of_vectors(height, width, routes, print_table_route, print_on_place, speed);
            }
        }
        else 
           cout << "Невозможно" << endl;
    }
    else
    {
        cout << "Условие: ходы в диапазоне [-2;2], размер массива [1;4]\n";
        vector<vector<Point>> variants = fill_variants();
        int j = 1;

        cout << "Печатать (1) или не печатать (0) путь графически: ";
        bool print_table_route, print_on_place = 0;
        print_table_route = get_number < bool>();
        int speed = 36;
        if (print_table_route)
        {
            cout << "Печатать на одном месте (1) или нет (0): ";
            print_on_place = get_number < bool>();
            if (print_on_place)
            {

                cout << "Введите скорость печатания (от 30 до 50 или другую) или нажмите пробел: ";
                speed = input_value<int>(36);
            }
        }
        //bool routes_find = 0;
        cout << endl;
        for (int i = 0; i < variants.size(); i++)
        {
            T = variants[i];
            routes = {};
            levels = {};
            memory = {};
            route = {};
            

            find_route({}, routes, width, height, T, route, A, count, call_count, memory, deep_level, levels, max_deep_level);
            if (routes.size() != 0)
            {
                //routes_find = 1;
                if (values.print_or_not_print_find_array == 1)
                {
                    cout << "Массив ходов: " << endl;
                    print_vector_of_step(T);
                    print_vector_of_vectors(height, width, routes, print_table_route, print_on_place, speed);

                }
            }
        }
        //if (routes_find == 0)
        //    cout << "Таких массивов нет" << endl;

    }
    

}

bool find_route(Point step, vector <Routes>& routes, int width, int height, vector<Point> T, Routes route, Point A,  int count, int& call_count, vector<Point>& memory, int deep_level, vector<int>& levels, int& max_deep_level)
{
    Values values;
    //values.print_or_not_print = 1;
    call_count++;
    deep_level++;
    //print_vector_of_vectors(route); 

    levels.push_back(deep_level - 1);//запись в массив уровня глубины 
    route.step.push_back(step);
    route.route.push_back(A);//запись в массив значения числа 
    //запись в массив значения числа 
    memory.push_back(A);

    if (values.p_o_n_p_intermediate_values == 1)
        print_string(call_count, deep_level - 1, route.route);

    if (A.x < 1 || A.y < 1 || A.x > width || A.y > height)
    {
        //levels.pop_back();
        //route.pop_back();
        if (values.p_o_n_p_intermediate_values == 1)
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
        if (values.p_o_n_p_intermediate_values == 1)
            cout << "\nВернулись в одну из предыдущих точек. \n";
        return 0;
    }

    if (width * height == route.route.size())
    {
        if (values.p_o_n_p_intermediate_values == 1)
            cout << "\nНашли путь!";

        return 1;
    }



    for (int i = 0; i < T.size(); i++)
    {

        A.x += T[i].x;
        A.y += T[i].y;
        
        if (find_route(T[i], routes, width, height, T, route, A, count, call_count, memory, deep_level, levels, max_deep_level))
        {
            route.route.push_back(A);
            route.step.push_back(step);//запись в массив значения числа 
            if (values.p_o_n_p_intermediate_values == 1)
            {
                cout << "\nПуть:\n";
                print_route(route.route);


            }
            routes.push_back(route);
            route.route.pop_back();
            route.step.pop_back();
            if (i != T.size() - 1)
                if (values.p_o_n_p_intermediate_values == 1)
                {
                    cout << "Идем на предыдущий шаг: \n";
                    //cout << "Точка в которую вернулись:" << endl;
                    print_string(call_count, deep_level - 1, route.route);
                    cout << "Идем дальше:" << endl;

                }
            

        }
        else
        {

            if (i < T.size() - 1)
            {
                if (values.p_o_n_p_intermediate_values == 1)
                {
                    if (route.route.size() > 0)
                        cout << "Идем в предыдущую точку " << Point_to_string(route.route[route.route.size() - 1]) << ".  \n";

                    cout << "Весь маршрут:" << endl;
                    print_route(route.route);
                    print_area(height, width, route.route, route.route.size());


                    cout << "Идем дальше:" << endl;
                }
            }


        }

        //deep_level--;
        A.x -= T[i].x;
        A.y -= T[i].y;

    }
    if (values.p_o_n_p_intermediate_values == 1)
    {
        cout << "Закончились варианты следующего шага для точки " << Point_to_string(A) << ".  \n";
        //if (route.route.size() > 1)
        //    cout << "Идем в предыдущую точку " << Point_to_string(route.route[route.route.size() - 2]) << ".  \n\n";
    }

    return 0;
}

void print_area(int height,int  width, vector <Point> route, int size)
{
    vector <vector <char>> P(height * 2 + 3);
    P[0].push_back(' ');
    P[0].push_back('|');
    for (int j = 0; j < width; j++)
    {
        P[0].push_back(number_to_str(j + 1)[0]);
        P[0].push_back('|');
    }
    for (int j = 0; j < width * 2 + 2; j++)
    {
        P[1].push_back('-');
    }
    for (int i = 2; i < height * 2 + 2; i++)
    {            
        P[i].push_back(number_to_str((i)/2)[0]);

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


    for (int i = 0; i < size; i++)
    {
        if (route[i].x > 0 && route[i].y > 0)
        {
            P[route[i].y * 2][route[i].x * 2] = '.';
        }
    }
    

    for (int i = P.size() - 1; i > -1; i--)
    {
        for (int j = 0; j < P[i].size(); j++)
        {
            cout << P[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void print_vector_of_vectors(int height, int width, vector <Routes> array, bool print_table_route, bool print_on_place, int speed)
{
    
    for (int i = 0; i < array.size(); i++)
    {
        for (int k = i + 1; k < array.size(); k++)
        {
            int s = 0;
            if (array[i].route[0].x != -1 &&
                array[i].route[0].y != -1)
            {
                for (int m = 0; m < array[i].route.size(); m++)
                {
                    if (array[i].route[m].x == array[i].route[m].x && array[i].route[m].y == array[i].route[m].y)
                        s++;
                    else break;
                }
                if (s < array[i].route.size())
                {
                    array[k].route[0].x = -1;
                    array[k].route[0].y = -1;
                }
            }
        }
    }
    //{4,6,3,6,7}
    //{4,6,3,-1,7}
    for (int i = 0; i < array.size(); i++)
    {
        
        if (array[i].route[0].x != -1 &&
            array[i].route[0].y != -1)
        {
            cout << "Маршрут " << i + 1 << endl;
            if (print_table_route)
            {
                
                if (print_on_place)
                {
                    //cout << endl << "Исходная точка:" << endl;
                    //cout << setw(3) << 0 << ": point: " << setw(6) << Point_to_string(array[i].route[0]) << "|     step:" << setw(8) << Point_to_string(array[i].step[0]) << endl;
                    //print_area(height, width, array[i].route, 1);
                    for (int j = 0; j < array[i].route.size(); j++)
                    {

                        Point A = cursor_position();
                        cout << setw(3) << j << ": point: " << setw(6) << Point_to_string(array[i].route[j]) << "|     step:" << setw(8) << Point_to_string(array[i].step[j]) << endl;
                        print_area(height, width, array[i].route, j + 1);
                        for (int k = 0; k < 10000000; k += 3)
                        {
                            k -= 2;
                            for (int l = 0; l < speed; l += 3)
                            {
                                l -= 2;
                            }
                        }
                        erase_past_output(A);

                    }

                }
                else
                {
                    cout << setw(3) << 0 << ": point: " << setw(6) << Point_to_string(array[i].route[0]) << "|     step:" << setw(8) << Point_to_string(array[i].step[0]) << endl;
                    print_area(height, width, array[i].route, 1);
                    for (int j = 1; j < array[i].route.size(); j++)
                    {

                        cout << setw(3) << j << ": point: " << setw(6) << Point_to_string(array[i].route[j]) << "|     step:" << setw(8) << Point_to_string(array[i].step[j]) << endl;
                        print_area(height, width, array[i].route, j + 1);
                        

                    }
                }
            }

                for (int j = 0; j < array[i].route.size(); j++)
                {

                    cout << setw(3) << j << ": point: " << setw(6) << Point_to_string(array[i].route[j]) << "|     step:" << setw(8) << Point_to_string(array[i].step[j]) << endl;
                }
                cout << endl;
            
            /*cout << "Весь маршрут: " << endl;
            for (int j = 0; j < array[i].route.size(); j++)
            {
            cout << endl;*/
        }
        
    }

}


//12345
// 
//
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

void print_vector_of_step(vector<Point> T)
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

bool in_T(vector <Point> T)
{
    bool m = 0;
    for (int i = 0; i < T.size(); i++)
    {
        for (int j = i; j < T.size(); j++)
        {
            if (T[j].x == T[i].x && T[j].y == T[i].y)
            {
                m = 1;
                break;
            }
            if (m)
                break;
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

    //for (int size = 1; size <= 4; size++)
    //{
    vector <int> indexes = {};
    for (int i = 1; i <= 4; i++)
    {
        indexes = {};
        rec_fill_variants(0, i, indexes, variants, T);
    }

    return variants;
}

void rec_fill_variants(int last, int m, vector<int> indexes, vector<vector<Point>>& variants, vector<Point> T)
{
    /*
    /*if (variants.size() == 649)
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
            /*if (P.size() == size)
            {
                
            }
            
            variants.push_back(P);
            P.pop_back();
        }
    }*/
    if (indexes.size() == m)
    {
        vector<Point> P = {};
        for (int index = 0; index < indexes.size(); index++)
        {
            //cout << indexes[index];
            P.push_back(T[indexes[index]]);
        }
        variants.push_back(P);
        return;
        //cout << endl;
    }
    for (int index = last + 1; index <= T.size(); index++)
    {
        indexes.push_back(index - 1);
        rec_fill_variants(index, m, indexes, variants, T);
        indexes.pop_back();
    }
}