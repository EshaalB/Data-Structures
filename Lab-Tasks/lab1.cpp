#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
    struct Node {
        T data;
        Node* next;
        Node(T const& element) : data(element), next(NULL) {}
    };

    Node* head;
    Node* tail;
    int listSize;

public:
    LinkedList() : head(NULL), tail(NULL), listSize(0) {}

    ~LinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    void insertatHead(T const element) {
        Node* newNode = new Node(element);
        newNode->next = head;
        head = newNode;
        if (tail == NULL) tail = newNode;
        listSize++;
    }

    void insertatTail(T const element) {
        Node* newNode = new Node(element);
        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    void update(T const element, int position) {
        if (position < 0 || position >= listSize) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* temp = head;
        for (int count = 0; count < position; count++) {
            temp = temp->next;
        }
        temp->data = element;
    }

    bool searchKey(T const element) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == element) return true;
            temp = temp->next;
        }
        return false;
    }

    bool deleteKey(T const element) {
        if (head == NULL) {
            cout << "List is empty, nothing to delete." << endl;
            return false;
        }

        if (head->data == element) {
            deleteatHead();
            return true;
        }

        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL && curr->data != element) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Element not found." << endl;
            return false;
        }

        prev->next = curr->next;
        if (curr == tail) tail = prev;
        delete curr;
        listSize--;
        return true;
    }

    int size() {
        return listSize;
    }

    void insertMiddle(T const element, int position) {
        if (position < 0 || position > listSize) {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (position == 0) {
            insertatHead(element);
            return;
        }

        Node* newNode = new Node(element);
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL) tail = newNode;
        listSize++;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next;   
            curr->next = prev;   
            prev = curr;         
            curr = nextNode;
        }

        head = prev;   
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteatHead() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete temp;
        listSize--;
    }

    void deleteatTail() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = tail = NULL;
        }
        else {
            Node* curr = head;
            while (curr->next != tail) {
                curr = curr->next;
            }
            delete tail;
            tail = curr;
            tail->next = NULL;
        }
        listSize--;
    }
    void deleteinRange(int firstIndex, int lastIndex) {
        if (firstIndex < 0 || lastIndex >= listSize || firstIndex > lastIndex) {
            cout << "Invalid range." << endl;
            return;
        }

        Node* current = head;
        Node* previous = NULL;
        int index = 0;


        while (index < firstIndex && current != NULL) {
            previous = current;
            current = current->next;
            index++;
        }


        Node* temp;
        for (int i = firstIndex; i <= lastIndex && current != NULL; i++) {
            temp = current;
            current = current->next;
            delete temp;
            listSize--;
        }


        if (previous != NULL) {
            previous->next = current;
        }
        else {
            head = current;

            if (current == NULL)
                tail = previous;

        }
    }

    };

    int main() {
        LinkedList<int> list;

        list.insertatHead(10);
        list.print();
        list.insertatTail(20);
        list.print();
        list.insertatHead(5);
        list.print();
        list.insertatTail(25);
        list.print();
        list.insertatTail(30);
        list.print();
        list.insertatTail(35);
        list.print();
        list.insertatTail(40);
        list.print();
        list.insertatTail(45);

        cout << "List size is: " << list.size() << endl;
        cout << "After insertion at head and tail" << endl;
        list.print();
        cout << "After insertion middle " << endl;
        list.insertMiddle(12, 4);
        cout << "After delete  " << endl;
        list.deleteatHead();
        list.print();
        list.deleteatTail();
        list.print();
        cout << "Range" << endl;
        list.deleteinRange(2, 4);
        list.print();

        list.searchKey(5);
        cout << "After update  " << endl;
        list.update(44, 3);
        list.print();

        cout << "List size is: " << list.size() << endl;
        cout << "After reverse  " << endl;
        list.reverse();
        list.print();

        return 0;
    }

