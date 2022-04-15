#include <iostream>// библиотека
#include <Windows.h> // библиотека


static double getNumber()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        double a;
        std::cin >> a;

        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout << "вы ввели не число" << std::endl;
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

double calculation_function(int N, int x)
{
    double result = 0;
    if (N == 0)
    {
        result = pow(x + 1, 0.5);
    }
    else
    {
        result = pow((x + N * int(calculation_function(N - 1, x))), 0.5);
    }
    std::cout << N << " " << result << std::endl ;
    // 3 + 1.5 * 
    // 3 + 0.5 * 
    return result;
}

void main()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    double N, x;
    std::cout << "введите число N" << std::endl;
    N = getNumber();
    std::cout << "введите число x " << std::endl;
    x = getNumber();
    std::cout << calculation_function(N, x);
}