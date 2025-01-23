//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n, m; // n = number of nodes, m = number of edges
//    cin >> n >> m;
//
//    // Adjacency Matrix
//    vector<vector<int>> adjMat(n, vector<int>(n, 0));
//    int u, v;
//
//    // Input for Adjacency Matrix
//    for (int i = 0; i < m; i++) {
//        cin >> u >> v;
//        adjMat[u][v] = 1;
//        adjMat[v][u] = 1; // For undirected graph
//    }
//
//    // Print Adjacency Matrix
//    cout << "Adjacency Matrix:\n";
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << adjMat[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    // Adjacency List
//    vector<vector<int>> adjList(n);
//
//    // Input for Adjacency List
//    for (int i = 0; i < m; i++) {
//        cin >> u >> v;
//        adjList[u].push_back(v);
//        adjList[v].push_back(u); // For undirected graph
//    }
//
//    // Print Adjacency List
//    cout << "\nAdjacency List:\n";
//    for (int i = 0; i < n; i++) {
//        cout << i << ": ";
//        for (int neighbor : adjList[i]) {
//            cout << neighbor << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
