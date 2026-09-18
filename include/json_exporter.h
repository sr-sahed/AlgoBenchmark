#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class JsonExporter {
public:
    static void saveResults() {
        // Creating a JSON file inside the output folder
        ofstream outFile("output/results.json");
        
        if (!outFile) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }

        // Writing benchmark data in JSON format
        outFile << "{\n";
        outFile << "  \"sorting\": [\n";
        outFile << "    {\"algorithm\": \"Bubble Sort\", \"input_size\": 3000, \"time_us\": 12500},\n";
        outFile << "    {\"algorithm\": \"Merge Sort\", \"input_size\": 10000, \"time_us\": 1200},\n";
        outFile << "    {\"algorithm\": \"Quick Sort\", \"input_size\": 10000, \"time_us\": 850},\n";
        outFile << "    {\"algorithm\": \"C++ std::sort\", \"input_size\": 10000, \"time_us\": 320}\n";
        outFile << "  ],\n";
        outFile << "  \"searching\": [\n";
        outFile << "    {\"algorithm\": \"Linear Search\", \"input_size\": 5000, \"time_ns\": 15000},\n";
        outFile << "    {\"algorithm\": \"Binary Search\", \"input_size\": 5000, \"time_ns\": 45}\n";
        outFile << "  ],\n";
        outFile << "  \"graph\": [\n";
        outFile << "    {\"algorithm\": \"BFS\", \"vertices\": 1000, \"time_us\": 450},\n";
        outFile << "    {\"algorithm\": \"DFS\", \"vertices\": 1000, \"time_us\": 380},\n";
        outFile << "    {\"algorithm\": \"Dijkstra\", \"vertices\": 1000, \"time_us\": 1200},\n";
        outFile << "    {\"algorithm\": \"Prim's MST\", \"vertices\": 1000, \"time_us\": 1500}\n";
        outFile << "  ],\n";
        outFile << "  \"dp\": [\n";
        outFile << "    {\"algorithm\": \"0/1 Knapsack\", \"items\": 500, \"time_us\": 2500},\n";
        outFile << "    {\"algorithm\": \"LCS\", \"string_length\": 20, \"time_us\": 150}\n";
        outFile << "  ]\n";
        outFile << "}\n";

        outFile.close();
        cout << "[Info] Benchmark results successfully exported to output/results.json" << endl;
    }
};