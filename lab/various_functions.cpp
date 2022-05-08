#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "various_functions.h"
#include <vector>
#include "Point.h"

using namespace std;

string char_to_string(char ch)
{
    string s = {};
    s += ch;
    return s;
}

Point cursor_position()
{
	CONSOLE_SCREEN_BUFFER_INFO bi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
	return { bi.dwCursorPosition.X, bi.dwCursorPosition.Y };
}


void set_cursor_position(Point A)
{
	COORD coord;
	coord.X = A.x;
	coord.Y = A.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void erase_past_output(Point A)
{
	CONSOLE_SCREEN_BUFFER_INFO bi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
	set_cursor_position(A);
	string s = "";
	for (int i = 0; i < 80; i++)
		s += ' ';
	for (int i = 0; i < bi.dwCursorPosition.Y - A.y; i++)
		cout << s << endl;

	set_cursor_position(A);
}
