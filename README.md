# ⚡ Interactive Algorithm Benchmarking & Visualization Suite

A high-performance algorithm benchmarking platform built with a **C++ Core Engine**, **Python Flask Backend**, and an **Interactive Web UI**. Designed for academic algorithms sessional evaluation and as a strong foundation for future Machine Learning engineering work.

---

## 🚀 Key Features

* **C++17 Engine:** High-precision execution time measurement (`std::chrono`) for raw performance optimization.
* **Full Algorithm Coverage:**
  * **Searching:** Linear Search, Binary Search
  * **Sorting:** Bubble Sort, Merge Sort, Quick Sort, C++ `std::sort` (IntroSort)
  * **Graph Algorithms:** BFS, DFS, Dijkstra's Shortest Path, Prim's MST
  * **Dynamic Programming:** 0/1 Knapsack, Longest Common Subsequence (LCS)
* **Real-Time Web Interface:** Dynamic execution from a modern Tailwind CSS UI powered by Python Flask and subprocess bridge.

---

## 🛠️ Tech Stack

* **Backend / Core:** C++17
* **API / Bridge:** Python (Flask)
* **Frontend:** HTML5, JavaScript, Tailwind CSS
* **Environment:** macOS & VS Code

---

## ⚙️ Local Setup & Installation
 **Clone the Repository:**
   ```bash
   git clone https://github.com/sr-sahed/AlgoBenchmark.git
   cd AlgoBenchmark
   ```
1. Compile the C++ Engine:

```Bash
mkdir -p output
g++ -std=c++17 src/main.cpp -o output/benchmark
```
2. Install Python Dependencies (Flask):

```Bash
pip3 install flask
```
3. Run the Application:

```Bash
python3 app.py
```
4. Open in Browser:
Go to http://localhost:5000 to interact with the dashboard.

💡 Why This Project?
For an ML Engineer, understanding algorithmic time/space complexities, graph structures, and dynamic programming optimization is crucial for building scalable data pipelines and efficient models. This project demonstrates the practical application of low-level optimization combined with modern web interfaces.
