#include <iostream>
#include <random>
#include <array>

#define N 100			   // 正方形节点阵的长度

int root(int p);
int connected(int p, int q);
void unioned(int p, int q);

using namespace std;
int id[N*N + 2];					// 有两个是虚拟节点,下标分别是 N*N 和 N*N+1
int sz[N*N + 2];					// size


void main()
{
	int state[N*N];				// state of site. 0 -> close; 1 -> open
	array<int, N*N> iRand;				// 随机数列容器
	double p;					// 概率p = 每次渗透的时候，open的节点 / 总结点

	/*** 初始化 ***/
	for (int i = 0; i < N*N + 2; i++)
	{
		id[i] = i;
		sz[i] = 1;
		if (i < N*N)
		{
			iRand[i] = i;			// 初始化随机数容器。正序排列
			state[i] = 0;			// 初始化状态为close
		}
	}
	sz[N*N] = sz[N*N + 1] = 2;		// 给定较大的初始size，使初始化能全部连向这两个节点
	for (int i = 0; i < N; i++)
	{
		unioned(N*N, i);					// 最上面一排的节点指向 N
		unioned(N*N + 1, i + N*(N - 1));		// 最下面一排的节点指向 N+1
	}
	random_shuffle(iRand.begin(), iRand.end());   // 对随机数容器的数字进行随机排序
	
												  
	/********** simulation *********/	
	int i = 0;
	while (root(N*N) != root(N*N + 1))
	{
		state[iRand[i]] = 1;
		if (state[iRand[i] - 1] == 1)
			unioned(iRand[i], iRand[i] - 1);
		if (state[iRand[i] + 1] == 1)
			unioned(iRand[i], iRand[i] + 1);
		if (state[iRand[i] - N] == 1)
			unioned(iRand[i], iRand[i] - N);
		if (state[iRand[i] + N] == 1)
			unioned(iRand[i], iRand[i] + N);
		i++;
	}
	p = (i - 1.0) / N / N;


	for (int i = 0; i < N*N + 2; i++)
	{
		cout << i;

		int j = i;
		while (id[j] != j)
		{
			cout << " -> " << id[j];
			j = id[j];
		}

		cout << "\n";
	}
	cout << "The final probabilty is " << p << endl;
	cin.get();
}

int root(int p)
{
	while (id[p] != p)
	{
		id[p] = id[id[p]];		// weight quick union with path compression(WQUPC), 只有一行代码
		p = id[p];
	}
	return p;
}

int connected(int p, int q)
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
