#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }

    // Helper function to perform BFS and return distances from a source
    vector<int> bfs(int src) {
        vector<int> dist(V, INT_MAX); // Initialize distances to "infinity"
        queue<int> q;

        dist[src] = 0; // Distance to itself is 0
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == INT_MAX) { // If not visited
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return dist;
    }

    int findSafestHotel(int hA, int hB, vector<int> hotels) {
        // Perform BFS from hA and hB
        vector<int> distFromA = bfs(hA);
        vector<int> distFromB = bfs(hB);

        int minRisk = INT_MAX;
        int safestHotel = -1;

        // Find the hotel with the minimum combined risk
        for (int hotel : hotels) {
            int totalRisk = distFromA[hotel] + distFromB[hotel];
            if (totalRisk < minRisk) {
                minRisk = totalRisk;
                safestHotel = hotel;
            }
        }

        return safestHotel;
    }
};

int main() {
    // Example graph (adjacency list representation)
    Graph g(8); // 8 vertices (0 to 7)

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    int hA = 0; // Ahmed's house
    int hB = 7; // Baber's house
    vector<int> hotels = { 3, 4, 5, 6 }; // Hotel vertices

    int safestHotel = g.findSafestHotel(hA, hB, hotels);
    cout << "Safest hotel is: " << safestHotel
