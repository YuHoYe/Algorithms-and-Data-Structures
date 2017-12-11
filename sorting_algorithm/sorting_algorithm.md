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
- in iteration i, find index iMin of smallest remaining entry.
- swap a[i] and a[iMin].

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

# insertion sort
[Wiki](https://en.wikipedia.org/wiki/Insertion_sort)
- in iteration i, swap a[i] with each lager entry to its left.

## C
```C
// The insertion sort algorithm
// @param arr The array to be sorted
// @param len The amount of elements in the array
void insertion_sort(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
			swap(&arr[j], &arr[j - 1]);
	}
}
```

# shell sort
[Wiki](https://en.wikipedia.org/wiki/Shellsort)
- h-sort array for decreasing sequence of values of h, h use 3x + 1

## C
```C
// The insertion sort algorithm
// @param arr The array to be sorted
// @param len The amount of elements in the array
void shell_sort(int* arr, int len)
{
	int h = 1;
	while (len > 3 * h)
		h = 3 * h + 1;		// 3x + 1 increase sequence(find the biggest h)

	while (h >= 1)
	{
		for (int i = h; i < len; i++)
		{
			for (int j = i; (j > h) && (arr[j] < arr[j - h]); j -= h)
				swap(&arr[j], &arr[j - h]);
		}

		h = h / 3;
	}
}
```

# quick sort
[Wiki](https://en.wikipedia.org/wiki/Quicksort)
- quick sort is a divide and conquer algorithm.
- Pick an element, called a pivot, from the array.
- Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
- Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values

## C
```C
// The quick sort algorithm
// @param arr The array to be sorted
// @param len The amount of elements in the array
void quick_sort(int* arr, int len) 
{
	quick_sort_recursive(arr, 0, len - 1);
}
// The quick sort recursive part algorithm
// @param arr The array to be sorted
// @param start The start index for sort, normaly equal to 0
// @param end The end index for sort, normaly equal to length(arr)-1
void quick_sort_recursive(int* arr, int start, int end)
{
	if (start >= end)
		return;		
	int mid = arr[end];
	int left = start, right = end - 1;
	while (left < right) 
	{
		while (arr[left] < mid && left < right)		// scan from left to right
			left++;
		while (arr[right] >= mid && left < right)	// scan from right to left
			right--;
		swap(&arr[left], &arr[right]);
	}
	if (arr[left] >= arr[end])
		swap(&arr[left], &arr[end]);
	else
		left++;
	if (left)
		quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}
```


# test
[test.cpp](./test.cpp)

| Algroithms | Time(Sort 1000 numbers in VS 2017 64bit) |
|:----------:|:----------------------------------------:|
|selection sort|1.30731ms|
|insertion_sort|5.06953ms|
|shell sort|0.20992ms|
|quick sort|0.14604ms|
