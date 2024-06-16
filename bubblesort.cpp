#include "declaration.h"

void bubbleSort1(int a[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

// Count

void bubbleSort2(int a[], int n)
{
    int countAssignments = 0, countComparisons = 0;

    int i, j;
    bool swapped;

    ++countAssignments; // i = 0
    for (i = 0; ++countComparisons && i < n - 1; i++) {
        ++countAssignments; // i++
        swapped = false; ++countAssignments;

        ++countAssignments; // j = 0
        for (j = 0; ++countComparisons && j < n - i - 1; j++) {
            ++countAssignments; // j++
            if (++countComparisons && a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true; ++countAssignments;
            }
        }

        if (++countComparisons && swapped == false)
            break;
    }

    // Do something with 2 variable count.
}