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
    Node* head;
    Node* prev;

    Node* copyBST(Node* other) {
        if (!other) return nullptr;

        Node* newNode = new Node(other->data);
        newNode->left = copyBST(other->left);
        newNode->right = copyBST(other->right);

        return newNode;
    }

public:
    BST() : parent(nullptr), head(nullptr), prev(nullptr) {}

    BST(const BST& obj) {
        parent = copyBST(obj.parent);
    }

    Node* getRoot() { return parent; }

    int countNodes(Node* node) {
        if (!node) return 0;
        return countNodes(node->left) + countNodes(node->right) + 1;
    }

    bool insertCall(T val) {
        return insert(parent, val);
    }

    bool insert(Node*& node, T key) {
        if (!node) {
            node = new Node(key);
            return true;
        }
        if (key == node->data)
            return false;

        if (key > node->data)
            return insert(node->right, key);
        else
            return insert(node->left, key);
    }

    void inOrderTraversal() {
        if (!parent) return;
        inOrderRec(parent);
        cout << endl;
    }

    void inOrderRec(Node* node) {
        if (!node) return;
        inOrderRec(node->left);
        cout << node->data << " ";
        inOrderRec(node->right);
    }

    Node* findMax(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, T key) {
        if (!node) return node;

        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        }
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* temp = findMax(node->left);
                node->data = temp->data;
                node->left = deleteNode(node->left, temp->data);
            }
        }
        return node;
    }

    void del(T key) {
        parent = deleteNode(parent, key);
    }

    void findKL(Node* node, T k, int& count, int& result) {
        if (!node || count > k) return;

        findKL(node->right, k, count, result);

        count++;
        if (count == k) {
            result = node->data;
            return;
        }
        findKL(node->left, k, count, result);
    }

    int findKthLargest(int k) {
        int count = 0;
        int result = -1;
        findKL(parent, k, count, result);
        return result;
    }

    bool searchR(Node* node, T val) {
        if (!node) return false;
        if (node->data > val) return searchR(node->left, val);
        else if (node->data < val) return searchR(node->right, val);
        else return true;
    }

    bool searchM(T val) {
        return searchR(parent, val);
    }

    void levelOrderTraversal() {
        if (!parent) return;

        queue<Node*> q;
        q.push(parent);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }

    int countPairs(Node* root1, Node* root2, int x) {
        if (!root1) return 0;
        int ans = 0;
        if (searchR(root2, x - root1->data)) ans++;

        ans += countPairs(root1->left, root2, x);
        ans += countPairs(root1->right, root2, x);

        return ans;
    }

    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    ~BST() {
        destroy(parent);
    }
    void bstToDll(Node*& head) {
        head = nullptr;
        Node* tail = nullptr;
        bstToDllRec(parent, head, tail);
    }

    void bstToDllRec(Node* node, Node*& head, Node*& tail) {
        if (!node) return;

        bstToDllRec(node->left, head, tail);

        if (!head) {
            head = node;   
        }
        else {
            tail->next = node;  
            node->prev = tail;  
        }
        tail = node;  

        bstToDllRec(node->right, head, tail);
    }
     
    void printDll(Node* head) {
        Node* current = head;
        cout << "Doubly Linked List: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void printTree() {
        cout << "Tree" << endl;
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

    int getHeight(Node* node) const { return node ? node->height : 0; }

    int balanceFactor(Node* node) const {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* singleRightRotation(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* singleLeftRotation(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
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

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

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

    bool search(Node* node, T key) const {
        if (!node) return false;
        if (node->key == key) return true;
        if (key < node->key) return search(node->left, key);
        return search(node->right, key);
    }

    bool search(T key) const {
        return search(root, key);
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
};
int main() {
    BST<int> bst;

    cout << "Inserting elements into BST:\n";
    bst.insertCall(5);
    bst.insertCall(10);
    bst.insertCall(12);
    bst.insertCall(13);
    bst.insertCall(14);
    bst.insertCall(11);
    bst.insertCall(80);
    BST<int> bst2;

    cout << "Inserting elements into BST:\n";
    bst2.insertCall(5);
    bst2.insertCall(10);
    bst2.insertCall(20);
    bst2.insertCall(90);
    bst2.insertCall(3);
    bst2.insertCall(9);
    bst2.insertCall(12);

    cout << "In-order traversal of BST: ";
    bst.inOrderTraversal();

    cout << "Level-order traversal of BST: ";
    bst.levelOrderTraversal();

    int searchKey = 60;
    cout << "Searching for " << searchKey << " in BST: "
        << (bst.searchM(searchKey) ? "Found" : "Not Found") << endl;

    int k = 3;
    cout << "The " << k << "-th largest element in BST is: "
        << bst.findKthLargest(k) << endl;

    int target = 100;
    int pCount = bst.countPairs(bst.getRoot(), bst2.getRoot(), target);
    cout << "Pair count of two trees:" << pCount << endl;
    cout << "Deleting 20 from BST.\n";
    bst.del(20);

    cout << "In-order traversal after deletion: ";
    bst.inOrderTraversal();

    cout << "Deleting 30 from BST.\n";
    bst.del(30);

    cout << "In-order traversal after deletion: ";
    bst.inOrderTraversal();

    cout << "Deleting 50 from BST.\n";
    bst.del(50);

    cout << "In-order traversal after deletion: ";
    bst.inOrderTraversal();

    cout << endl;
    bst.printTree();
     
    cout << "\n\nAVL Tree Test\n";
    AVL<int> avl;
    avl.insert(50);
    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(70);
    avl.insert(60);
    avl.insert(80);

    cout << "Inorder traversal of AVL: ";
    avl.displayInorder();

    cout << "Preorder traversal of AVL: ";
    avl.displayPreorder();

    cout << "Postorder traversal of AVL: ";
    avl.displayPostorder();

    cout << "Checking if AVL tree is balanced: "
        << (avl.isAVL() ? "Yes" : "No") << endl;

    cout << "Deleting 20 from AVL.\n";
    avl.del(20);
    cout << "Inorder traversal after deletion: ";
    avl.displayInorder();
    cout << "Checking if AVL tree is balanced: "
        << (avl.isAVL() ? "Yes" : "No") << endl;
    cout << "Minimum element in AVL: ";
    avl.findMin();

    cout << "All paths from root to leaves in AVL tree:\n";
    avl.printAllPaths();

    return 0;
}
