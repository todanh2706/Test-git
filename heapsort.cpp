#include "declaration.h"

void heapify1(int a[], int n, int i)
{

    int largest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);

        heapify1(a, n, largest);
    }
}

void heapSort1(int a[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify1(a, n, i);

    for (int i = n - 1; i > 0; i--) {

        swap(a[0], a[i]);

        heapify1(a, i, 0);
    }
}

// Count

void heapify2(int a[], int n, int i, int &countAssignments, int &countComparisons)
{

    int largest = i; ++countAssignments;

    int l = 2 * i + 1; ++countAssignments;

    int r = 2 * i + 2; ++countAssignments;

    if (++countComparisons && l < n && ++countComparisons && a[l] > a[largest])
        largest = l; ++countAssignments;

    if (++countComparisons && r < n && ++countComparisons && a[r] > a[largest])
        largest = r; ++countAssignments;

    if (++countComparisons && largest != i) {
        swap(a[i], a[largest]);

        heapify2(a, n, largest, countAssignments, countComparisons);
    }
}

// Count

void heapSort2(int a[], int n)
{

    int countAssignments = 0, countComparisons = 0;

    ++countAssignments; // i = n / 2 - 1
    for (int i = n / 2 - 1; ++countComparisons && i >= 0; i--) {
        ++countAssignments; // i--
        heapify2(a, n, i, countAssignments, countComparisons);
    }

    ++countAssignments;
    for (int i = n - 1; ++countComparisons && i > 0; i--) {
        ++countAssignments;
        
        swap(a[0], a[i]);

        heapify2(a, i, 0, countAssignments, countComparisons);
    }

    // Do something with 2 variables count.
}