//#include <iostream>
//#include <vector>
//#include <queue>
//#include <unordered_map>
//#include <fstream>
//#include <string>
//using namespace std;
//
//// TEMPLATE CLASS FOR GRAPH
//template <typename T>
//class Graph {
//    struct Edge {
//        T destination; //ending point
//        int weight; // some value of an edge that cannot be -ve
//    };
//
//    struct Node {
//        T id;
//        string type;
//        vector<Edge> adjList; // list of edges of this node
//    };
//
//public:
//    vector<Node> vertices; // list that holds all the vertices in the graph
//    unordered_map<T, int> nodeIndex; // maps node elements to an index using hashing
//
//    // FUNCTION TO ADD A NEW VERTEX
//    void addVertex(T vertexID, const string& vType) {
//        if (nodeIndex.count(vertexID)) { // checking if the id already exists
//            cout << "Vertex of id " << vertexID << " already exists!" << endl;
//            return;
//        }
//        Node newNode = { vertexID, vType }; //adding using a newNode
//        //updating list and index
//        vertices.push_back(newNode);
//        nodeIndex[vertexID] = vertices.size() - 1;
//    }
//
//    // FUNCTION TO ADD AN EDGE
//    void addEdge(T src, T destination, int weight, bool direction) {
//        if (!nodeIndex.count(src) || !nodeIndex.count(destination)) { //checking if the src and dest already exists
//            cout << "One or both vertices not found!" << endl;
//            return;
//        }
//        if (weight < 0) { // check for -ve weight
//            cout << "Weight is negative " << endl;
//            return;
//        }
//        vertices[nodeIndex[src]].adjList.push_back({ destination, weight });
//        if (!direction) // checking if direction is 0 meaning undirected then push back src as well 
//            vertices[nodeIndex[destination]].adjList.push_back({ src, weight });
//    }
//
//    // FUNCTION TO PRINT GRAPH
//    void printGraph() {
//        for (const auto& vtx : vertices) {
//            cout << "Vertex " << vtx.id << " [" << vtx.type << "] -> ";
//            for (const auto& neighbour : vtx.adjList) {
//                cout << neighbour.destination << " (weight: " << neighbour.weight << "), ";
//            }
//            cout << endl;
//        }
//    }
//};
//
//// MINIMUM HEAP IMPLEMENTATION FOR PRIM'S ALGO
//template <typename T>
//class MinHeap {
//public:
//    unordered_map<T, int> weights; // keeping track of weight
//    unordered_map<T, int> heapPos;//keeping track of heap position to update quickly 
//    vector<T> heapArr; //list of vertices in a heap where min heap is followed 
//
//    MinHeap(const vector<T>& vtx, const vector<int>& weightsArr) {
//        for (int i = 0; i < vtx.size(); i++) {
//            // stores weight in weights map ,heap array and heap position for each vertex 
//            weights[vtx[i]] = weightsArr[i];  
//            heapArr.push_back(vtx[i]);
//            heapPos[vtx[i]] = i;
//        }
//        buildHeap();
//    }
//
//    void buildHeap() { // ensure min heap property is not violated 
//        for (int i = (heapArr.size() - 1) / 2; i >= 0; i--)  heapifyDown(i);
//    }
//
//    bool isEmpty() { return heapArr.empty(); } // check if heap is empty 
//
//    T extractMin() { // func to find the smallest weight in heap by swapping root with last and calling heap down 
//        if (heapArr.empty()) {
//            cout << "Heap empty!" << endl;
//            return T();
//        }
//        T minVtx = heapArr[0];
//        swap(heapArr[0], heapArr.back());
//        heapPos[heapArr[0]] = 0;
//        heapPos.erase(minVtx);
//        weights.erase(minVtx);
//        heapArr.pop_back();
//        heapifyDown(0);
//        return minVtx;
//    }
//    // fucn for updating weight
//    void decreaseKey(T vtx, int newWeight) {
//        if (!heapPos.count(vtx)) { //check if vtx exists 
//            cerr << "Error: Vertex " << vtx << " not found in MinHeap!" << endl;
//            return;
//        }
//        int currIdx = heapPos[vtx];
//        if (newWeight >= weights[vtx]) return; // checkk if new is greater than curr 
//        weights[vtx] = newWeight; //swap 
//        heapifyUp(currIdx); //update 
//    }
//
//private:
//    //FUNC FOR HEAPIFY UP 
//    void heapifyUp(int idx) {
//        if (idx == 0) return;
//
//        int parentIdx = (idx - 1) / 2;
//        if (weights[heapArr[idx]] < weights[heapArr[parentIdx]]) {
//            swap(heapArr[idx], heapArr[parentIdx]);
//            heapPos[heapArr[idx]] = idx;
//            heapPos[heapArr[parentIdx]] = parentIdx;
//            heapifyUp(parentIdx);
//        }
//    }
//    //FUNC FOR HEAPIFY DOWN
//    void heapifyDown(int idx) {
//        int left = 2 * idx + 1;
//        int right = 2 * idx + 2;
//        int smallest = idx;
//
//        if (left < heapArr.size() && weights[heapArr[left]] < weights[heapArr[smallest]])
//            smallest = left;
//
//        if (right < heapArr.size() && weights[heapArr[right]] < weights[heapArr[smallest]])
//            smallest = right;
//
//        if (smallest != idx) {
//            swap(heapArr[idx], heapArr[smallest]);
//            heapPos[heapArr[idx]] = idx;
//            heapPos[heapArr[smallest]] = smallest;
//            heapifyDown(smallest);
//        }
//    }
//};
//
//// FUNCTION TO FIND MINIMUM SPANNING TREE USING PRIM'S ALGORITHM
//template <typename T>
//void findMST(Graph<T>& graph) {
//    if (graph.vertices.empty()) { //check if graph empty 
//        cout << "Graph is empty. No MST possible." << endl;
//        return;
//    }
//
//    int numV = graph.vertices.size(); //vertices in graph 
//    vector<int> key(numV, INT_MAX); //vector to store minimum weight 
//    vector<int> parent(numV, -1); // vector to store predecessor 
//    vector<bool> visited(numV, false); // check if vertex has been visited 
//
//    // intialized key with 0 and vertex with id 
//    key[0] = 0;
//    vector<T> vtx(numV);
//    for (int i = 0; i < numV; i++) {
//        vtx[i] = graph.vertices[i].id;
//    }
//
//    MinHeap<T> minHeap(vtx, key); // make obj of min heap to establish priority queue 
//
//    while (!minHeap.isEmpty()) { //extract min weight of first vertex,intialize it to an index and then mark it visited 
//        T starting = minHeap.extractMin();
//        int startingIdx = graph.nodeIndex[starting];
//        visited[startingIdx] = true;
//        //do the same for neighbouring 
//        for (const auto& neighbour : graph.vertices[startingIdx].adjList) {
//            T curr = neighbour.destination;
//            int currIdx = graph.nodeIndex[curr];
//            if (!visited[currIdx] && neighbour.weight < key[currIdx]) {
//                key[currIdx] = neighbour.weight;
//                parent[currIdx] = startingIdx;
//                minHeap.decreaseKey(currIdx, neighbour.weight);// to get new smaller weight 
//            }
//        }
//
//
//        cout << "Edges in the Minimum Spanning Tree:" << endl; //print edges 
//        for (int i = 1; i < numV; i++) {
//            if (parent[i] != -1) {
//                cout << graph.vertices[parent[i]].id << " -> " << graph.vertices[i].id << endl;
//            }
//        }
//    }
//}
//
//// MAIN FUNCTION FOR MENU-BASED INTERACTION
//int main() {
//    Graph<int> graph;
//    while (true) {
//        cout << "Assignment 4 Q1 " << endl;
//        cout << "1. Input graph from file" << endl;
//        cout << "2. Save graph to file" << endl;
//        cout << "3. Add vertex" << endl;
//        cout << "4. Add edge" << endl;
//        cout << "5. Find MST" << endl;
//        cout << "6. Print graph" << endl;
//        cout << "7. Exit" << endl;
//        cout << "Enter your option: ";
//        int opt;
//        cin >> opt;
//
//        if (opt == 1) { //read input from file 
//            string filename;
//            cout << "Enter filename: ";
//            cin >> filename;
//            ifstream infile(filename);
//            if (!infile) {
//                cout << "File not found!" << endl;
//                continue;
//            }
//            int numVtx, numEdges;
//            infile >> numVtx;
//            for (int i = 0; i < numVtx; i++) {
//                int id;
//                string type;
//                infile >> id >> type;
//                graph.addVertex(id, type);
//            }
//            infile >> numEdges;
//            for (int i = 0; i < numEdges; i++) {
//                int src, destination, weight;
//                bool direction;
//                infile >> src >> destination >> weight >> direction; 
//                graph.addEdge(src, destination, weight, direction);
//            }
//            infile.close();
//        }
//        else if (opt == 2) { // write to file 
//            string filename;
//            cout << "Enter filename to save: ";
//            cin >> filename;
//            ofstream outfile(filename);
//            outfile << graph.vertices.size() << endl;
//            for (const auto& vtx : graph.vertices) {
//                outfile << vtx.id << " " << vtx.type << endl;
//            }
//            int edgeCount = 0;
//            for (const auto& vtx : graph.vertices) {
//                edgeCount += vtx.adjList.size();
//            }
//            outfile << edgeCount / 2 << endl;
//            for (const auto& vtx : graph.vertices) {
//                for (const auto& edge : vtx.adjList) {
//                    if (vtx.id < edge.destination) {
//                        outfile << vtx.id << " " << edge.destination << " " << edge.weight << endl;
//                    }
//                }
//            }
//            outfile.close();
//        }
//        else if (opt == 3) { // add vertex 
//            int id;
//            string type;
//            cout << "Enter vertex ID and type: ";
//            cin >> id >> type;
//            graph.addVertex(id, type);
//        }
//        else if (opt == 4) { //add edge 
//            int src, destination, weight;
//            bool direction;
//            cout << "Enter source, destination, weight, and direction (0 for undirected, 1 for directed): ";
//            cin >> src >> destination >> weight >> direction;
//            graph.addEdge(src, destination, weight, direction);
//        }
//        else if (opt == 5) { // find MST 
//            findMST(graph);
//        }
//        else if (opt == 6) { // print graph
//            graph.printGraph();
//        }
//        else if (opt == 7) {
//            break;
//        }
//    }
//    return 0;
//}
