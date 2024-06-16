#include "declaration.h"

void insertionSort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void flashSort1(int a[], int n)
{
	int minVal = a[0];
	int max = 0;
	int m = (int) (0.45 * n);
	int *l = new int[m];

	for (int i = 0; i < m; i++)
		l[i] = 0;

	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}

	if (a[max] == minVal)
		return;
    
	double c1 = (double) (m - 1) / (a[max] - minVal);

	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}

	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];

	swap (a[max], a[0]);

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
    
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = (int) (c1 * (a[j] - minVal));
		}
		flash = a[j];

		if (k < 0) break;

		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
    
	delete[] l;
	insertionSort(a, n);
}

// Count

void flashSort2(int a[], int n)
{
    int countAssignments = 0, countComparisons = 0;
    
	int minVal = a[0]; ++countAssignments;
	int max = 0; ++countAssignments;
	int m = (int) (0.45 * n); ++countAssignments;
	int *l = new int[m];

    ++countAssignments;
	for (int i = 0; ++countComparisons && i < m; i++) {
        ++countAssignments;

		l[i] = 0; ++countAssignments;
    }

    ++countAssignments;
	for (int i = 1; ++countComparisons && i < n; i++)
	{
        ++countAssignments;

		if (++countComparisons && a[i] < minVal) {
			minVal = a[i]; ++countAssignments;
        }

		if (++countComparisons && a[i] > a[max]) {
			max = i; ++countAssignments;
        }
	}

	if (++countComparisons && a[max] == minVal) {
		return;
    }
    
	double c1 = (double) (m - 1) / (a[max] - minVal); ++countAssignments;

    ++countAssignments;
	for (int i = 0; ++countComparisons && i < n; i++)
	{
        ++countAssignments;

		int k = int(c1 * (a[i] - minVal)); ++countAssignments;
		++l[k]; ++countAssignments;
	}

    ++countAssignments;
	for (int i = 1; ++countComparisons && i < m; i++) {
        ++countAssignments;
        
		l[i] += l[i - 1]; ++countAssignments;
    }

	swap (a[max], a[0]);

	int nmove = 0; ++countAssignments;
	int j = 0; ++countAssignments;
	int k = m - 1; ++countAssignments;
	int t = 0; ++countAssignments;
	int flash;
    
	while (++countComparisons && nmove < n - 1)
	{
		while (++countComparisons && j > l[k] - 1)
		{
			j++; ++countAssignments;
			k = (int) (c1 * (a[j] - minVal)); ++countAssignments;
		}
		flash = a[j]; ++countAssignments;

		if (++countComparisons && k < 0) break;

		while (++countComparisons && j != l[k])
		{
			k = int(c1*(flash - minVal)); ++countAssignments;
			int hold = a[t = --l[k]]; ++countAssignments;
			a[t] = flash; ++countAssignments;
			flash = hold; ++countAssignments;
			++nmove; ++countAssignments;
		}
	}

	delete[] l;
	insertionSort(a, n); // Chờ selection sort count
}