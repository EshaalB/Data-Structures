//#include <iostream>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//class Graph {
//public:
//    int V;  // Number of vertices
//    int** adjMatrix;  // Adjacency Matrix
//    vector<int>* adjList;  // Adjacency List
//
//    // Constructor for adjacency matrix representation
//    Graph(int V) {
//        this->V = V;
//        adjMatrix = new int* [V];
//        for (int i = 0; i < V; i++) {
//            adjMatrix[i] = new int[V] {0};  // Initialize with 0
//        }
//        adjList = new vector<int>[V];  // Initialize adjacency list
//    }
//
//    // Destructor to deallocate memory
//    ~Graph() {
//        for (int i = 0; i < V; i++) {
//            delete[] adjMatrix[i];
//        }
//        delete[] adjMatrix;
//        delete[] adjList;
//    }
//
//    // Add directed edge to the graph (both matrix and list)
//    void addEdge(int u, int v) {
//        adjMatrix[u][v] = 1;
//        adjList[u].push_back(v);
//    }
//
//    // Remove directed edge
//    void removeEdge(int u, int v) {
//        adjMatrix[u][v] = 0;
//        adjList[u].erase(remove(adjList[u].begin(), adjList[u].end(), v), adjList[u].end());
//    }
//
//    // Print Adjacency Matrix
//    void printAdjMatrix() {
//        for (int i = 0; i < V; i++) {
//            for (int j = 0; j < V; j++) {
//                cout << adjMatrix[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//
//    // Print Adjacency List
//    void printAdjList() {
//        for (int i = 0; i < V; i++) {
//            cout << i << " -> ";
//            for (int v : adjList[i]) {
//                cout << v << " ";
//            }
//            cout << endl;
//        }
//    }
//
//    // Depth First Search (DFS) Traversal (Recursive)
//    void DFS(int start) {
//        vector<bool> visited(V, false);
//        DFSUtil(start, visited);
//    }
//
//    void DFSUtil(int v, vector<bool>& visited) {
//        visited[v] = true;
//        cout << v << " ";
//
//        for (int u : adjList[v]) {
//            if (!visited[u]) {
//                DFSUtil(u, visited);
//            }
//        }
//    }
//
//    // Breadth First Search (BFS) Traversal
//    void BFS(int start) {
//        vector<bool> visited(V, false);
//        queue<int> q;
//        visited[start] = true;
//        q.push(start);
//
//        while (!q.empty()) {
//            int v = q.front();
//            q.pop();
//            cout << v << " ";
//
//            for (int u : adjList[v]) {
//                if (!visited[u]) {
//                    visited[u] = true;
//                    q.push(u);
//                }
//            }
//        }
//    }
//
//    // Check if the graph has a cycle (DFS for directed graphs)
//    bool detectCycle() {
//        vector<bool> visited(V, false);
//        vector<bool> inRecursionStack(V, false);
//        for (int i = 0; i < V; i++) {
//            if (DFSUtilCycle(i, visited, inRecursionStack)) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    bool DFSUtilCycle(int v, vector<bool>& visited, vector<bool>& inRecursionStack) {
//        if (inRecursionStack[v]) return true;
//        if (visited[v]) return false;
//
//        visited[v] = true;
//        inRecursionStack[v] = true;
//
//        for (int u : adjList[v]) {
//            if (DFSUtilCycle(u, visited, inRecursionStack)) {
//                return true;
//            }
//        }
//        inRecursionStack[v] = false;
//        return false;
//    }
//
//    // Find connected components in an undirected graph (DFS)
//    void connectedComponents() {
//        vector<bool> visited(V, false);
//        int count = 0;
//        for (int i = 0; i < V; i++) {
//            if (!visited[i]) {
//                cout << "Component " << ++count << ": ";
//                DFSConnected(i, visited);
//                cout << endl;
//            }
//        }
//    }
//
//    void DFSConnected(int v, vector<bool>& visited) {
//        visited[v] = true;
//        cout << v << " ";
//        for (int u : adjList[v]) {
//            if (!visited[u]) {
//                DFSConnected(u, visited);
//            }
//        }
//    }//int computeDiameter() {
//    //    int diameter = 0;
//
//    //    // Run BFS from each vertex to find the longest shortest path
//    //    for (int i = 0; i < vertices; ++i) {
//    //        vector<int> dist = BFS(i);  // Get the shortest distances from vertex i
//
//    //        // Find the maximum distance in the dist vector
//    //        int maxDist = 0;  // Initialize maxDist to 0 (smallest possible distance)
//    //        for (int j = 0; j < numVertices; ++j) {
//    //            if (dist[j] != INT_MAX) {  // Ignore unreachable nodes (in case of disconnected graph)
//    //                maxDist = (dist[j] > maxDist) ? dist[j] : maxDist;  // Update maxDist
//    //            }
//    //        }
//
//    //        // Update the diameter if the max distance from vertex i is greater than the current diameter
//    //        diameter = (maxDist > diameter) ? maxDist : diameter;
//    //    }
//
//    //    return diameter;
//    //}
//
//    // Topological Sort (for Directed Acyclic Graph)
//    void topologicalSort() {
//        vector<bool> visited(V, false);
//        stack<int> topoStack;
//
//        for (int i = 0; i < V; i++) {
//            if (!visited[i]) {
//                topologicalSortUtil(i, visited, topoStack);
//            }
//        }
//
//        while (!topoStack.empty()) {
//            cout << topoStack.top() << " ";
//            topoStack.pop();
//        }
//    }
//
//    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& topoStack) {
//        visited[v] = true;
//        for (int u : adjList[v]) {
//            if (!visited[u]) {
//                topologicalSortUtil(u, visited, topoStack);
//            }
//        }
//        topoStack.push(v);
//    }
//
//    // Check if a path exists between two nodes (using DFS)
//    bool isPath(int start, int end) {
//        vector<bool> visited(V, false);
//        return isPathUtil(start, end, visited);
//    }
//
//    bool isPathUtil(int v, int end, vector<bool>& visited) {
//        if (v == end) return true;
//        visited[v] = true;
//
//        for (int u : adjList[v]) {
//            if (!visited[u]) {
//                if (isPathUtil(u, end, visited)) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    // Find all paths between two nodes
//    void findAllPaths(int start, int end) {
//        vector<bool> visited(V, false);
//        vector<int> path;
//        findAllPathsUtil(start, end, visited, path);
//    }
//
//    void findAllPathsUtil(int v, int end, vector<bool>& visited, vector<int>& path) {
//        visited[v] = true;
//        path.push_back(v);
//
//        if (v == end) {
//            for (int i : path) {
//                cout << i << " ";
//            }
//            cout << endl;
//        }
//        else {
//            for (int u : adjList[v]) {
//                if (!visited[u]) {
//                    findAllPathsUtil(u, end, visited, path);
//                }
//            }
//        }
//
//        path.pop_back();
//        visited[v] = false;
//    }
//
//    // Find strongly connected components (Kosaraju's algorithm)
//    void stronglyConnectedComponents() {
//        stack<int> Stack;
//        vector<bool> visited(V, false);
//
//        // Step 1: Fill vertices in Stack according to their finishing times
//        for (int i = 0; i < V; i++) {
//            if (!visited[i]) {
//                fillOrder(i, visited, Stack);
//            }
//        }
//
//        // Step 2: Transpose the graph
//        Graph gTranspose(V);
//        transposeGraph(gTranspose);
//
//        // Step 3: Process all vertices in order defined by Stack
//        fill(visited.begin(), visited.end(), false);
//        while (!Stack.empty()) {
//            int v = Stack.top();
//            Stack.pop();
//
//            if (!visited[v]) {
//                gTranspose.DFSUtil(v, visited);
//                cout << endl;
//            }
//        }
//    }
//
//    void fillOrder(int v, vector<bool>& visited, stack<int>& Stack) {
//        visited[v] = true;
//        for (int u : adjList[v]) {
//            if (!visited[u]) {
//                fillOrder(u, visited, Stack);
//            }
//        }
//        Stack.push(v);
//    }
//
//    void transposeGraph(Graph& g) {
//        for (int i = 0; i < V; i++) {
//            for (int j : adjList[i]) {
//                g.addEdge(j, i);
//            }
//        }
//    }
//
//    // Detect Bridge in an undirected graph using DFS
//    void findBridges() {
//        vector<bool> visited(V, false);
//        vector<int> discoveryTime(V, -1);
//        vector<int> lowTime(V, -1);
//        vector<pair<int, int>> bridges;
//
//        int time = 0;
//        for (int i = 0; i < V; i++) {
//            if (!visited[i]) {
//                DFSForBridges(i, visited, discoveryTime, lowTime, bridges, time);
//            }
//        }
//
//        for (auto bridge : bridges) {
//            cout << bridge.first << " - " << bridge.second << endl;
//        }
//    }
//
//    void DFSForBridges(int u, vector<bool>& visited, vector<int>& discoveryTime, vector<int>& lowTime,
//        vector<pair<int, int>>& bridges, int& time) {
//        visited[u] = true;
//        discoveryTime[u] = lowTime[u] = time++;
//
//        for (int v : adjList[u]) {
//            if (!visited[v]) {
//                DFSForBridges(v, visited, discoveryTime, lowTime, bridges, time);
//                lowTime[u] = min(lowTime[u], lowTime[v]);
//
//                if (lowTime[v] > discoveryTime[u]) {
//                    bridges.push_back({ u, v });
//                }
//            }
//            else if (v != u) {
//                lowTime[u] = min(lowTime[u], discoveryTime[v]);
//            }
//        }
//    }
//};
//
//int main() {
//    Graph g(5);
//
//    g.addEdge(0, 1);
//    g.addEdge(0, 4);
//    g.addEdge(1, 2);
//    g.addEdge(1, 3);
//    g.addEdge(1, 4);
//    g.addEdge(3, 0);
//    g.addEdge(4, 2);
//    g.addEdge(4, 3);
//
//    cout << "Adjacency Matrix: \n";
//    g.printAdjMatrix();
//    cout << "\nAdjacency List: \n";
//    g.printAdjList();
//
//    cout << "\nDFS (starting from node 0): ";
//    g.DFS(0);
//    cout << "\nBFS (starting from node 0): ";
//    g.BFS(0);
//
//    cout << "\nCycle Detection: ";
//    if (g.detectCycle()) {
//        cout << "Graph has a cycle." << endl;
//    }
//    else {
//        cout << "No cycle detected." << endl;
//    }
//
//    cout << "\nConnected Components: ";
//    g.connectedComponents();
//
//    cout << "\nTopological Sort: ";
//    g.topologicalSort();
//
//    cout << "\nPath existence between node 0 and 3: ";
//    if (g.isPath(0, 3)) {
//        cout << "Path exists." << endl;
//    }
//    else {
//        cout << "No path exists." << endl;
//    }
//
//    cout << "\nAll Paths between node 0 and 3: ";
//    g.findAllPaths(0, 3);
//
//    cout << "\nStrongly Connected Components: ";
//    g.stronglyConnectedComponents();
//
//    cout << "\nBridges in the graph: ";
//    g.findBridges();
//
//    return 0;
//}
