#include <iostream>// библиотека
#include <iomanip>
#include <Windows.h> // библиотека
#include "various_functions.h"
#include "lab_4_1_func.h"
#include "string"
#include "vector"


using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::setw;
using std::make_pair;
using std::endl;
using std::fixed;
using std::setprecision; //подключение пространства имен std

int find_time(unsigned int n, unsigned int size)
{
    int start_time, end_time, time = 0;
    Values value;
    for (int h = 0; h < n; h++)
    {
        srand(clock());
        unsigned int N, P;

        if (size == 0)
        {
            N = rand() % 5 + 2;
        }
        else N = size;
        if (size == 100)
        {
            N = rand() % 5 + 2;
        }
        P = N + 1;

        vector <vector <long long>> matrix(N, vector<long long>(P, 0));
        vector <double> matrix_x(N);
        fill(matrix);

        if (value.debugging == 0)
        {
            cout << "исходная матрица:" << endl;
            print_vector_two_dimensional_4_1(matrix);
        }

        start_time = clock();
        calculation(matrix);
        matrix_x = decision(matrix);
        end_time = clock();
        time += end_time - start_time;

        if (value.debugging == 1)
        {
            cout << "полученная матрица" << endl;
            print_vector_two_dimensional_4_1(matrix);
        }

        if (value.debugging == 1)
        {
            cout << "ответ: " << endl;
            print_vector_4_1(matrix_x);
            
            for (int i = 0; i < 6; i++)
            {
                cout << endl;
            }
        }
        matrix.clear();
    }
    return time;
}

void calculation(vector <vector <long long>> &matrix)
{
    vector <long long> output_matrix(matrix.size());
    long long  base, element_i, coefficient;
    int l = 1;
    boolean final = 1;
    Values value;
    for (int k = 0; k < matrix.size() - 1; k++)
    {

        if (matrix[k][k] == 0)
        {
            l = 1;
            if (value.debugging == 1)
            {
                cout << "первый элемент равен нулю" << endl;
            }
            for (int i = k + 1; i < matrix.size(); i++)
            {
                for (int j = k; j < matrix[i].size(); j++)
                {
                    if (matrix[i][j] != 0)
                        swap(matrix[k][j], matrix[i][j]);
                    else
                        l++;
                }

                if (l == matrix.size() - k)
                {
                    final = 0;
                    if (value.debugging == 0)                    
                        cout << "матрица вырожденная, значит имеет бесконечно много решений!" << endl;
                        print_vector_two_dimensional_4_1(matrix);
                    break;
                    exit(0);
                }

                if (matrix[k][k] != 0)
                {
                    if (value.debugging == 1)
                    {
                        cout << "матрица после перестановки строк:" << endl;
                        print_vector_two_dimensional_4_1(matrix);
                    }
                    break;
                }
            }
        }

        if (final == 0)
            break;

        for (int i = k + 1; i < matrix.size(); i++)
        {
            base = matrix[k][k];
            element_i = matrix[i][k];
            if (element_i != 0)
            {
                if (element_i % base == 0)
                {
                    coefficient = element_i / base;
                    for (int j = k; j < matrix[i].size(); j++)
                    {
                        matrix[k][j] *= coefficient;
                        matrix[i][j] += -1 * matrix[k][j];
                    }
                }
                else if (base % element_i == 0)
                {
                    coefficient = base / element_i;
                    for (int j = k; j < matrix[i].size(); j++)
                    {
                        matrix[i][j] *= coefficient;
                        matrix[i][j] += -1 * matrix[k][j];
                    }
                }
                else
                {
                    for (int j = k; j < matrix[i].size(); j++)
                    {
                        matrix[i][j] *= base;
                        matrix[k][j] *= element_i;
                        matrix[i][j] += -1 * matrix[k][j];
                    }
                }
            }
            if (value.debugging == 1)
            {
                cout << "матрица после прохода " << i + 1 << " строки, " << k + 1 << " столбца; " << endl;

                print_vector_two_dimensional_4_1(matrix);

                cout << endl;
            }
        }

        decrease(matrix);

    }
}

vector <double> decision(vector <vector <long long>> matrix)
{
    vector <double> matrix_x(matrix.size(), 0);
    double temp;
    for (int i = matrix.size() - 1; i >= 0; i--)
    {
        temp = 0;
        for (int j = matrix[i].size() - 2; j >= i; j--)
        {
            temp += matrix[i][j] * matrix_x[j];
        }
        temp = matrix[i][matrix[i].size() - 1] - temp;
        matrix_x[i] = temp / matrix[i][i];
    }
    return matrix_x;
}

void print_vector_4_1(vector <double> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "x" << i + 1 << " = " << setw(4) << matrix[i] << "; ";
    }
}

void fill(vector <vector <long long>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size() - 1; j++)
        {
            matrix[i][j] = rand() % 13 - 6;
        }
        matrix[i][matrix[i].size() - 1] = (rand() % 3 + 3) * (rand() % 13 - 6);
    }
}

void print_vector_two_dimensional_4_1(vector <vector <long long>> matrix)
{
    unsigned int N = matrix.size();
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << setw(N * 3 - 2) << matrix[i][j];
        }
        cout << endl;
    }
}

void decrease(vector <vector <long long>>& matrix)
{
    int l;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int s = 2; s <= 122; s++)
        {

            l = 1;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] % s != 0)
                {
                    l = 0;
                    break;
                }
            }
            if (l == 1)
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    matrix[i][j] /= s;
                }
            }
        }
    }
}