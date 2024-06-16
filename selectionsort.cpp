#include "declaration.h"

void selectionSort1(int a[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {

        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            swap(a[min_idx], a[i]);
    }
}

// Count

void selectionSort2(int a[], int n)
{
    int countAssignments = 0, countComparisons = 0;

    int i, j, min_idx;

    ++countAssignments;
    for (i = 0; ++countComparisons && i < n - 1; i++) {
        ++countAssignments;

        min_idx = i; ++countAssignments;

        ++countAssignments;
        for (j = i + 1; ++countComparisons && j < n; j++) {
            ++countAssignments;

            if (++countComparisons && a[j] < a[min_idx]) {
                min_idx = j; ++countAssignments;
            }
        }

        if (++countComparisons && min_idx != i) {
            swap(a[min_idx], a[i]); ++countAssignments;
        }
    }
}