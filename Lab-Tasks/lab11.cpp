#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// class to represent class with vertices matrix and list 
class Graph {
private:
    int vertices;                        
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;         

public:
    Graph(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
        adjList.resize(v);
    }

    // undirected edge for matrix 
    void addEdgeMatrix(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Since it's undirected
    }

    // undirected edge for list 
    void addEdgeList(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Since it's undirected
    }

    // print the adjacency matrix
    void printMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // print the adjacency list
    void printList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // Count connected components using DFS
    void countConnectedComponents() {
        vector<bool> visited(vertices, false);
        int components = 0;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited);
                components++;
            }
        }
        cout << "Number of connected components: " << components << endl;
    }

    // Depth-First Search (DFS)
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int neighbor : adjList[v]) {
            if (!visited[neighbor])  DFSUtil(neighbor, visited);
       
        }
    }
   // Topological Sorting using DFS
    void topologicalSort() {
        vector<bool> visited(vertices, false);
        stack<int> Stack;

    
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                tpSort(i, visited, Stack);
            }
        }

        // Output the topological order
        cout << "Topological Order: ";
        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << endl;
    }

    // Helper function for topological sorting
    void tpSort(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        
        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                tpSort(neighbor, visited, Stack);
            }
        }

        
        Stack.push(v);
    }
    int BFS(int start, int end) {
    vector<bool> visited(vertices, false);
    queue<pair<int, int>> q;    
    q.push({ start, 0 });       
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;   
        q.pop();

        if (node == end) {
            return distance;   
        }

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({ neighbor, distance + 1 });  
            }
        }
    }
    return -1;  
}


    // No of stations using BFS 
    int findStations(int start, int end) {
        int distance = BFS(start, end);
        if (distance != -1) {
            return distance-1;  
        }
        else {
            return -1;  
        }
    }
};

// Main 
int main() {
    // Problem 1: Graph representation using adjacency matrix and list
    Graph g1(5);
    g1.addEdgeMatrix(0, 1);
    g1.addEdgeMatrix(0, 2);
    g1.addEdgeMatrix(1, 2);
    g1.addEdgeMatrix(3, 4);
    g1.addEdgeList(0, 1);
    g1.addEdgeList(0, 2);
    g1.addEdgeList(1, 2);
    g1.addEdgeList(3, 4);

    g1.printMatrix();
    g1.printList();
    cout << endl;

    // Problem 2: Count connected components
    g1.countConnectedComponents();

    // Problem 3: Topological sorting for a DAG
    Graph g2(6);
    g2.addEdgeList(5, 2);
    g2.addEdgeList(5, 0);
    g2.addEdgeList(4, 0);
    g2.addEdgeList(4, 1);
    g2.addEdgeList(2, 3);
    g2.addEdgeList(3, 1);
    g2.topologicalSort();
    cout << endl;

    // Problem 5: Finding stations between nodes
    Graph subway(5);
    subway.addEdgeList(0, 1);  // Station A-B
    subway.addEdgeList(1, 2);  // Station B-C
    subway.addEdgeList(2, 3);  // Station C-D
    subway.addEdgeList(3, 4);  // Station D-E

    int stations = subway.findStations(0, 2);  // A to C
    cout << "Number of stations between A and C: " << stations << endl;

    return 0;
}
