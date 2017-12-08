#ifndef UNION_FIND_H_
#define UNION_FIND_H_


int WQUPC_root(int p, int* id);
int WQUPC_find(int p, int q, int* id);
void WQUPC_unioned(int p, int q, int* id, int *sz);

int QU_root(int p, int* id);
int QU_find(int p, int q, int* id);
void QU_unioned(int p, int q, int* id);

int QF_find(int p, int q, int* id);
void QF_unioned(int p, int q, int* id, int len);





// The weight quick unioned with path compression algorithm
// @func WQUPC_find if p and q are connected
// @func WQUPC_unioned  connect p and q
int WQUPC_root(int p, int* id)
{
	while (id[p] != p)
	{
		id[p] = id[id[p]];		// weight quick unioned with path compression(WQUPC), only one extra line
		p = id[p];
	}
	return p;
}

int WQUPC_find(int p, int q, int* id)
{
	return WQUPC_root(p,id) == WQUPC_root(q, id);
}

void WQUPC_unioned(int p, int q, int* id, int *sz)
{
	int i = WQUPC_root(p, id);			// 对处在root的数进行连接，否则会连成圈，导致root函数无限循环
	int j = WQUPC_root(q, id);

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



// The quick unioned algorithm
// @func QU_find if p and q are connected
// @func QU_unioned  connect p and q
int QU_root(int p, int* id)
{
	while (id[p] != p)
	{
		p = id[p];
	}
	return p;
}

int QU_find(int p, int q, int* id)
{
	return QU_root(p, id) == QU_root(q, id);
}

void QU_unioned(int p, int q, int* id)
{
	int i = QU_root(p, id);			// 对处在root的数进行连接，否则会连成圈，导致root函数无限循环
	int j = QU_root(q, id);
	id[i] = j;
}


// The quick find algorithm
// @func QF_find if p and q are connected
// @func QF_unioned  connect p and q
int QF_find(int p, int q, int* id)
{
	return (id[p] == id[q]);
}

void QF_unioned(int p, int q, int* id, int len)
{
	int pid = id[p];			// It's necessary for these two lines code
	int qid = id[q];			// The value of id[p] will change while i > p
	for (int i = 0; i < len; i++)
	{
		if (id[i] == pid)
		{
			id[i] = qid;
		}
	}
}

#endif 
