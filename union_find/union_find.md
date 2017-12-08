# Outline of Union Find
[Wiki](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)

[并查集(Union-Find)算法介绍](http://blog.csdn.net/dm_vincent/article/details/7655764)

# Outline
- [quick find](#quick-find)
- [quick union](#quick-union)
- [weighted QU with path compression](#weighted-qu-with-path-compression)
- [test](#test)
- [application(percolate simulation)](#applicationpercolate-simulation)

# quick find

- Data structure
	- Integer array id[] of length N.
	- Interpretation: p and q are connected iff they have the same id.
- Find
	- Check if p and q have the same id.
- Union
	- To merge components containing p and q, change all entries whose id equals id[p] to id[q].

## C
```C
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
```

## Python
coming soon

# quick union

- Data structure
	- Inter array id[] of length N.
	- Interpretation: id[i] is parent of i.
	- Root of i is id[id[id[...id[i]...]]].(keep going until it doesn't change)
- Find
	- Check if p and q have the same root.
- Union
	- To merge components containing p and q, set the id of p's root to the id of q's root.

## C
```C
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
```
## Python
coming soon

# weighted QU with path compression
- Improvement
	- Keep track of size of each tree(number of objects).
	- Balance by linking root of smaller tree to root of large tree.
-  Data structure
	- Same as Quick Union, but maintain extra array sz[i] to count number of objects in the tree rooted at i.
	- After computing the root of p, set the id of each examined node to point to that root.
-  Find
	- Identical to Quick Union
-  Union
	- Link root of smaller tree to root of larger tree.
	- Update the sz[] array.

## C
```C
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
```

## Python
coming soon

# test
[test.cpp](./test.cpp)

display the data structure tree in command line by using ->. You can find the difference between different union find algorithms.

| Algorithms | Find Time | Union Time |
|:----------:|:---------:|:----------:|
|quick find|0.137509ms|2.15503ms|
|quick union|0.518095ms|0.250636ms|
|weighted QU with path compression|0.20992ms|0.259413ms|

# application(percolate simulation)
- N-by-N grid of sites
- Each site is open with probabilaty p
- System percolates iff top and bottom are connected by open sites.

When N is large, theory guarantees a sharp threshold p*
- p > p*: almost certainly percolates.
- p < p*: almost certainly does not percolate.

[percolates.cpp](./percolates.cpp)
