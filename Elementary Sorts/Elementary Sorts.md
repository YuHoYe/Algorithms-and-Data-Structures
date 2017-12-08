# Outline of Elementary Sorts
- [selection sort](#selection-sort)
- [insertion sort](#insertion-sort)
- [shell sort](#shell-sort)
- [test](#test)

# selection sort
- in iteration i, find index min of smallest remaining entry.
- swap a[i] and a[min].

## C++
```C++
void selection_sort(int* a, int l)
{
	for (int i = 0; i < l; i++)
	{
		int min = i;
		for (int j = i + 1; j < l; j++)
		{
			min = a[j] < a[min] ? j : min;
		}
		swap(&a[i], &a[min]);
	}
}
```

## Python
coming soon

## cost model
| algorithm | compares | changes |
|:---------:|:----------:|:-----:|
|selection sort|1/2N^2|N|

# insertion sort
- in iteration i, swap a[i] with each lager entry to its left.

## C++
```C++
void insertion_sort(int* a, int l)
{
	for (int i = 0; i < l; i++)
	{
		for (int j = i; j > 0 && a[j] < a[j - 1]; j--)
			swap(&a[j], &a[j - 1]);
	}
}
```

## Python
coming soon

## cost model
| algorithm | compares | changes |
|:---------:|:----------:|:-----:|
|selection sort|1/2N^2|N|
|insertion sort|1/4N^2|1/4N^2|

# shell sort
- h-sort array for decreasing sequence of values of h, h use 3x + 1

## C++
```C++
void shellsort(int* a, int l)
{
	int h = 1;
	while (l > 3 * h)
		h = 3 * h + 1;		// 3x + 1 increase sequence(find the biggest h)

	while (h >= 1)
	{
		for (int i = h; i < l; i++)
		{
			for (int j = i; (j > h) && (a[j] < a[j - h]); j -= h)
				swap(&a[j], &a[j - h]);
		}

		h = h / 3;
	}
}
```

## Python 
coming soon

## cost model
| algorithm | compares | changes |
|:---------:|:----------:|:-----:|
|selection sort|1/2N^2|N|
|insertion sort|1/4N^2|1/4N^2|
|shell sort|2.5N lg N(no accurate model)|-|

# test
[test elementary sorts.cpp](./test%20elementary%20sorts.cpp)

| algorithm | time(# of elements is 20480) |
|:---------:|:----------:|
|selection sort|713|
|insertion sort|2153|
|shell sort|12|

