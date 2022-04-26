#pragma once
#include <Windows.h> // библиотека
#include <vector>

using std::vector;

class Team
{
public:
	Character one, two, three;
	void set_team(vector < Character > team)
	{
		one = team[0];
		two = team[1];
		three = team[2];
	}
};

