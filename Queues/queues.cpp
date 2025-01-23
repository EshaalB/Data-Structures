//#include <iostream>
//using namespace std;
//
//template <typename T>
//class Queue {
//private:
//    struct Node {
//        T data;
//        Node* next;
//        Node(T val) : data(val), next(nullptr) {}
//    };
//
//    Node* frontE;
//    Node* rearE;
//    int llSize;
//
//public:
//    Queue() : frontE(nullptr), rearE(nullptr), llSize(0) {}
//
//    void enqueue(T data) {
//        Node* newNode = new Node(data);
//        if (rearE == nullptr) {
//            frontE = rearE = newNode;
//        }
//        else {
//            rearE->next = newNode;
//            rearE = newNode;
//        }
//        llSize++;
//    }
//
//    void dequeue() {
//        if (isEmpty()) {
//            cout << "Queue is empty!" << endl;
//            return;
//        }
//        Node* temp = frontE;
//        frontE = frontE->next;
//        delete temp;
//        llSize--;
//        if (frontE == nullptr) rearE = nullptr;
//    }
//
//    bool isFull() {
//        return false;
//    }
//
//    int size() {
//        return llSize;
//    }
//
//    bool isEmpty() {
//        return llSize == 0;
//    }
//
//    T front() {
//        if (isEmpty()) {
//            cout << "Queue is empty" << endl;
//            throw runtime_error("Queue is empty");
//        }
//        return frontE->data;
//    }
//
//    T rear() {
//        if (isEmpty()) {
//            cout << "Queue is empty" << endl;
//            throw runtime_error("Queue is empty");
//        }
//        return rearE->data;
//    }
//
//    void reverse() {
//        Node* curr = frontE;
//        Node* prev = nullptr;
//
//        while (curr) {
//            Node* nextNode = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = nextNode;
//        }
//        frontE = prev;
//    }
//
//    T getMin() {
//        return frontE->data;
//    }
//
//    T getMax() {
//        return rearE->data;
//    }
//
//    void display() {
//        Node* curr = frontE;
//        while (curr) {
//            cout << curr->data << " ";
//            curr = curr->next;
//        }
//        cout << endl;
//    }
//
//    void sorting() {
//        if (isEmpty() || frontE->next == nullptr) return;
//
//        bool swapped;
//        do {
//            swapped = false;
//            Node* curr = frontE;
//            while (curr && curr->next) {
//                if (curr->data > curr->next->data) {
//                    swap(curr->data, curr->next->data);
//                    swapped = true;
//                }
//                curr = curr->next;
//            }
//        } while (swapped);
//    }
//};
//
//template <typename T>
//class CircularQueue {
//private:
//    struct Node { // Define Node here
//        T data;
//        Node* next;
//        Node(T val) : data(val), next(nullptr) {}
//    };
//
//    Node* frontElement;
//    Node* rearElement;
//    int linkedSize;
//
//public:
//    CircularQueue() : frontElement(nullptr), rearElement(nullptr), linkedSize(0) {}
//
//    ~CircularQueue() {
//        while (!isEmpty()) {
//            dequeue();
//        }
//    }
//
//    void enqueue(T data) {
//        Node* newNode = new Node(data);
//        if (isEmpty()) {
//            frontElement = rearElement = newNode;
//            rearElement->next = frontElement; // Circular link
//        }
//        else {
//            rearElement->next = newNode;
//            rearElement = newNode;
//            rearElement->next = frontElement; // Maintain circular link
//        }
//        linkedSize++;
//    }
//
//    void dequeue() {
//        if (isEmpty()) {
//            cout << "Queue is empty!" << endl;
//            return;
//        }
//        Node* temp = frontElement;
//        if (frontElement == rearElement) { // Only one element
//            frontElement = rearElement = nullptr;
//        }
//        else {
//            frontElement = frontElement->next;
//            rearElement->next = frontElement; // Update rear to point to new front
//        }
//        delete temp;
//        linkedSize--;
//    }
//
//    bool isEmpty() {
//        return linkedSize == 0;
//    }
//
//    void display() {
//        if (isEmpty()) return;
//
//        Node* curr = frontElement;
//        do {
//            cout << curr->data << " ";
//            curr = curr->next;
//        } while (curr != frontElement);
//        cout << endl;
//    }
//
//    bool isPalindrome() {
//        if (isEmpty()) return true;
//
//        Node* slow = frontElement;
//        Node* fast = frontElement;
//
//        // Finding the middle using the fast-slow pointer approach
//        while (fast && fast->next && fast->next != frontElement) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        // If the number of elements is odd, skip the middle element
//        Node* secondHalf = (fast != nullptr && fast->next == frontElement) ? slow->next : slow;
//
//        // Reverse the second half
//        Node* prev = nullptr;
//        Node* curr = secondHalf;
//        Node* startSecondHalf = secondHalf; // Save the starting point to restore later
//
//        do {
//            Node* nextNode = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = nextNode;
//        } while (curr != startSecondHalf);
//
//        // Now prev points to the head of the reversed second half
//        Node* firstHalf = frontElement;
//        Node* secondHalfHead = prev;
//
//        // Check for palindrome
//        bool palindrome = true;
//        do {
//            if (firstHalf->data != secondHalfHead->data) {
//                palindrome = false;
//                break;
//            }
//            firstHalf = firstHalf->next;
//            secondHalfHead = secondHalfHead->next;
//        } while (firstHalf != slow && secondHalfHead != startSecondHalf);
//
//        // Restore the original order
//        curr = prev;
//        prev = nullptr;
//        do {
//            Node* nextNode = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = nextNode;
//        } while (curr != startSecondHalf);
//
//        // Link back to the front element
//        if (rearElement != nullptr) {
//            rearElement->next = frontElement; // Maintain circular link
//        }
//
//        return palindrome;
//    }
//
//};
//
//int main() {
//    Queue<int> q;
//    q.enqueue(10);
//    q.enqueue(20);
//    q.enqueue(30);
//    q.enqueue(50);
//    q.display();
//    cout << "Front: " << q.front() << "\n";
//    cout << "Rear: " << q.rear() << "\n";
//
//    q.dequeue();
//    cout << "Front after dequeue: " << q.front() << "\n";
//
//    cout << "Queue contents: ";
//    q.display();
//
//    q.reverse();
//    cout << "Queue after reverse: ";
//    q.display();
//
//    q.sorting();
//    cout << "Queue after sorting: ";
//    q.display();
//
//    cout << "Max: " << q.getMax() << endl;
//    cout << "Min: " << q.getMin() << endl;
//
//    CircularQueue<int> cq;
//
//    cq.enqueue(1);
//    cq.enqueue(2);
//    cq.enqueue(3);
//    cq.enqueue(2);
//    cq.enqueue(1);
//
//    cout << "Circular Queue contents: ";
//    cq.display();
//
//    cout << "Is palindrome: " << (cq.isPalindrome() ? "Yes" : "No") << endl;
//
//
//    return 0;
//}