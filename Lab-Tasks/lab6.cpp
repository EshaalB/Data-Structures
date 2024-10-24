#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BST {
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T element) : data(element), left(nullptr), right(nullptr) {}
    };
    Node* parent;

public:
    BST() : parent(nullptr) {}

    // Problem 4: insert and delete 
    void insert(T key) {
        insertRec(parent, key);
    }

    void insertRec(Node*& parent, T key) {
        if (parent == nullptr) {
            parent = new Node(key);
            return;
        }
        if (key >= parent->data)
            insertRec(parent->right, key);
        else
            insertRec(parent->left, key);
    }

    void inOrderTraversal() {
        if (parent == nullptr) return;
        inOrderRec(parent);
        cout << endl;
    }

    void inOrderRec(Node* parent) {
        if (parent == nullptr) return;
        inOrderRec(parent->left);
        cout << parent->data << " ";
        inOrderRec(parent->right);
    }

    Node* findMax(Node* parent) {
        while (parent->right != nullptr) {
            parent = parent->right;
        }
        return parent;
    }

    Node* deleteNode(Node* parent, T key) {
        if (parent == nullptr) return parent;

        if (key < parent->data) {
            parent->left = deleteNode(parent->left, key);
        }
        else if (key > parent->data) {
            parent->right = deleteNode(parent->right, key);
        }
        else {
            if (parent->left == nullptr && parent->right == nullptr) {
                delete parent;
                return nullptr;
            }
            else if (parent->left == nullptr) {
                Node* temp = parent->right;
                delete parent;
                return temp;
            }
            else if (parent->right == nullptr) {
                Node* temp = parent->left;
                delete parent;
                return temp;
            }
            else {
                Node* temp = findMax(parent->left);
                parent->data = temp->data;
                parent->left = deleteNode(parent->left, temp->data);
            }
        }
        return parent;
    }

    void del(T key) {
        parent = deleteNode(parent, key);
    }

    // Problem 5: Range Search
    void rangeSearch(T low, T high) {
        rangeSearchRec(parent, low, high);
    }

    void rangeSearchRec(Node* parent, T low, T high) {
        if (parent == nullptr) return;

         

        if (low < parent->data)
            rangeSearchRec(parent->left, low, high);

        if (low <= parent->data && high >= parent->data)
            cout << parent->data << " ";
           
  
        if (high > parent->data)
            rangeSearchRec(parent->right, low, high);

         
    }

    // Problem 6: Second Largest Element in BST
    T findSecondLargest() {
        if (parent == nullptr || (parent->left == nullptr && parent->right == nullptr))
            cout<<"Empty"<<endl;

        return findSecondLargestRec(parent);
    }

    T findSecondLargestRec(Node* parent) {
        if (parent->right != nullptr && parent->right->right == nullptr && parent->right->left == nullptr)
            return parent->data;

        if (parent->right == nullptr && parent->left != nullptr)
            return findMax(parent->left)->data;

        return findSecondLargestRec(parent->right);
    }

    // Problem 7: Level Order Traversal
    void levelOrderTraversal() {
        if (parent == nullptr) return;

        queue<Node*> q;
        q.push(parent);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
        cout << endl;
    }
};

int main() {
    BST<int> bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(21);
    bt.insert(1);
    bt.insert(7);
    bt.insert(22);
    bt.insert(6);

    cout << "Inorder Traversal: ";
    bt.inOrderTraversal();

    cout << "Range Search (3 to 21): ";
    bt.rangeSearch(3, 21);
    cout << endl;

    cout << "Second Largest Element: " << bt.findSecondLargest() << endl;

    cout << "Level Order Traversal: ";
    bt.levelOrderTraversal();

    bt.del(5);
    cout << "After Deleting 5, Inorder Traversal: ";
    bt.inOrderTraversal();

    return 0;
}
