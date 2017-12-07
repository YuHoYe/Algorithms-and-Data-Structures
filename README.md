# Algorithms and Data Structures
Algorithms and Data Structure achieved by C++ and Python

# Outline
- [Books & MOOCs](#books-&-moocs)
- [Analysis Of Algorithm](#analysis-of-algorithm)
- [Union Find](#union-find)
	- [Quick Find](#quick-find)
	- [Quick Union](#quick-union)
	- [Weighted Quick Union](#weighted-quick-union)

# Books & MOOCs
[Algorithms, Part I](https://www.coursera.org/learn/algorithms-part1) Made by Princeton University

# Analysis Of Algorithms
Algorithm complexity is something designed to compare two algorithms at the idea level — ignoring low-level details such as the implementation programming language, the hardware the algorithm runs on, or the instruction set of the given CPU.

# Union Find
Given a set of N objects. 
- **Union command**: connect two objects.
- **Find query**: is there a path connecting the two objects?

## Quick Find

- Data structure
	- Integer array id[] of length N.
	- Interpretation: p and q are connected iff they have the same id.
- Find
	- Check if p and q have the same id.
- Union
	- To merge components containing p and q, change all entries whose id equals id[p] to id[q].

#### Code(C)
```C
int find(int p, int q)
{
	return (id[p] == id[q]);
}

void union(int p, int q)
{
	int pid = id[p];			// It's necessary for these two lines code
	int qid = id[q];			// The value of id[p] will change while i > p
	for (int i = 0; i < N; i++)
	{
		if (id[i] == pid)
		{
			id[i] = qid;
		}
	}
}
```

#### Code(Python)
coming soon

#### Cost Model
Number of array accesses(for read or write)

| Algorithm | Initialize | Union | Find |
|:---------:|:----------:|:-----:|:----:|
|Quick Find|N|N|1|

Uion is too expensive. It take N^2 array accesses to process a sequence of N union commands on N objects.

## Quick Union

- Data structure
	- Inter array id[] of length N.
	- Interpretation: id[i] is parent of i.
	- Root of i is id[id[id[...id[i]...]]].(keep going until it doesn't change)
- Find
	- Check if p and q have the same root.
- Union
	- To merge components containing p and q, set the id of p's root to the id of q's root.

#### Code
```C
int root(int p)
{
	while (id[p] != p)
	{
		p = id[p];
	}
	return p;
}

int find(int p, int q)
{
	return root(p) == root(q);
}

void union(int p, int q)
{
	int i = root(p);			// 对处在root的数进行连接，否则会连成圈，导致root函数无限循环
	int j = root(q);
	id[i] = j;
}
```
#### Code(Python)
coming soon

#### Cost model
Number of array accesses(for read or write)

| Algorithm | Initialize | Union | Find |
|:---------:|:----------:|:-----:|:----:|
|Quick Find|N|N|1|
|Quick Union|N|N(includes cost of finding roots)|N|

Trees can get tall and find is too expensive(could be N array accesses).

## Weighted Quick Union

- Improvement
	- Keep track of size of each tree(number of objects).
	- Balance by linking root of smaller tree to root of large tree.
-  Data structure
	- Same as Quick Union, but maintain extra array sz[i] to count number of objects in the tree rooted at i.
-  Find
	- Identical to Quick Union
-  Union
	- Link root of smaller tree to root of larger tree.
	- Update the sz[] array.

#### Code(C)
```C
int root(int p)
{
	while (id[p] != p)
	{
		p = id[p];
	}
	return p;
}

int find(int p, int q)
{
	return root(p) == root(q);
}

void union(int p, int q)
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
```

#### Code(Python)
coming soon

#### Cost model
Number of array accesses(for read or write)

| Algorithm | Initialize | Union | Find |
|:---------:|:----------:|:-----:|:----:|
|Quick Find|N|N|1|
|Quick Union|N|N(includes cost of finding roots)|N|
|Weighted QU|N|lg N(includes cost of finding roots)|lg N|

## Quick union with path compression
Just after computing the root of p, set the id of each examined node to point to that root.

#### Code(C)
```C
int root(int p)
{
	while (id[p] != p)
	{
		id[p] = id[id[p]];		// weight quick union with path compression(WQUPC), only one extra line of code.
		p = id[p];
	}
	return p;
}
```

#### Code(Python)
coming soon

