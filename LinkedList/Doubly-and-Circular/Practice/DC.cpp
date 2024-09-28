#include <iostream>
using namespace std;
// Node  Doubly 
struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode(int val) : data(val), next(NULL), prev(NULL) {}
};



// Q1   Doubly  
class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    // a
    void insertAtStart(int data) {
        DoublyNode* newNode = new DoublyNode(data);
        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // b
    void deleteAtStart() {
        if (head == NULL) return;
        DoublyNode* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
    }

    // c
    void insertAtLast(int data) {
        DoublyNode* newNode = new DoublyNode(data);
        if (tail == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // d
    void deleteAtLast() {
        if (tail == NULL) return;
        DoublyNode* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        delete temp;
    }

    // e
    void insertBefore(int key, int data) {
        DoublyNode* current = head;
        DoublyNode* newNode = new DoublyNode(data);
        int count = 0;

        if (head == NULL) {
            head = newNode;
        }
        else {
            while (current && current->data != key) {
                count++;
                current = current->next;
            }

            if (count == 0) {

                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            else if (current) {

                newNode->next = current;
                newNode->prev = current->prev;
                if (current->prev) current->prev->next = newNode;
                else head = newNode;
                current->prev = newNode;
            }
        }
    }

    // f
    void deleteKey(int key) {
        DoublyNode* current = head;
        if (head && head->data == key) {
            if (head->next) {
                head->next->prev = head->prev;
                head = head->next;
            }
            else {
                head = NULL;
                tail = NULL;
            }
            delete current;
            return;
        }
        while (current && current->data != key) current = current->next;
        if (current != NULL) {
            if (current->prev) current->prev->next = current->next;
            else head = current->next;
            if (current->next) current->next->prev = current->prev;
            else tail = current->prev;
            delete current;
        }
    }
    // g
    void displayForward() {
        DoublyNode* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // h
    void displayBackward() {
        DoublyNode* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};
// Q2 circular
// Node Circular  
struct CircularNode {
    int data;
    CircularNode* next;

    CircularNode(int val) : data(val), next(NULL) {}
};
class CircularLinkedList {
private:
    CircularNode* head;

public:
    CircularLinkedList() : head(NULL) {}

    // a
    void insertAtStart(int data) {
        CircularNode* newNode = new CircularNode(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            CircularNode* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // b
    void insertAtEnd(int data) {
        CircularNode* newNode = new CircularNode(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            CircularNode* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // c
    void deleteKey(int key) {
        if (head == NULL) return;


        if (head->data == key) {

            if (head->next == head) {
                delete head;
                head = NULL;
            }
            else {

                CircularNode* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
            return;
        }

        CircularNode* current = head->next;
        CircularNode* prev = head;
        while (current != head) {
            if (current->data == key) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void deleteLast() {
        if (head == NULL) return;
        CircularNode* temp = head;
        CircularNode* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (prev != NULL) prev->next = head;
        delete temp;
    }

    // d
    void deleteAtIndex(int index) {
        if (head == NULL) return;
        CircularNode* current = head;
        CircularNode* prev = NULL;
        int count = 0;
        while (current != head || count == 0) {
            if (count == index) {
                if (prev != NULL) prev->next = current->next;
                else head = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
            count++;
        }
    }

    // e
    bool search(int key) {
        if (head == NULL) return false;
        CircularNode* temp = head;
        while (temp != head || temp->next != head) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    // f
    void display() {
        if (head == NULL) return;
        CircularNode* temp = head;
        while (temp->next != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
         cout << temp->data << " ";
        cout << endl;
    }
};


int main() {
    // Doubly Linked List
    DoublyLinkedList d1;
    cout << "Doubly" << endl;
    cout << "After insertion operations" << endl;
    d1.insertAtStart(1);
    d1.displayForward();
    d1.insertAtLast(2);
    d1.displayForward();
    d1.insertBefore(2, 3);
    d1.displayForward();
    cout << "After backward operations" << endl;
    d1.displayBackward();
    cout << "After deletion operations" << endl;
    d1.deleteAtStart();
    d1.displayForward();
    d1.deleteAtLast();
    d1.displayForward();

    // Circular Linked List
    CircularLinkedList c1;
    cout << "Circular" << endl;
    cout << "After insertion operations" << endl;
    c1.insertAtStart(10);
    c1.display();
    c1.insertAtEnd(30);
    c1.display();
    c1.insertAtStart(5);
    c1.display();
    cout << "After deletion operations" << endl;
    c1.deleteKey(10);
    c1.display();
    c1.deleteLast();
    c1.display();
    cout << "After search operations" << endl;
    if ((c1.search(5)))
        cout << "Found" << endl;
    else {
        cout << "Not found" << endl;
    }

    return 0;
}