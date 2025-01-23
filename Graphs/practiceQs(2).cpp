//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <climits>
//
//using namespace std;
//
//class Graph {
//private:
//    vector<vector<int>> adjMatrix;
//    vector<vector<int>> adjList;
//    int V;  // Number of vertices
//
//public:
//    // Constructor to initialize the graph with the number of vertices
//    Graph(int V) {
//        this->V = V;
//        adjMatrix = vector<vector<int>>(V, vector<int>(V, 0));  // Initialize adjacency matrix with 0s
//        adjList = vector<vector<int>>(V);  // Initialize adjacency list
//    }
//
//    // Add edge to adjacency matrix
//    void addEdgeMatrix(int u, int v) {
//        adjMatrix[u][v] = 1;
//        adjMatrix[v][u] = 1;  // For undirected graph
//    }
//
//    // Add edge to adjacency list
//    void addEdgeList(int u, int v) {
//        adjList[u].push_back(v);
//        adjList[v].push_back(u);  // For undirected graph
//    }
//
//    // Print adjacency matrix
//    void printMatrix() {
//        for (int i = 0; i < V; i++) {
//            for (int j = 0; j < V; j++) {
//                cout << adjMatrix[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//
//    // Print adjacency list
//    void printList() {
//        for (int i = 0; i < V; i++) {
//            cout << "Vertex " << i << ": ";
//            for (int v : adjList[i]) {
//                cout << v << " ";
//            }
//            cout << endl;
//        }
//    }
//
//    // Count provinces (connected components)
//    int countProvinces() {
//        vector<bool> visited(V, false);
//        int count = 0;
//
//        for (int i = 0; i < V; i++) {
//            if (!visited[i]) {
//                dfs(i, visited);
//                count++;
//            }
//        }
//        return count;
//    }
//
//    // Depth-first search (DFS) helper function for counting provinces
//    void dfs(int v, vector<bool>& visited) {
//        visited[v] = true;
//        for (int u : adjList[v]) {
//            if (!visited[u]) {
//                dfs(u, visited);
//            }
//        }
//    }
//
//    // Dijkstra's algorithm for shortest path from source
//    vector<int> dijkstra(int src) {
//        vector<int> dist(V, INT_MAX);
//        dist[src] = 0;
//        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//        pq.push({ 0, src });
//
//        while (!pq.empty()) {
//            int u = pq.top().second;
//            pq.pop();
//
//            for (int v = 0; v < V; v++) {
//                if (adjMatrix[u][v] && dist[v] > dist[u] + 1) {
//                    dist[v] = dist[u] + 1;
//                    pq.push({ dist[v], v });
//                }
//            }
//        }
//        return dist;
//    }
//
//    // Find all paths between two nodes
//    void findPaths(int u, int v, vector<bool>& visited, vector<int>& path) {
//        visited[u] = true;
//        path.push_back(u);
//
//        if (u == v) {
//            for (int p : path) {
//                cout << p << " ";
//            }
//            cout << endl;
//        }
//        else {
//            for (int neighbor : adjList[u]) {
//                if (!visited[neighbor]) {
//                    findPaths(neighbor, v, visited, path);
//                }
//            }
//        }
//
//        path.pop_back();
//        visited[u] = false;
//    }
//
//    // Count connected components
//    int countConnectedComponents() {
//        vector<bool> visited(V, false);
//        int count = 0;
//        for (int i = 0; i < V; i++) {
//            if (!visited[i]) {
//                dfs(i, visited);
//                count++;
//            }
//        }
//        return count;
//    }
//
//    // BFS traversal
//    void bfs(int start) {
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
//        cout << endl;
//    }
//
//    // DFS traversal
//    void dfsTraversal(int start) {
//        vector<bool> visited(V, false);
//        dfsTraversalHelper(start, visited);
//        cout << endl;
//    }
//
//    // DFS traversal helper function
//    void dfsTraversalHelper(int v, vector<bool>& visited) {
//        visited[v] = true;
//        cout << v << " ";
//
//        for (int u : adjList[v]) {
//            if (!visited[u]) {
//                dfsTraversalHelper(u, visited);
//            }
//        }
//    }
//
//    // Detect cycle in an undirected graph
//    bool detectCycleUndirected() {
//        vector<bool> visited(V, false);
//        vector<int> parent(V, -1);
//
//        for (int i = 0; i < V; i++) {
//            if (!visited[i]) {
//                if (detectCycleUndirectedHelper(i, visited, parent)) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    // Cycle detection helper function for undirected graph
//    bool detectCycleUndirectedHelper(int v, vector<bool>& visited, vector<int>& parent) {
//        visited[v] = true;
//
//        for (int u : adjList[v]) {
//            if (!visited[u]) {
//                parent[u] = v;
//                if (detectCycleUndirectedHelper(u, visited, parent)) {
//                    return true;
//                }
//            }
//            else if (parent[v] != u) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    // Detect cycle in a directed graph
//    bool detectCycleDirected() {
//        vector<bool> visited(V, false);
//        vector<bool> inRecursionStack(V, false);  // Keep track of nodes in the recursion stack
//
//        for (int i = 0; i < V; i++) {
//            if (!visited[i]) {
//                if (detectCycleDirectedHelper(i, visited, inRecursionStack)) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    // Cycle detection helper function for directed graph
//    bool detectCycleDirectedHelper(int v, vector<bool>& visited, vector<bool>& inRecursionStack) {
//        visited[v] = true;
//        inRecursionStack[v] = true;
//
//        for (int u : adjList[v]) {
//            if (!visited[u] && detectCycleDirectedHelper(u, visited, inRecursionStack)) {
//                return true;
//            }
//            else if (inRecursionStack[u]) {
//                return true;
//            }
//        }
//
//        inRecursionStack[v] = false;
//        return false;
//    }
//
//    // Union Find data structure (Disjoint Set)
//    int findParent(int u, vector<int>& parent) {
//        if (parent[u] == u) {
//            return u;
//        }
//        return parent[u] = findParent(parent[u], parent);
//    }
//
//    void unionFind(int u, int v, vector<int>& parent, vector<int>& rank) {
//        int rootU = findParent(u, parent);
//        int rootV = findParent(v, parent);
//
//        if (rootU != rootV) {
//            if (rank[rootU] > rank[rootV]) {
//                parent[rootV] = rootU;
//            }
//            else if (rank[rootU] < rank[rootV]) {
//                parent[rootU] = rootV;
//            }
//            else {
//                parent[rootV] = rootU;
//                rank[rootU]++;
//            }
//        }
//    }
//
//    // Topological Sort (Kahn's Algorithm)
//    void topologicalSort() {
//        vector<int> inDegree(V, 0);
//        for (int u = 0; u < V; u++) {
//            for (int v : adjList[u]) {
//                inDegree[v]++;
//            }
//        }
//
//        queue<int> q;
//        for (int i = 0; i < V; i++) {
//            if (inDegree[i] == 0) {
//                q.push(i);
//            }
//        }
//
//        while (!q.empty()) {
//            int v = q.front();
//            q.pop();
//            cout << v << " ";
//
//            for (int u : adjList[v]) {
//                if (--inDegree[u] == 0) {
//                    q.push(u);
//                }
//            }
//        }
//        cout << endl;
//    }
//    //void printDegrees() {
//    //    for (int i = 0; i < numVertices; ++i) {
//    //        int degree = 0;
//    //        for (int j = 0; j < numVertices; ++j) {
//    //            degree += adjMatrix[i][j]; // Count edges incident to vertex i
//    //        }
//    //        cout << "Degree of vertex " << i << ": " << degree << endl;
//    //    }
//    //}
//    // Check if there is a path between two vertices
//    bool isPath(int u, int v) {
//        vector<bool> visited(V, false);
//        queue<int> q;
//        visited[u] = true;
//        q.push(u);
//
//        while (!q.empty()) {
//            int node = q.front();
//            q.pop();
//
//            if (node == v) {
//                return true;
//            }
//
//            for (int neighbor : adjList[node]) {
//                if (!visited[neighbor]) {
//                    visited[neighbor] = true;
//                    q.push(neighbor);
//                }
//            }
//        }
//        return false;
//    }
//
//    // Hamiltonian Cycle (simplified approach)
//    bool hamiltonianCycle() {
//        vector<int> path(V, -1);
//        path[0] = 0;  // Start from vertex 0
//
//        if (hamiltonianCycleHelper(0, path)) {
//            for (int v : path) {
//                cout << v << " ";
//            }
//            cout << endl;
//            return true;
//        }
//        return false;
//    }
//
//    // Hamiltonian cycle helper function
//    bool hamiltonianCycleHelper(int pos, vector<int>& path) {
//        if (pos == V) {
//            return true;
//        }
//
//        for (int v = 1; v < V; v++) {
//            if (isSafe(v, path, pos)) {
//                path[pos] = v;
//
//                if (hamiltonianCycleHelper(pos + 1, path)) {
//                    return true;
//                }
//
//                path[pos] = -1;  // Backtrack
//            }
//        }
//        return false;
//    }
//
//    // Helper function to check if a vertex can be added to the Hamiltonian cycle
//    bool isSafe(int v, vector<int>& path, int pos) {
//        if (adjMatrix[path[pos - 1]][v] == 0) {
//            return false;
//        }
//
//        for (int i = 0; i < pos; i++) {
//            if (path[i] == v) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    // Detect closed island
//    int countClosedIslands() {
//        vector<vector<bool>> visited(V, vector<bool>(V, false));
//        int count = 0;
//
//        for (int i = 1; i < V - 1; i++) {
//            for (int j = 1; j < V - 1; j++) {
//                if (!visited[i][j] && adjMatrix[i][j] == 1) {
//                    dfsClosedIsland(i, j, visited);
//                    count++;
//                }
//            }
//        }
//        return count;
//    }
//
//    void dfsClosedIsland(int i, int j, vector<vector<bool>>& visited) {
//        if (i < 0 || i >= V || j < 0 || j >= V || adjMatrix[i][j] == 0 || visited[i][j]) {
//            return;
//        }
//
//        visited[i][j] = true;
//
//        dfsClosedIsland(i + 1, j, visited);
//        dfsClosedIsland(i - 1, j, visited);
//        dfsClosedIsland(i, j + 1, visited);
//        dfsClosedIsland(i, j - 1, visited);
//    }
//
//    // Rotten Tomatoes (spread of rot from one point)
//    void rottenTomatoes() {
//        queue<pair<int, int>> q;
//        vector<vector<bool>> visited(V, vector<bool>(V, false));
//
//        // Initialize with all rotten tomatoes and their positions
//        for (int i = 0; i < V; i++) {
//            for (int j = 0; j < V; j++) {
//                if (adjMatrix[i][j] == 1) {
//                    q.push({ i, j });
//                    visited[i][j] = true;
//                }
//            }
//        }
//
//        while (!q.empty()) {
//            int x = q.front().first;
//            int y = q.front().second;
//            q.pop();
//
//            // Process adjacent cells
//            for (int i = -1; i <= 1; i++) {
//                for (int j = -1; j <= 1; j++) {
//                    if (x + i >= 0 && x + i < V && y + j >= 0 && y + j < V &&
//                        adjMatrix[x + i][y + j] == 0 && !visited[x + i][y + j]) {
//                        visited[x + i][y + j] = true;
//                        q.push({ x + i, y + j });
//                    }
//                }
//            }
//        }
//    }
//};
//
//int main() {
//    Graph g(5);
//
//    // Example usage
//    g.addEdgeMatrix(0, 1);
//    g.addEdgeMatrix(1, 2);
//    g.addEdgeMatrix(2, 3);
//    g.addEdgeMatrix(3, 4);
//
//    g.printMatrix();
//    g.printList();
//
//    // Count connected components (provinces)
//    cout << "Provinces: " << g.countProvinces() << endl;
//
//    // Dijkstra's shortest path from vertex 0
//    vector<int> dist = g.dijkstra(0);
//    for (int i = 0; i < 5; i++) {
//        cout << "Distance from 0 to " << i << ": " << dist[i] << endl;
//    }
//
//    // DFS Traversal
//    g.dfsTraversal(0);
//
//    // BFS Traversal
//    g.bfs(0);
//
//    // Check for cycle in an undirected graph
//    if (g.detectCycleUndirected()) {
//        cout << "Cycle detected in undirected graph" << endl;
//    }
//    else {
//        cout << "No cycle detected in undirected graph" << endl;
//    }
//
//    // Hamiltonian cycle check
//    if (g.hamiltonianCycle()) {
//        cout << "Hamiltonian cycle found" << endl;
//    }
//    else {
//        cout << "No Hamiltonian cycle" << endl;
//    }
//
//    return 0;
//}
