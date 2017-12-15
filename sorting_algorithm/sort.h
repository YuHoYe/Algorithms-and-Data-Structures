#ifndef SORT_H_
#define SORT_H_

void swap(int* x, int* y);
void selection_sort(int arr[], int len);
void insertion_sort(int arr[], int len);
void shell_sort(int arr[], int len);
void quick_sort(int arr[], int len);
void quick_sort_recursive(int arr[], int start, int end);
void merge_sort(int arr[], const int len);
void merge_sort_recursive(int arr[], int reg[], int start, int end);



void swap(int *x, int *y)
{
	int temp = *y;
	*y = *x;
	*x = temp;
}


// The selection sort algorithm
// @param arr[] The array to be sorted
// @param len The amount of elements in the array
void selection_sort(int arr[], int len)
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
// @param arr[] The array to be sorted
// @param len The amount of elements in the array
void insertion_sort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
			swap(&arr[j], &arr[j - 1]);
	}
}


// The insertion sort algorithm
// @param arr[] The array to be sorted
// @param len The amount of elements in the array
void shell_sort(int arr[], int len)
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


// The quick sort algorithm
// @param arr[] The array to be sorted
// @param len The amount of elements in the array
void quick_sort(int arr[], int len) 
{
	quick_sort_recursive(arr, 0, len - 1);
}
// The quick sort recursive part
// @param arr[] The array to be sorted
// @param start The start index for sort, normally equal to 0
// @param end The end index for sort, normally equal to length(arr)-1
void quick_sort_recursive(int arr[], int start, int end)
{
	int Cutoff = 10;		// Cutoff to insertion sort = 10 items.
	if (start >= end)
		return;		
	if (end <= start + Cutoff - 1)			// Using insertion sort for small subarrys.
	{
		insertion_sort(&arr[start], end - start + 1);
		return;
	}
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


// The merge sort algorithm
// @param arr[] The array to be sorted
// @param len The amount of elements in the array
void merge_sort(int arr[], const int len)
{
	int* reg = new int[len];
	merge_sort_recursive(arr, reg, 0, len - 1);
}
// The merge sort recursive part
// @param arr[] The array to be sorted
// @param reg[] The auxiliary array
// @param start The start index for sort, normally equal to 0
// @param end The end index for sort, normally equal to length(arr)-1
void merge_sort_recursive(int arr[], int reg[], int start, int end)
{
	int Cutoff = 7;		// Cutoff to insertion sort = 7 items.
	if (start >= end)
		return;
	if (end <= start + Cutoff - 1)			// Using insertion sort for small subarrys.
	{
		insertion_sort(&arr[start], end - start + 1);
		return;
	}
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	merge_sort_recursive(arr, reg, start1, end1);
	merge_sort_recursive(arr, reg, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2)
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	while (start1 <= end1)
		reg[k++] = arr[start1++];
	while (start2 <= end2)
		reg[k++] = arr[start2++];
	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}


#endif 