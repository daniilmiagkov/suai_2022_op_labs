#pragma once
#include <vector>
#include <Windows.h> // библиотека

using std::vector;

struct Skills_and_salaries
{
	vector <int> indexes;
	int sum_salaries, sum_skills, max_size, index;
	void push(vector <int> index_array, int sum_sa, int sum_sk)
	{
		indexes = index_array;
		sum_salaries = sum_sa;
		sum_skills = sum_sk;
	}
};

