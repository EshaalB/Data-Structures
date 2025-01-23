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

    void print() {
        for (int i = 0; i < currSize; i++) {
            cout << "Student " << i << " - Roll No: " << st[i].rollNo
                << ", CGPA: " << st[i].cgpa << endl;
        }
    }
};
template <typename T>
class AVL {
private:
    struct Node {
        T key;
        int height;
        Node* left;
        Node* right;

        Node(T data) : key(data), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    int getHeight(Node* node) const {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) const {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* singleRightRotation(Node* node) {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node* singleLeftRotation(Node* node) {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node* leftRightRotation(Node* node) {
        node->left = singleLeftRotation(node->left);
        return singleRightRotation(node);
    }

    Node* rightLeftRotation(Node* node) {
        node->right = singleRightRotation(node->right);
        return singleLeftRotation(node);
    }

    Node* insert(Node* node, T key) {
        if (!node) return new Node(key);

        if (key < node->key) {
            node->left = insert(node->left, key);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        else {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int bf = balanceFactor(node);

        if (bf > 1 && key < node->left->key) return singleRightRotation(node);
        if (bf < -1 && key > node->right->key) return singleLeftRotation(node);
        if (bf > 1 && key > node->left->key) return leftRightRotation(node);
        if (bf < -1 && key < node->right->key) return rightLeftRotation(node);

        return node;
    }

    Node* findMin(Node* node) const {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, T key) {
        if (!node) return nullptr;

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        }
        else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }

        if (!node) return nullptr;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int bf = balanceFactor(node);

        if (bf > 1 && balanceFactor(node->left) >= 0) return singleRightRotation(node);
        if (bf > 1 && balanceFactor(node->left) < 0) return leftRightRotation(node);
        if (bf < -1 && balanceFactor(node->right) <= 0) return singleLeftRotation(node);
        if (bf < -1 && balanceFactor(node->right) > 0) return rightLeftRotation(node);

        return node;
    }

    void displayInorder(Node* node) const {
        if (!node) return;
        displayInorder(node->left);
        cout << node->key << " ";
        displayInorder(node->right);
    }

    void displayPreorder(Node* node) const {
        if (!node) return;
        cout << node->key << " ";
        displayPreorder(node->left);
        displayPreorder(node->right);
    }

    void displayPostorder(Node* node) const {
        if (!node) return;
        displayPostorder(node->left);
        displayPostorder(node->right);
        cout << node->key << " ";
    }

public:
    AVL() : root(nullptr) {}

    void insert(T key) {
        root = insert(root, key);
    }

    void del(T key) {
        root = deleteNode(root, key);
    }

    void displayInorder() const {
        displayInorder(root);
        cout << endl;
    }

    void displayPreorder() const {
        displayPreorder(root);
        cout << endl;
    }

    void displayPostorder() const {
        displayPostorder(root);
        cout << endl;
    }

    bool search(T key) const {
        Node* curr = root;
        while (curr) {
            if (key == curr->key) return true;
            curr = key < curr->key ? curr->left : curr->right;
        }
        return false;
    }

    bool isAVL(Node* node) const {
        if (!node) return true;
        int bf = balanceFactor(node);
        if (bf > 1 || bf < -1) return false;
        return isAVL(node->left) && isAVL(node->right);
    }

    bool isAVL() const {
        return isAVL(root);
    }

    void findMin() const {
        Node* minNode = findMin(root);
        if (minNode)
            cout << "Minimum element is: " << minNode->key << endl;
        else
            cout << "Tree is empty." << endl;
    }

    void printAllPaths() {
        int path[100];
        printAllPathsRecursive(root, path, 0);
    }

    void printAllPathsRecursive(Node* curr, int path[], int pathLength) const {
        if (!curr) return;

        path[pathLength] = curr->key;
        pathLength++;

        if (!curr->left && !curr->right) {
            for (int i = 0; i < pathLength; i++)
                cout << path[i] << " ";
            cout << endl;
        }
        else {
            printAllPathsRecursive(curr->left, path, pathLength);
            printAllPathsRecursive(curr->right, path, pathLength);
        }
    }
    void levelOrderTraversal() {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->key << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
        cout << endl;
    }
};
int main() {
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

    //cout << "\n\nAVL Tree Test\n";
    //AVL<int> avl;
    //avl.insert(50);
    //avl.insert(30);
    //avl.insert(20);
    //avl.insert(40);
    //avl.insert(70);
    //avl.insert(60);
    //avl.insert(80);

    //cout << "Inorder traversal of AVL: ";
    //avl.displayInorder();

    //cout << "Preorder traversal of AVL: ";
    //avl.displayPreorder();

    //cout << "Postorder traversal of AVL: ";
    //avl.displayPostorder();
    //cout << "Level Order " << endl;
    //avl.levelOrderTraversal();
    //cout << "Checking if AVL tree is balanced: "
    //    << (avl.isAVL() ? "Yes" : "No") << endl;

    //cout << "Deleting 20 from AVL.\n";
    //avl.del(20);
    //cout << "Inorder traversal after deletion: ";
    //avl.levelOrderTraversal();
    //cout << "Checking if AVL tree is balanced: "
    //    << (avl.isAVL() ? "Yes" : "No") << endl;
    //cout << "Minimum element in AVL: ";
    //avl.findMin();

    //cout << "All paths from root to leaves in AVL tree:\n";
    //avl.printAllPaths(); 
    return 0;
}
