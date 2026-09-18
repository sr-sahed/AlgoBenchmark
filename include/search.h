#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

class SearchBenchmark {
public:
    // Linear Search (O(N))
    static void linearSearch(const vector<int>& arr, int target) {
        auto start = high_resolution_clock::now();
        
        int foundIndex = -1;
        for (size_t i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                foundIndex = i;
                break;
            }
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "[Linear Search] Time: " << duration.count() << " ns" << endl;
    }

    // Binary Search (O(log N)) - Array must be sorted
    static void binarySearch(const vector<int>& arr, int target) {
        auto start = high_resolution_clock::now();
        
        int left = 0, right = arr.size() - 1;
        int foundIndex = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                foundIndex = mid;
                break;
            }
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "[Binary Search] Time: " << duration.count() << " ns" << endl;
    }
};