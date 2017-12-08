# Sorting Algorithm
[Wiki](https://en.wikipedia.org/wiki/Sorting_algorithm)

# Outline
- [selection sort](#selection-sort)
- [insertion sort](#insertion-sort)
- [shell sort](#shell-sort)
- [quick sort](#quick-sort)
- [test](#test)

# selection sort
[Wiki](https://en.wikipedia.org/wiki/Selection_sort)
- in iteration i, find index min of smallest remaining entry.
- swap a[i] and a[min].

## C
```C
// The selection sort algorithm
// @param arr The array to be sorted
// @param len The amount of elements in the array
void selection_sort(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < len; j++)
		{
			iMin = arr[j] < arr[iMin] ? j : iMin;
		}
		swap(&arr[i], &arr[iMin]);
	}
}
```

## Python
coming soon

# insertion sort
[Wiki](https://en.wikipedia.org/wiki/Insertion_sort)
- in iteration i, swap a[i] with each lager entry to its left.

## C
```C
// The insertion sort algorithm
// @param arr The array to be sorted
// @param len The amount of elements in the array
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

# shell sort
[Wiki](https://en.wikipedia.org/wiki/Shellsort)
- h-sort array for decreasing sequence of values of h, h use 3x + 1

## C
```C
// The insertion sort algorithm
// @param arr The array to be sorted
// @param len The amount of elements in the array
void shell_sort(int* a, int l)
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

# quick sort
[quick sort Wiki](https://en.wikipedia.org/wiki/Quicksort)


# test
[test.cpp](./test.cpp)
| Algroithms | Time(Sort 1000 numbers in VS 2017 64bit) |
|:----------:|:----------------------------------------:|
|selection sort|1.30731ms|
|insertion_sort|5.06953ms|
|shell sort|0.20992ms|
