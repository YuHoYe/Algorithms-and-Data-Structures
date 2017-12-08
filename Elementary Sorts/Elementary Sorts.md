# Outline of Elementary Sorts

# Selection sort
- in iteration i, find index min of smallest remaining entry
- swap a[i] and a[min]

## Code(C++)
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
