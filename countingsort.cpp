#include "declaration.h"

void countingSort1(int a[], int n) 
{

    int k = *max_element(a, a + n); 

    int *cnt = new int[k + 1];
    for (int i = 0; i < k + 1; i++) cnt[i] = 0;

    for (int i = 0; i < n; i++) { 
        cnt[a[i]]++; 
    } 
  
    for (int i = 1; i <= k; i++) { 
        cnt[i] = cnt[i] + cnt[i - 1]; 
    } 

    int *ans = new int[n]; 
    for (int i = n - 1; i >= 0; i--) { 
        ans[--cnt[a[i]]] = a[i]; 
    } 

    for (int i = 0; i < n; i++) { 
        a[i] = ans[i]; 
    }

    delete[] cnt;
    delete[] ans;
}

// Count

void countingSort2(int a[], int n)
{
    int countAssignments = 0, countComparisons = 0;

    int k = *max_element(a, a + n); ++countAssignments;

    int *cnt = new int[k + 1];

    ++countAssignments; // i = 0
    for (int i = 0;++countComparisons && i < k + 1; i++) {
        ++countAssignments; // i++

        cnt[i] = 0; ++countAssignments;
    }

    ++countAssignments; // i = 0
    for (int i = 0;++countComparisons && i < n; i++) { 
        ++countAssignments; // i++

        cnt[a[i]]++; ++countAssignments;
    } 
  
    ++countAssignments; // i = 1
    for (int i = 1;++countComparisons && i <= k; i++) { 
        ++countAssignments; // i++

        cnt[i] = cnt[i] + cnt[i - 1]; ++countAssignments;
    } 

    int *ans = new int[n]; 

    ++countAssignments; // i = n - 1
    for (int i = n - 1; ++countComparisons && i >= 0; i--) { 
        ++countAssignments;

        ans[--cnt[a[i]]] = a[i]; ++countAssignments;
    } 

    ++countAssignments; // i = 0
    for (int i = 0; ++countComparisons && i < n; i++) { 
        ++countAssignments; // i++

        a[i] = ans[i]; ++countAssignments;
    }

    delete[] cnt;
    delete[] ans;

    // Do something with 2 variable count.
}