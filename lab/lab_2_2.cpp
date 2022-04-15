#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> 
#include "various_functions.h"
#include "main_header.h"
#include <vector>
#include "string"

using namespace std;

int binary_find(int key, vector<vector<int>>& array, int left, int right);
void sorting_bubble_two_dimensional_vectors(vector<vector<int>>& array);
void in_vector(vector <string>& As);
void fill_Hs(vector<vector<int>>& Hs, vector<string> As);
void print_Hs(vector<vector<int>>& Hs);
int input_P();
int input_M();
string input_Is();
int input_value(int a);


void lab_2_2()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    vector <string> As;
    in_vector(As);

    string Is = input_Is();
    As.push_back(Is);
    
    vector <vector <int>> Hs(As.size(), vector <int> (2));

    fill_Hs(Hs, As);

    int hash_Is = Hs[Hs.size() - 1][0];
    cout << "Hash Is: " << hash_Is << endl;
    Hs.erase(Hs.begin() + Hs.size() - 1);

    print_Hs(Hs);

    sorting_bubble_two_dimensional_vectors(Hs);

    cout << "Ias: " << binary_find(hash_Is, Hs, 0, Hs.size() - 1);

}

void sorting_bubble_two_dimensional_vectors(vector<vector<int>>& Hs)
{
    for (int i = 0; i < Hs.size(); i++)
        for (int j = 0; j < Hs.size() - 1; j++)
            if (Hs[j] > Hs[j + 1])
                swap_notstd(Hs[j], Hs[j + 1]);
}

string input_Is()
{
    cout << "Введите строку Is: ";
    string Is;
    getline(cin, Is);
    //cin.ignore(1, '\n');
    return Is;
}

void print_Hs(vector<vector<int>>& Hs)
{
    cout << "Hs: \n";
    for (int i = 0; i < Hs.size(); i++)
        cout << setw(2) << i << ": " << Hs[i][0] << endl;
}

int input_P()
{
    cout << "Введите P: ";
    return input_value(10);
}

int input_M()
{
    cout << "Введите M: ";
    return input_value(10001);
}

void in_vector(vector <string>& As)
{
    srand(clock());
    cout << "Введите длину массива: ";
    int N;
    string str;
    getline(cin, str);
    if (str == "")
    {
        N = rand() % 10 + 10;
    }
    else
    {
        while (true)
        {
            N = str_to_number<double>(str);
            if (N < 10)
            {
                cout << "Количество должно быть больше 10, введите другую длину: ";
                getline(cin, str);
            }
            else 
            {
                N = get_number_int_without_input(str);
                break;
            }
        }
    }

    cout << "Длина массива = " << N << endl;
    int size_str;
    for (int i = 0; i < N; i++)
    {
        size_str = rand() % 5 + 10;
        str = "";
        for (int j = 0; j < size_str; j++)
        {
            str += rand() % (10) + 'A';
        }
        cout << setw(2) << i << ": " << str << endl;
        As.push_back(str);

    }
}



void fill_Hs(vector<vector<int>>& Hs, vector<string> As)
{
    unsigned long long H = 0;
    int P = input_P();
    //cout << "Введите P: ";
    //int P = get_number_int();
    int M = input_M();
    //cout << "Введите M: ";
    //int M = get_number_int();
    for (int i = 0; i < Hs.size(); i++)
    {
        for (int j = 0; j < As[i].length(); j++)
        {
            H += (As[i][j] - 'A') * pow(P, j);
        }
        Hs[i][0] = H % M;
        Hs[i][1] = i;
        H = 0;
    }
}

int binary_find(int key, vector<vector<int>>& array, int left, int right)
{
    int mid = (left + right) / 2; 

    if (key == array[mid][0])
    {
        return array[mid][1];
    }
    else if (left > right)
    {
        return -1;
    }
    else if (key > array[mid][0])
    {
        left = mid + 1;
        return binary_find(key, array, left, right);
    }
    else
    {
        right = mid - 1;
        return binary_find(key, array, left, right);
    }
}

 