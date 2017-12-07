#include <stdio.h>
#include <math.h>

#define N 100

int root(int p);
int find(int p, int q);
void unioned(int p, int q);

int id[N];
int sz[N] = { 1 };

void main()
{
	// ��ʼ����ÿ���㶼�������������±������index���������������ж��Ƿ�����
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
		printf("%d", i);

		int j = i;
		while (id[j] != j)
		{
			printf(" -> %d ", id[j]);
			j = id[j];
		}

		printf("\n");
	}

	getchar();
}


/*************** Weighted quick-unioned *******************/

int root(int p)
{
	while (id[p] != p)
	{
		id[p] = id[id[p]];		// weight quick unioned with path compression(WQUPC), ֻ��һ�д���
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
	int i = root(p);			// �Դ���root�����������ӣ����������Ȧ������root��������ѭ��
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
//	int i = root(p);			// �Դ���root�����������ӣ����������Ȧ������root��������ѭ��
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