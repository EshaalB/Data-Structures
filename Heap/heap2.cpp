//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// Function to heapify (bubble down) the heap to maintain heap property
//void heapifyDown(vector<int>& heap, int n, int i) {
//    int largest = i;
//    int left = 2 * i + 1;
//    int right = 2 * i + 2;
//
//    // If left child is larger than root
//    if (left < n && heap[left] > heap[largest])
//        largest = left;
//
//    // If right child is larger than root
//    if (right < n && heap[right] > heap[largest])
//        largest = right;
//
//    // If largest is not root
//    if (largest != i) {
//        swap(heap[i], heap[largest]);
//        heapifyDown(heap, n, largest);
//    }
//}
//
//// Function to heapify (bubble up) the heap to maintain heap property
//void heapifyUp(vector<int>& heap, int i) {
//    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
//        swap(heap[i], heap[(i - 1) / 2]);
//        i = (i - 1) / 2;
//    }
//}
//
//// Function to insert a new element into the heap
//void insert(vector<int>& heap, int& n, int value) {
//    // Increase the size of heap
//    heap.push_back(value);
//    n++;
//
//    // Bubble up the new element to restore heap property
//    heapifyUp(heap, n - 1);
//}
//
//// Function to delete the root (max element) from the heap
//int deleteRoot(vector<int>& heap, int& n) {
//    if (n <= 0) return -1;  // Heap is empty
//
//    int root = heap[0];
//
//    // Replace the root with the last element
//    heap[0] = heap[n - 1];
//    n--;
//
//    // Heapify down to restore heap property
//    heapifyDown(heap, n, 0);
//
//    return root;
//}
//
//int main() {
//    vector<int> heap = { 100, 90, 80, 60, 70, 50, 40, 30, 20, 10 };
//    int n = heap.size();
//
//    // Insert a new element into the heap
//    int newElement = 95;
//    cout << "Inserting " << newElement << " into the heap." << endl;
//    insert(heap, n, newElement);
//    cout << "Heap after insertion: ";
//    for (int el : heap) cout << el << " ";
//    cout << endl;
//
//    // Delete the root (max element) from the heap
//    cout << "Deleting root (max element) from the heap: ";
//    int deletedElement = deleteRoot(heap, n);
//    cout << deletedElement << endl;
//
//    // Heap after deletion
//    cout << "Heap after deletion: ";
//    for (int el : heap) cout << el << " ";
//    cout << endl;
//
//    return 0;
//}
