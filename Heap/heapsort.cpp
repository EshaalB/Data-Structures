//#include <iostream>
//#include <vector>
//#include <algorithm> // For swap
//using namespace std;
//
//// Function to heapify a subtree rooted at index i (Max-Heap)
//void heapifyMax(vector<int>& arr, int n, int i) {
//    int largest = i;
//    int left = 2 * i + 1;
//    int right = 2 * i + 2;
//
//    if (left < n && arr[left] > arr[largest]) {
//        largest = left;
//    }
//
//    if (right < n && arr[right] > arr[largest]) {
//        largest = right;
//    }
//
//    if (largest != i) {
//        swap(arr[i], arr[largest]);
//        heapifyMax(arr, n, largest);
//    }
//}
//
//// Function to heapify a subtree rooted at index i (Min-Heap)
//void heapifyMin(vector<int>& arr, int n, int i) {
//    int smallest = i;
//    int left = 2 * i + 1;
//    int right = 2 * i + 2;
//
//    if (left < n && arr[left] < arr[smallest]) {
//        smallest = left;
//    }
//
//    if (right < n && arr[right] < arr[smallest]) {
//        smallest = right;
//    }
//
//    if (smallest != i) {
//        swap(arr[i], arr[smallest]);
//        heapifyMin(arr, n, smallest);
//    }
//}
//
//// Function to perform heap sort (Min-Heap or Max-Heap based on `ascending` flag)
//void heapSort(vector<int>& arr, bool ascending = true) {
//    int n = arr.size();
//
//    // Build the heap (Max-Heap or Min-Heap)
//    if (ascending) {
//        // Build Min-Heap for Ascending order
//        for (int i = n / 2 - 1; i >= 0; i--) {
//            heapifyMin(arr, n, i);
//        }
//    }
//    else {
//        // Build Max-Heap for Descending order
//        for (int i = n / 2 - 1; i >= 0; i--) {
//            heapifyMax(arr, n, i);
//        }
//    }
//
//    // Extract elements from the heap one by one
//    for (int i = n - 1; i > 0; i--) {
//        swap(arr[0], arr[i]);
//
//        // Heapify the reduced heap
//        if (ascending) {
//            heapifyMin(arr, i, 0);
//        }
//        else {
//            heapifyMax(arr, i, 0);
//        }
//    }
//}
//
//int main() {
//    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
//
//    // Sorting in ascending order using Min-Heap
//    cout << "Original array: ";
//    for (int num : arr) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    heapSort(arr, true); // Ascending order
//    cout << "Sorted array (Ascending): ";
//    for (int num : arr) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    // Sorting in descending order using Max-Heap
//    vector<int> arr2 = { 12, 11, 13, 5, 6, 7 };
//    heapSort(arr2, false); // Descending order
//    cout << "Sorted array (Descending): ";
//    for (int num : arr2) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
