 
#include <iostream>
#include <queue>
using namespace std;

class Student {
public:
    int rollNo;
    double cgpa;

    Student(int rollNo = 0, double cgpa = 0.0) : rollNo(rollNo), cgpa(cgpa) {}
};

class StudentMaxHeap {
private:
    Student* st;
    int currSize;
    int maxSize;

    void heapifyUp(int index) {
        if (index == 0) return; // Base case 

        int parentIndex = (index - 1) / 2; //parent index 

        // if current > largest then swap current with parent along with rollNos and cgpa 
        if (st[index].cgpa > st[parentIndex].cgpa ||
            (st[index].cgpa == st[parentIndex].cgpa && st[index].rollNo < st[parentIndex].rollNo)) {
            swap(st[index], st[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int maxChild = index;

        // left > max then swap 
        if (leftChild < currSize &&
            (st[leftChild].cgpa > st[maxChild].cgpa ||
                (st[leftChild].cgpa == st[maxChild].cgpa && st[leftChild].rollNo < st[maxChild].rollNo))) {
            maxChild = leftChild;
        }

        // right > max then swap 
        if (rightChild < currSize &&
            (st[rightChild].cgpa > st[maxChild].cgpa ||
                (st[rightChild].cgpa == st[maxChild].cgpa && st[rightChild].rollNo < st[maxChild].rollNo))) {
            maxChild = rightChild;
        }


        if (maxChild != index) {
            swap(st[index], st[maxChild]);
            heapifyDown(maxChild);
        }
    }
    

public:
    StudentMaxHeap(int size) : currSize(0), maxSize(size) {
        st = new Student[maxSize];
    }

    ~StudentMaxHeap() { delete[] st; }

    bool isEmpty() { return currSize == 0; }

    bool isFull() { return currSize == maxSize; }

    bool insert(int rollNo, double cgpa) {
        if (isFull()) return false;

        st[currSize] = Student(rollNo, cgpa);
        heapifyUp(currSize);
        currSize++;
        return true;
    }

    bool removeBestStudent(int& rollNo, double& cgpa) {
        if (isEmpty()) {
            return false;
        }
        rollNo = st[0].rollNo;
        cgpa = st[0].cgpa;
        int last = currSize - 1;

        st[0] = st[last];
        currSize--;

        heapifyDown(0);
        return true;
    }
    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int minchild = i;

        // left < max then swap
        if (left < currSize && (st[left].cgpa < st[minchild].cgpa ||
            (st[left].cgpa == st[minchild].cgpa && st[left].rollNo < st[minchild].rollNo))) {
            minchild = left;
        }

        // right < max then swap
        if (right < currSize && (st[right].cgpa < st[minchild].cgpa ||
            (st[right].cgpa == st[minchild].cgpa && st[right].rollNo < st[minchild].rollNo))) {
            minchild = right;
        }


        if (minchild != i) {
            swap(st[i], st[minchild]);
            heapify(minchild);
        }
    }
    void print() {
        for (int i = 0; i < currSize; i++) {
            cout << "Student " << i << " - Roll No: " << st[i].rollNo
                << ", CGPA: " << st[i].cgpa << endl;
        }
    }
    void buildheap(Student* st, int n) {
        currSize = n;
                for (int i = (currSize / 2) - 1; i >= 0; i--) {
                    heapify(i);
                }
            }
    
};
void heapifyDown(vector<int>& heap, int index, int size) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(heap, largest, size);
    }
}
vector<int> kSmallestElements(const vector<int>& heap, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap(heap.begin(), heap.end());
    vector<int> result;

    for (int i = 0; i < k && !minHeap.empty(); i++) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}
vector<int> mergeMinHeaps(const vector<int>& heap1, const vector<int>& heap2) {
    vector<int> mergedHeap = heap1; // Start with the first heap
    mergedHeap.insert(mergedHeap.end(), heap2.begin(), heap2.end()); // Add second heap elements

    
    make_heap(mergedHeap.begin(), mergedHeap.end(), greater<int>());
    return mergedHeap;
}
vector<int> convertMinHeapToMaxHeap(const vector<int>& minHeap) {
    vector<int> maxHeap = minHeap;
    int n = maxHeap.size();

    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(maxHeap, i, n);
    }

    return maxHeap;
}
int main() {
    vector<int> minHeap = { 2, 3, 6, 5, 9, 8 };

    // Q2 A  K SMALLEST ELEMENTS 
    int k = 2;
    vector<int> smallest = kSmallestElements(minHeap, k);
    cout << "K Smallest Elements: ";
    for (int num : smallest) cout << num << " ";

    // Q2 B  MERGE MIN HEAPS 
    vector<int> heap1 = { 1, 3, 6 };
    vector<int> heap2 = { 2, 5, 7 };
    vector<int> merged = mergeMinHeaps(heap1, heap2);

    cout << "\nMerged Min-Heap: ";
    for (int num : merged) cout << num << " ";

    // Q2 C CONVERT MIN TO MAX 
    vector<int> maxHeap = convertMinHeapToMaxHeap(minHeap);

    cout << "\nConverted Max-Heap: ";
    for (int num : maxHeap) cout << num << " ";

    StudentMaxHeap heap(10);
    int choice;

    do {
        cout << "\nHeap Operations" << endl;
        cout << "1. Insert Student" << endl;
        cout << "2. Delete Best Student" << endl;
        cout << "3. Print All Students" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int numStudents;
            cout << "Enter the number of students you want to insert: ";
            cin >> numStudents;

            for (int i = 0; i < numStudents; i++) {
                int roll;
                double cgpa;
                cout << "Enter roll number and CGPA for student " << (i + 1) << ": ";
                cin >> roll >> cgpa;
                if (!heap.insert(roll, cgpa)) {
                    cout << "Heap is full! Cannot insert more students." << endl;
                    break;
                }
            }
            break;
        }
        case 2: {
            int rollNo;
            double cgpa;

            if (heap.removeBestStudent(rollNo, cgpa)) {
                cout << "Removed Student - Roll No: " << rollNo << ", CGPA: " << cgpa << endl;
            }
            else {
                cout << "Heap is empty! No student to remove." << endl;
            }
            break;
        }
        case 3:
            cout << "Current Students in Max Heap:" << endl;
            heap.print();
            break;

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }

    } while (choice != 4);
    return 0;
}