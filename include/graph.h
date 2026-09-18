#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

class GraphBenchmark {
public:
    // 1. Breadth-First Search (BFS) - O(V + E)
    static void bfs(int startNode, int V, const vector<vector<int>>& adj) {
        auto start = high_resolution_clock::now();
        
        vector<bool> visited(V, false);
        queue<int> q;
        
        visited[startNode] = true;
        q.push(startNode);
        
        int visitedCount = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visitedCount++;
            
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[BFS] Nodes Visited: " << visitedCount << " | Time: " << duration.count() << " microseconds" << endl;
    }

    // Helper for DFS
    static void dfsUtil(int node, const vector<vector<int>>& adj, vector<bool>& visited, int& visitedCount) {
        visited[node] = true;
        visitedCount++;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, adj, visited, visitedCount);
            }
        }
    }

    // 2. Depth-First Search (DFS) - O(V + E)
    static void dfs(int startNode, int V, const vector<vector<int>>& adj) {
        auto start = high_resolution_clock::now();
        
        vector<bool> visited(V, false);
        int visitedCount = 0;
        dfsUtil(startNode, adj, visited, visitedCount);
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[DFS] Nodes Visited: " << visitedCount << " | Time: " << duration.count() << " microseconds" << endl;
    }

    // 3. Dijkstra's Algorithm (Shortest Path) - O((V + E) log V)
    static void dijkstra(int startNode, int V, const vector<vector<pair<int, int>>>& adj) {
        auto start = high_resolution_clock::now();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        
        pq.push({0, startNode});
        dist[startNode] = 0;
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[Dijkstra] Shortest Path Calculated | Time: " << duration.count() << " microseconds" << endl;
    }

    // 4. Prim's Algorithm (Minimum Spanning Tree) - O(E log V)
    static void primMST(int V, const vector<vector<pair<int, int>>>& adj) {
        auto start = high_resolution_clock::now();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> inMST(V, false);
        
        pq.push({0, 0}); // {weight, node}
        int mstCost = 0;
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            
            if (inMST[u]) continue;
            
            inMST[u] = true;
            mstCost += weight;
            
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                
                if (!inMST[v]) {
                    pq.push({wt, v});
                }
            }
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[Prim's MST] Total Cost: " << mstCost << " | Time: " << duration.count() << " microseconds" << endl;
    }
};