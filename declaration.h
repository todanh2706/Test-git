#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <chrono>
#include <algorithm>

using namespace std;

// Data
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

// Sorting
void selectionSort1(int a[], int n);
void selectionSort2(int a[], int n);

void bubbleSort1(int a[], int n);
void bubbleSort2(int a[], int n);

void heapSort1(int a[], int n);
void heapSort2(int a[], int n);

void countingSort1(int a[], int n);
void countingSort2(int a[], int n);

void flashSort1(int a[], int n);
void flashSort2(int a[], int n);