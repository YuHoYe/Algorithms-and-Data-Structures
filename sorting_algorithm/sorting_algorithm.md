# Outline of Elementary Sorts
[https://en.wikipedia.org/wiki/Sorting_algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)

- [Selection sort](#selection-sort)
- [insertion sort](#insertion-sort)
- [shell sort](#shell-sort)
- [fast sort](#fast-sort)
- [test](#test)

# Selection sort
[https://en.wikipedia.org/wiki/Selection_sort](https://en.wikipedia.org/wiki/Selection_sort)
- in iteration i, find index min of smallest remaining entry.
- swap a[i] and a[min].

## C++
```C++
/* a[0] to a[n-1] is the array to sort */
int i,j;
int n;

/* advance the position through the entire array */
/*   (could do j < n-1 because single element is also min element) */
for (j = 0; j < n-1; j++)
{
    /* find the min element in the unsorted a[j .. n-1] */

    /* assume the min is the first element */
    int iMin = j;
    /* test against elements after j to find the smallest */
    for (i = j+1; i < n; i++)
    {
        /* if this element is less, then it is the new minimum */
        if (a[i] < a[iMin])
        {
            /* found new minimum; remember its index */
            iMin = i;
        }
    }

    if (iMin != j) 
    {
        swap(a[j], a[iMin]);
    }
}
```

## Python
coming soon

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

# quick sort
[quick sort Wiki](https://en.wikipedia.org/wiki/Quicksort)


# test
[test elementary sorts.cpp](./test%20elementary%20sorts.cpp)

| algorithm | time(# of elements is 20480) |
|:---------:|:----------:|
|selection sort|713|
|insertion sort|2153|
|shell sort|12|

