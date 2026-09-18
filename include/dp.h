#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

class DPBenchmark {
public:
    // 1. 0/1 Knapsack Problem - O(N * W)
    static void knapsack01(int W, const vector<int>& weights, const vector<int>& values, int n) {
        auto start = high_resolution_clock::now();
        
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0)
                    dp[i][w] = 0;
                else if (weights[i - 1] <= w)
                    dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
                else
                    dp[i][w] = dp[i - 1][w];
            }
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[0/1 Knapsack] Max Value: " << dp[n][W] << " | Time: " << duration.count() << " microseconds" << endl;
    }

    // 2. Longest Common Subsequence (LCS) - O(m * n)
    static void longestCommonSubsequence(const string& s1, const string& s2) {
        auto start = high_resolution_clock::now();
        
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[LCS] Length: " << dp[m][n] << " | Time: " << duration.count() << " microseconds" << endl;
    }
};