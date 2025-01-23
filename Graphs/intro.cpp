#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

template <typename V>
class Graph {
    vector<V> vertices;                    // List of vertices
    vector<vector<int>> adjMat;            // Adjacency matrix
    vector<vector<V>> adjList;             // Adjacency list
    int weight;

public:
    Graph(int v) {
        adjMat.resize(v, vector<int>(v, 0));
        adjList.resize(v);
    }

    void addVertex(V vertex) {
        vertices.push_back(vertex);
    }

    int getVertexIndex(V vertex) {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] == vertex) return i;
        }
        return -1;
    }

    void addEdgeList(V u, V v, bool directionCheck) {
        int idxU = getVertexIndex(u);
        int idxV = getVertexIndex(v);
        if (idxU == -1 || idxV == -1) {
            cout << "Error: Invalid vertex names." << endl;
            return;
        }
        adjList[idxU].push_back(v);
        if (directionCheck == 0) adjList[idxV].push_back(u);
    }

    // Cycle Detection in Undirected Graph using BFS
    bool isCyclicUndirectedBFS() {
        vector<bool> visited(vertices.size(), false);
        for (int i = 0; i < vertices.size(); i++) {
            if (!visited[i]) {
                if (checkCycleBFS(i, visited)) return true;
            }
        }
        return false;
    }

    bool checkCycleBFS(int src, vector<bool>& visited) {
        queue<pair<int, int>> q; // Pair of current vertex and its parent
        visited[src] = true;
        q.push({ src, -1 });

        while (!q.empty()) {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (V neighbor : adjList[curr]) {
                int neighborIndex = getVertexIndex(neighbor);
                if (!visited[neighborIndex]) {
                    visited[neighborIndex] = true;
                    q.push({ neighborIndex, curr });
                }
                else if (neighborIndex != parent) {
                    return true; // Cycle found
                }
            }
        }
        return false;
    }

    // Cycle Detection in Directed Graph using DFS
    bool isCyclicDirectedDFS() {
        vector<bool> visited(vertices.size(), false);
        vector<bool> recStack(vertices.size(), false);

        for (int i = 0; i < vertices.size(); i++) {
            if (!visited[i]) {
                if (checkCycleDFS(i, visited, recStack)) return true;
            }
        }
        return false;
    }

    bool checkCycleDFS(int vertex, vector<bool>& visited, vector<bool>& recStack) {
        visited[vertex] = true;
        recStack[vertex] = true;

        for (V neighbor : adjList[vertex]) {
            int neighborIndex = getVertexIndex(neighbor);
            if (!visited[neighborIndex]) {
                if (checkCycleDFS(neighborIndex, visited, recStack)) return true;
            }
            else if (recStack[neighborIndex]) {
                return true; // Cycle found
            }
        }

        recStack[vertex] = false;
        return false;
    }

    // Topological Sort using Kahn's Algorithm
    vector<V> topologicalSortKahn() {
        vector<int> inDegree(vertices.size(), 0);
        for (int i = 0; i < vertices.size(); i++) {
            for (V neighbor : adjList[i]) {
                int neighborIndex = getVertexIndex(neighbor);
                inDegree[neighborIndex]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<V> topoOrder;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            topoOrder.push_back(vertices[curr]);

            for (V neighbor : adjList[curr]) {
                int neighborIndex = getVertexIndex(neighbor);
                inDegree[neighborIndex]--;
                if (inDegree[neighborIndex] == 0) q.push(neighborIndex);
            }
        }

        if (topoOrder.size() != vertices.size()) {
            cout << "Error: Graph is not a Directed Acyclic Graph (DAG)." << endl;
            return {};
        }

        return topoOrder;
    }

    // Topological Sort using DFS
    void topologicalSortDFSUtil(int vertex, vector<bool>& visited, stack<V>& stack) {
        visited[vertex] = true;

        for (V neighbor : adjList[vertex]) {
            int neighborIndex = getVertexIndex(neighbor);
            if (!visited[neighborIndex]) {
                topologicalSortDFSUtil(neighborIndex, visited, stack);
            }
        }

        stack.push(vertices[vertex]);
    }

    vector<V> topologicalSortDFS() {
        vector<bool> visited(vertices.size(), false);
        stack<V> stack;

        for (int i = 0; i < vertices.size(); i++) {
            if (!visited[i]) {
                topologicalSortDFSUtil(i, visited, stack);
            }
        }

        vector<V> topoOrder;
        while (!stack.empty()) {
            topoOrder.push_back(stack.top());
            stack.pop();
        }

        return topoOrder;
    }
    void floydWarshallShortestPaths() {
        int V = vertices.size();
        vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

        // Initialize the distance matrix based on the adjacency matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i == j) {
                    dist[i][j] = 0; // Distance to self is 0
                }
                else if (adjMat[i][j] != 0) {
                    dist[i][j] = adjMat[i][j]; // Direct edge weight
                }
            }
        }

        // Apply Floyd-Warshall Algorithm
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Print the shortest path matrix
        cout << "Shortest Path Matrix (All-Pairs):" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INT_MAX) {
                    cout << "INF ";
                }
                else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    // Minimum Spanning Tree using Prim's Algorithm
    void primsAlgorithm() {
        int numVertices = vertices.size();
        vector<bool> inMST(numVertices, false); // Tracks whether a vertex is in MST
        vector<int> key(numVertices, INT_MAX); // Min weights to include each vertex
        vector<int> parent(numVertices, -1);  // Stores the MST structure
        key[0] = 0; // Start from the first vertex

        for (int count = 0; count < numVertices - 1; count++) {
            // Find the vertex with the smallest key value not yet in MST
            int u = -1;
            for (int v = 0; v < numVertices; v++) {
                if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                    u = v;
                }
            }

            inMST[u] = true; // Include this vertex in MST

            // Update keys and parents for neighbors of 'u'
            for (auto neighbor : adjList[u]) {
                int neighborIndex = getVertexIndex(neighbor);
                int weight = adjMat[u][neighborIndex];

                // Update if the edge is smaller and neighbor is not in MST
                if (!inMST[neighborIndex] && weight < key[neighborIndex]) {
                    key[neighborIndex] = weight;
                    parent[neighborIndex] = u;
                }
            }
        }

        // Print the MST
        cout << "Edges in MST:\n";
        for (int i = 1; i < numVertices; i++) {
            cout << vertices[parent[i]] << " - " << vertices[i] << " (Weight: " << adjMat[parent[i]][i] << ")\n";
        }
    }

    // Minimum Spanning Tree using Kruskal's Algorithm
    struct Edge {
        int src, dest, weight;
    };

    vector<Edge> edges;

    void addEdgeForKruskal(int src, int dest, int weight) {
        edges.push_back({ src, dest, weight });
    }

    int findParent(int vertex, vector<int>& parent) {
        if (parent[vertex] == vertex) return vertex;
        return parent[vertex] = findParent(parent[vertex], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        int uRoot = findParent(u, parent);
        int vRoot = findParent(v, parent);

        if (rank[uRoot] < rank[vRoot]) {
            parent[uRoot] = vRoot;
        }
        else if (rank[uRoot] > rank[vRoot]) {
            parent[vRoot] = uRoot;
        }
        else {
            parent[vRoot] = uRoot;
            rank[uRoot]++;
        }
    }

    void kruskalsAlgorithm() {
        vector<int> parent(vertices.size());
        vector<int> rank(vertices.size(), 0);
        for (int i = 0; i < vertices.size(); i++) parent[i] = i;

        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
            });

        cout << "Edges in MST:\n";
        for (Edge edge : edges) {
            int uRoot = findParent(edge.src, parent);
            int vRoot = findParent(edge.dest, parent);

            if (uRoot != vRoot) {
                cout << vertices[edge.src] << " - " << vertices[edge.dest] << "\n";
                unionSet(uRoot, vRoot, parent, rank);
            }
        }
    }

    // Bridges in Graph
    void findBridgesUtil(int vertex, int parent, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<pair<V, V>>& bridges) {
        static int time = 0;
        visited[vertex] = true;
        disc[vertex] = low[vertex] = ++time;

        for (V neighbor : adjList[vertex]) {
            int neighborIndex = getVertexIndex(neighbor);
            if (!visited[neighborIndex]) {
                findBridgesUtil(neighborIndex, vertex, visited, disc, low, bridges);

                low[vertex] = min(low[vertex], low[neighborIndex]);

                if (low[neighborIndex] > disc[vertex]) {
                    bridges.push_back({ vertices[vertex], vertices[neighborIndex] });
                }
            }
            else if (neighborIndex != parent) {
                low[vertex] = min(low[vertex], disc[neighborIndex]);
            }
        }
    }
    // Articulation Points in Graph
    void findArticulationPointsUtil(int vertex, int parent, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<bool>& articulation) {
        static int time = 0;
        visited[vertex] = true;
        disc[vertex] = low[vertex] = ++time;
        int children = 0;

        for (V neighbor : adjList[vertex]) {
            int neighborIndex = getVertexIndex(neighbor);
            if (!visited[neighborIndex]) {
                children++;
                findArticulationPointsUtil(neighborIndex, vertex, visited, disc, low, articulation);

                low[vertex] = min(low[vertex], low[neighborIndex]);

                if (parent != -1 && low[neighborIndex] >= disc[vertex]) {
                    articulation[vertex] = true;
                }
            }
            else if (neighborIndex != parent) {
                low[vertex] = min(low[vertex], disc[neighborIndex]);
            }
        }

        if (parent == -1 && children > 1) {
            articulation[vertex] = true;
        }
    }

    void findArticulationPoints() {
        vector<bool> visited(vertices.size(), false);
        vector<int> disc(vertices.size(), -1);
        vector<int> low(vertices.size(), -1);
        vector<bool> articulation(vertices.size(), false);

        for (int i = 0; i < vertices.size(); i++) {
            if (!visited[i]) {
                findArticulationPointsUtil(i, -1, visited, disc, low, articulation);
            }
        }

        cout << "Articulation Points:\n";
        for (int i = 0; i < vertices.size(); i++) {
            if (articulation[i]) {
                cout << vertices[i] << "\n";
            }
        }
    }
    void kosarajuDFS1(int vertex, vector<bool>& visited, stack<int>& finishOrder) {
        visited[vertex] = true;

        for (V neighbor : adjList[vertex]) {
            int neighborIndex = getVertexIndex(neighbor);
            if (!visited[neighborIndex]) {
                kosarajuDFS1(neighborIndex, visited, finishOrder);
            }
        }

        finishOrder.push(vertex);
    }

    void kosarajuDFS2(int vertex, vector<bool>& visited, vector<vector<V>>& transpose, vector<V>& scc) {
        visited[vertex] = true;
        scc.push_back(vertices[vertex]);

        for (V neighbor : transpose[vertex]) {
            int neighborIndex = getVertexIndex(neighbor);
            if (!visited[neighborIndex]) {
                kosarajuDFS2(neighborIndex, visited, transpose, scc);
            }
        }
    }

    void kosarajusAlgorithm() {
        vector<bool> visited(vertices.size(), false);
        stack<int> finishOrder;

        for (int i = 0; i < vertices.size(); i++) {
            if (!visited[i]) {
                kosarajuDFS1(i, visited, finishOrder);
            }
        }

        vector<vector<V>> transpose(vertices.size());
        for (int i = 0; i < vertices.size(); i++) {
            for (V neighbor : adjList[i]) {
                int neighborIndex = getVertexIndex(neighbor);
                transpose[neighborIndex].push_back(vertices[i]);
            }
        }

        fill(visited.begin(), visited.end(), false);
        cout << "Strongly Connected Components:\n";

        while (!finishOrder.empty()) {
            int vertex = finishOrder.top();
            finishOrder.pop();

            if (!visited[vertex]) {
                vector<V> scc;
                kosarajuDFS2(vertex, visited, transpose, scc);
                for (V node : scc) {
                    cout << node << " ";
                }
                cout << "\n";
            }
        }
    }
    int computeGraphDiameter() { // O(V)^3
        int maxDiameter = 0;

        for (int i = 0; i < vertices.size(); i++) {
            vector<int> dist(vertices.size(), -1);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (V neighbor : adjList[curr]) {
                    int neighborIndex = getVertexIndex(neighbor);
                    if (dist[neighborIndex] == -1) {
                        dist[neighborIndex] = dist[curr] + 1;
                        q.push(neighborIndex);
                    }
                }
            }

            // Manually calculate the maximum distance from the current vertex
            int localMax = 0;
            for (int j = 0; j < dist.size(); j++) {
                if (dist[j] > localMax) {
                    localMax = dist[j];
                }
            }

            if (localMax > maxDiameter) {
                maxDiameter = localMax;
            }
        }

        return maxDiameter;
    }

};

int main() {
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph<string> g(numVertices);

    cout << "Enter the names of the vertices:" << endl;
    for (int i = 0; i < numVertices; i++) {
        string vertexName;
        cin >> vertexName;
        g.addVertex(vertexName);
    }

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (u v) and direction (1 for directed, 0 for undirected):" << endl;
    for (int i = 0; i < numEdges; i++) {
        string u, v;
        int direction;
        cin >> u >> v >> direction;
        g.addEdgeList(u, v, direction);
    }

    cout << "Checking for cycle in undirected graph using BFS: ";
    if (g.isCyclicUndirectedBFS()) {
        cout << "Cycle detected." << endl;
    }
    else {
        cout << "No cycle found." << endl;
    }

    cout << "Checking for cycle in directed graph using DFS: ";
    if (g.isCyclicDirectedDFS()) {
        cout << "Cycle detected." << endl;
    }
    else {
        cout << "No cycle found." << endl;
    }

    return 0;
}
