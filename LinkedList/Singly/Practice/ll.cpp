//#include <iostream>
//#include <queue>
//using namespace std;
//
//class Node {
//    friend class LinkedList;
//private:
//    int data;
//    Node* next;
//    Node(int d) {
//        this->data = d;
//        this->next = nullptr;
//    }
//};
//
//class LinkedList {
//private:
//    Node* head;
//public:
//    LinkedList() {
//        head = nullptr;
//    }
//
//    void insertAtEnd(int d) {
//        Node* newNode = new Node(d);
//        if (head == nullptr) {
//            head = newNode;
//            return;
//        }
//        Node* curr = head;
//        while (curr->next != nullptr) {
//            curr = curr->next;
//        }
//        curr->next = newNode;
//    }
//
//    void display() {
//        Node* curr = head;
//        while (curr != nullptr) {
//            cout << curr->data << " -> ";
//            curr = curr->next;
//        }
//        cout << "NULL" << endl;
//    }
//
//    void funcGuess() {
//        if (!head) return;
//
//        queue<int> nodeQueue;
//        Node* curr = head;
//
//        // Push all node data into the queue
//        while (curr != nullptr) {
//            nodeQueue.push(curr->data);
//            curr = curr->next;
//        }
//
//        Node* newHead = nullptr;
//        Node* tail = nullptr;
//
//        // Reconstruct the linked list using the queue
//        while (!nodeQueue.empty()) {
//            if (!nodeQueue.empty()) {
//                int frontValue = nodeQueue.front();
//                nodeQueue.pop();
//                Node* frontNode = new Node(frontValue);
//
//                if (newHead == nullptr) {
//                    newHead = frontNode;
//                    tail = frontNode;
//                }
//                else {
//                    tail->next = frontNode;
//                    tail = frontNode;
//                }
//            }
//
//            if (!nodeQueue.empty()) {
//                queue<int> tempQueue;
//                while (nodeQueue.size() > 1) {
//                    tempQueue.push(nodeQueue.front());
//                    nodeQueue.pop();
//                }
//
//                int backValue = nodeQueue.front();
//                nodeQueue.pop();
//
//                Node* backNode = new Node(backValue);
//                tail->next = backNode;
//                tail = backNode;
//
//                while (!tempQueue.empty()) {
//                    nodeQueue.push(tempQueue.front());
//                    tempQueue.pop();
//                }
//            }
//        }
//
//        if (tail) {
//            tail->next = nullptr;
//        }
//
//        head = newHead;
//    }
//};
//
//int main() {
//    LinkedList l1;
//
//    l1.insertAtEnd(1);
//    l1.insertAtEnd(2);
//    l1.insertAtEnd(3);
//    l1.insertAtEnd(4);
//    l1.insertAtEnd(5);
//    l1.insertAtEnd(6);
//    l1.insertAtEnd(7);
//    l1.insertAtEnd(8);
//
//    cout << "Original list: " << endl;
//    l1.display();
//
//    l1.funcGuess();
//
//    cout << "Updated list: " << endl;
//    l1.display();
//
//    return 0;
//}
