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

using namespace std;//подключение пространства имен 

int* fill_array(int N, int k);
void fill_file(int* array, int k, int length, string file_name);
//int* get_array(int &k, int&N);
//int* counting(int* A, int N, int& k);
int* calc(int& k);

void lab_1_3()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    int k = 0;
    //
    /*
    *
    srand(clock());
    int N = rand() % 10 + 10; //количество элементов исходного массива
    //cout << "Введите k: ";
    //k = check_input<int>();
    k = rand() % 10 + 10;

    //создание исходного массива
    int* A = fill_array(N, k);

    //заполнение исходного файла
    fill_file(A, k, N, "text_input");
    
    //
    //строки 26-36 создают случайные исходные данные и вводят их в файл "text_input", могут быть отключены для ручного ввода исх данных




    //создание выходного массива и заполнение его
    int* B = calc(k);

    //заполнение выходного файла
    fill_file(B, 0, k, "text_output");
}



void fill_file(int* array, int k, int length, string name)
{
    //создание имени файла
    string file_name = "D:\\lab_sale\\Vlad_Voronov\\texts\\" + name + ".txt";
    //создание переменной файла
    fstream file;

    file.open(file_name, ios::out); //открытие файла на запись в него
    if (name == "text_input") //если исходный файл, то запись в него k
    {
        file << k << endl;
    }
    if (file) // Проверяем открыт ли файл
    {
        file << length << std::endl; //запись длины

        for (int i = 0; i < length; i++) //Ввод исходных элементов  
        {
            file << array[i] << ","; // Записываем текст в файл
        }

        file.close(); //закрытие файла
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        cout << "Файл не открылся!" << endl;
}

int* fill_array(int N, int k)
{
    int* A = new int[N];//создание динамического массива
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % k;//заполнение элементов в диапазоне [0;k)
    }
    return A;
}

int* calc(int& k)
{
    //создание переменной файла
    fstream file_input;
    //открытие файла
    file_input.open("D:\\lab_sale\\Vlad_Voronov\\texts\\text_input.txt", ios::in); //открываем на считывание из файла 
    if (file_input) //если открылся
    {
        //считывание из него k и длины
        int N;
        file_input >> k;
        file_input >> N;

        k++;//так длина диапазона [0..9] это десять

        int* B = new int[k]; //создаем дин. массив В длиной k

        string s = {}; //пустая строка, чтобы потом из нее получать числа
        int number; //числа, которые мы получаем
        char ch; //символ, который считываем из файла

        for (int i = 0; i < k; i++) //заполнение нулями
        {
            B[i] = 0;
        }

        //считывание данных из файла
        while (file_input >> ch)
            //пытаемся считать символ из файла, если получается, то идем дальше
            //если не получается, то не идем
            //цикл работает пока можем считать символ.
            //также мы сразу же и присваиваем считанный символ в переменную ch
        {

            if (ch >= '0' && ch <= '9') //если число, то прибавляем к строке
            {
                s += ch;
            }
            if (ch == ',') //если , то добавляем в массив преобразованную строку
            {
                number = str_to_number<int>(s);
                for (int j = 0; j < k; j++) //проход по всему диапазону 
                {
                    if (number == j)
                        //если элемент исходного массива равен какому-то числу из диапазона, 
                        //то увеличиваем соответсвующий элемент в новом массиве
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
    else cout << "Файл не открылся";

}


/*
int* get_array(int &k, int& N)
{
    //создание переменной файла
    fstream file_input;
    //открытие файла
    file_input.open("D:\\lab op\\texts\\text_input.txt", ios::in);
    //считывание из него k и длины
    file_input >> k;
    file_input >> N;


    int* A = new int[N];
    string s = {};
    int m = 0;//индекс
    char ch;
    //считывание данных из файла
    while (!file_input.eof())
    {
        ch = file_input.get(); //считывание по одному символу из файла
        if (ch >= '0' && ch <= '9') //если число то прибавляем к строке
        {
            s += ch;
        }
        if (ch == ',') //если , то добавляем в массив преобразованную строку
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
    k++; //увеличиваем длину, чтобы захватить весь диапазон
    int* B = new int[k];
    for (int i = 0; i < k; i++) //заполнение нулями
    {
        B[i] = 0;
    }
    for (int i = 0; i < N; i++) //проход по всем элементам исходного массива
    {
        for (int j = 0; j < k; j++) //проход по всему диапазону
        {
            if (A[i] == j)
                //если элемент исходного массива равен какому-то числу из диапазона,
                //то увеличиваем соответсвующий элемент в новом массиве
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

//прототипы
template <typename T>
bool check(string str);

template <typename T>
T str_to_number(std::string str);

template <typename T>
T check_input();



//шаблон функции для проверки введенных координат
template <typename T>
T check_input()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        string str;
        cin >> str; //считывание строки до первого пробела
        if (check<T>(str) == 1) //проверка на число
        {
            return str_to_number<T>(str); //преобразование строки в число
        }
    }
}

template <typename T>
bool check(string str)
{
    bool k = 1;
    //проверка на возможность существования такого числа
    if ((str.find('-') < 1 || str.find('-') == -1) && ((str.find('.') < str.size() - 1 && str.find('.') > 0) || str.find('.') == -1))
    {
        //если длина больше 
        if (str.length() > 1)
        {
            //проверка на возможность существования такого числа
            //после нуля всегда точка или ничего, если ноль первый
            //после - если ноль, то должна быть точка или ничего 
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
                } //если у нас всего один символ то он не может быть точкой или минусом
            }
            if ((str[0] == '0' && str[1] != '.') || count_point > 1 ||
                (str[0] == '-' && str[1] == '.') ||
                (str[0] == '-' && str[1] == '0' && str[2] != '.') || count_minus > 1)
            {
                k *= 0;
                std::cout << "!!Вы ввели не число!!" << std::endl << "Введитe число: ";
            } //если 1й символ "0" и 2й не "." или число больше 1 или 1й симв "-" и второй "." или 1й симв "-" и 2й "0" и 3й не "." или число больше 1,
              //то программа выводит ошибку "Вы ввели не число" и просит снова Ввести число
        }
        else
            if (str == "-")
            {
                k *= 0;
                std::cout << "!!Вы ввели не число!!" << std::endl << "Введитe число: ";
            } //если строка состоит только из минуса, выводится ошибка
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
                        std::cout << "!!Вы ввели не число!!" << std::endl << "Введитe число: ";
                        break;
                    } //если в строке символ не от 0 до 9 и нет точки или минуса, то выводит ошибку (не пропускает буквы и прочие символы)
                }
            }
            if (s == "int")
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
                    {
                        k *= 0;
                        std::cout << "!!Вы ввели не число!!" << std::endl << "Введитe число: ";
                        break;
                    } //то же самое, что и выше, только для целочисленных
                }
            }
        }
    }
    else
    {
        k *= 0;
        std::cout << "!!Вы ввели не число!!" << std::endl << "Введитe число: ";
    } //если в итоге число не существует, выводится ошибка

    return k;
}

//проверка без вывода
template <typename T>
bool check_without_print(string str)
{
    bool k = 1;
    //проверка на возможность существования такого числа
    if ((str.find('-') < 1 || str.find('-') == -1) && ((str.find('.') < str.size() - 1 && str.find('.') > 0) || str.find('.') == -1))
    {
        //если длина больше 
        if (str.length() > 1)
        {
            //проверка на возможность существования такого числа
            //после нуля всегда точка или ничего, если ноль первый
            //после - если ноль, то должна быть точка или ничего 
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
                } //если у нас всего один символ то он не может быть точкой или минусом
            }
            if ((str[0] == '0' && str[1] != '.') || count_point > 1 ||
                (str[0] == '-' && str[1] == '.') ||
                (str[0] == '-' && str[1] == '0' && str[2] != '.') || count_minus > 1)
            {
                k *= 0;
            } //если 1й символ "0" и 2й не "." или число больше 1 или 1й симв "-" и второй "." или 1й симв "-" и 2й "0" и 3й не "." или число больше 1,
              //то программа выводит ошибку "Вы ввели не число" и просит снова Ввести число
        }
        else
            if (str == "-")
            {
                k *= 0;
            } //строка не может быть минусом
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
                    } //если в строке символ не от 0 до 9 и нет точки или минуса, то выводит ошибку (не пропускает буквы и прочие символы)
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
                    } //то же самое, что и выше, только для целочисленных
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

    int  k = 1; //коэфициент на который буде умножать число 
    if (str[0] == '-') //если первый элемент строки = -, то
    {
        k = -1; //k = -1
        str.erase(0, 1); //стираем 1 символ с индексом ноль.
    }

    int index = str.length(); //index равен длине строки str
    if (str.find('.') != -1)  //если нашли точку (индекс вхождения точки в строку str не равен -1)
    {
        index = str.find('.'); //index = индексу вхождения . в строку str
        str.erase(index, 1); // удаляем 1 символ с индексом index
    }

    int divider = pow(10, (str.length() - index)); // то, на что будем делить а, чтобы получить дробное десятичное число
    //число 100.54
    //точка имеет индекс 3
    //divider = 10 ^ (5 - 3) = 100
    //число а = 10054 / 100 = 100.54
    // 
    //число -5.643
    //k = -1, 5.643
    //точка имеет индекс 1
    //10 ^ (4 - 1) = 1000
    //a = -1 * 5643 / 1000 = -5.643
    // 
    //a = 10
    //10 ^ (2 - 2) = 1
    //a = 10 / 1 = 10
    //

    T a = 0; //само число
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