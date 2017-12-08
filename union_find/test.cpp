#include <iostream>
#include <cmath>
#include <windows.h>
#include "union_find.h"

#define N 1000



void main()
{
	int id[N];
	int sz[N] = { 1 };

	// 初始化，每个点都不相连，数组下标代表点的index，数组内容用来判定是否相连
	for (int i = 0; i < N; i++)
		id[i] = i;

	double time_union = 0;
	double time_find = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	QueryPerformanceCounter(&nBeginTime); // Start the timer for union
	for (int i = 0; i < N ; i++)
	{
		int p = rand() % N;
		int q = rand() % N;
		WQUPC_unioned(p, q, id, sz);
	}
	QueryPerformanceCounter(&nEndTime);	// End the timer for union
	time_union = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart; // Calculate the union function run time

	QueryPerformanceCounter(&nBeginTime); // Start the timer for find
	for (int i = 0; i < N; i++)
	{
		int p = rand() % N;
		int q = rand() % N;
		WQUPC_find(p, q, id);
	}
	QueryPerformanceCounter(&nEndTime);	// End the timer for find
	time_find = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart; // Calculate the find function run time

	// show the data structure tree in command line
	for (int i = 0; i < N; i++)
	{
		std::cout << i;

		int j = i;
		while (id[j] != j)
		{
			std::cout << " -> " << id[j];
			j = id[j];
		}

		std::cout << std::endl;
	}

	std::cout << "The union time is:" << time_union * 1000 << "ms" << std::endl;
	std::cout << "The find time is:" << time_find * 1000 << "ms" << std::endl;
	std::cin.get();
}



