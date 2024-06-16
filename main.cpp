#include "declaration.h"

void printArr (int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main () {

    int n;
    cin >> n;

    int *a = new int[n];
    GenerateData (a, n, 0); printArr (a, n);

    chrono::time_point<chrono::system_clock> start, end;

    start = chrono::system_clock::now ();
    flashSort1 (a, n);
    end = chrono::system_clock::now ();

    chrono::duration<double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count () << endl;

    delete[] a;
    return 0;
}