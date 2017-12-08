#ifndef SORT_H_
#define SORT_H_

void swap(int* x, int* y);
void selection_sort(int* arr, int len);
void insertion_sort(int* arr, int len);
void shell_sort(int* arr, int len);


void swap(int *x, int *y)
{
	int temp = *y;
	*y = *x;
	*x = temp;
}



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


#endif 