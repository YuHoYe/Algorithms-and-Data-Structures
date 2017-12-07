#include <iostream>
#include <cmath>

#define N 100

int root(int p);
int find(int p, int q);
void unioned(int p, int q);

int id[N];
int sz[N] = { 1 };

void main()
{
	// 初始化，每个点都不相连，数组下标代表点的index，数组内容用来判定是否相连
	for (int i = 0; i < N; i++)
		id[i] = i;


	for (int i = 0; i < N ; i++)
	{
		int p = rand() % N;
		int q = rand() % N;
		unioned(p, q);
	}

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

	std::cin.get();
}


/*************** Weighted quick-unioned *******************/

int root(int p)
{
	while (id[p] != p)
	{
		id[p] = id[id[p]];		// weight quick unioned with path compression(WQUPC), 只有一行代码
		p = id[p];
	}
	return p;
}

int find(int p, int q)
{
	return root(p) == root(q);
}

void unioned(int p, int q)
{
	int i = root(p);			// 对处在root的数进行连接，否则会连成圈，导致root函数无限循环
	int j = root(q);

	if (i == j)
		return;
	if (sz[i] < sz[j])
	{
		id[i] = j;
		sz[j] += sz[i];
	}
	else
	{
		id[j] = i;
		sz[i] += sz[j];
	}
}



/*************** Quick-unioned *******************/

//
//int root(int p)
//{
//	while (id[p] != p)
//	{
//		p = id[p];
//	}
//	return p;
//}
//
//int find(int p, int q)
//{
//	return root(p) == root(q);
//}
//
//void unioned(int p, int q)
//{
//	int i = root(p);			// 对处在root的数进行连接，否则会连成圈，导致root函数无限循环
//	int j = root(q);
//	id[i] = j;
//}



/*************** Quick-find ****************/

//int find(int p, int q)
//{
//	return (id[p] == id[q]);
//}
//
//void unioned(int p, int q)
//{
//	int pid = id[p];			// It's necessary for these two lines code
//	int qid = id[q];			// The value of id[p] will change while i > p
//	for (int i = 0; i < N; i++)
//	{
//		if (id[i] == pid)
//		{
//			id[i] = qid;
//		}
//	}
//}
