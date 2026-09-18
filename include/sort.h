#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

class SortingBenchmark {
private:
    // Helper function for Merge Sort
    static void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    // Helper function for Quick Sort (Partition)
    static int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    // Recursive Quick Sort implementation
    static void quickSortHelper(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSortHelper(arr, low, pi - 1);
            quickSortHelper(arr, pi + 1, high);
        }
    }

    // Recursive Merge Sort implementation
    static void mergeSortHelper(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortHelper(arr, left, mid);
            mergeSortHelper(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

public:
    // 1. Bubble Sort (O(N^2)) - Good for small inputs
    static void bubbleSort(vector<int> arr) {
        int n = arr.size();
        auto start = high_resolution_clock::now();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[Bubble Sort] N = " << n << " | Time: " << duration.count() << " microseconds" << endl;
    }

    // 2. Merge Sort (O(N log N)) - Divide and Conquer
    static void mergeSort(vector<int> arr) {
        int n = arr.size();
        auto start = high_resolution_clock::now();
        
        mergeSortHelper(arr, 0, n - 1);
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[Merge Sort] N = " << n << " | Time: " << duration.count() << " microseconds" << endl;
    }

    // 3. Quick Sort (O(N log N) average)
    static void quickSort(vector<int> arr) {
        int n = arr.size();
        auto start = high_resolution_clock::now();
        
        quickSortHelper(arr, 0, n - 1);
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[Quick Sort] N = " << n << " | Time: " << duration.count() << " microseconds" << endl;
    }

    // 4. C++ std::sort (IntroSort - O(N log N)) - Highly Optimized
    static void stdSort(vector<int> arr) {
        int n = arr.size();
        auto start = high_resolution_clock::now();
        
        sort(arr.begin(), arr.end());
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[C++ std::sort] N = " << n << " | Time: " << duration.count() << " microseconds" << endl;
    }
};