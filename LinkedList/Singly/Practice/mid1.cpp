//#include <iostream>
//
//struct Node {
//    char data;
//    Node* next;
//    Node(char val) : data(val), next(nullptr) {}
//};
//
//class LinkedList {
//public:
//    Node* head;
//
//    LinkedList() : head(nullptr) {}
//
//    void insert(char val) {
//        Node* newNode = new Node(val);
//        if (!head) {
//            head = newNode;
//            return;
//        }
//        Node* temp = head;
//        while (temp->next) {
//            temp = temp->next;
//        }
//        temp->next = newNode;
//    }
//
//    void insertAfter(Node* prevNode, char key) {
//        if (!prevNode) return;
//        Node* newNode = new Node(key);
//        newNode->next = prevNode->next;
//        prevNode->next = newNode;
//    }
//
//    void deleteAfter(Node* prevNode) {
//        if (!prevNode || !prevNode->next) return;
//        Node* toDelete = prevNode->next;
//        prevNode->next = toDelete->next;
//        delete toDelete;
//    }
//
//    void equalizeOccurrences(char key, int maxCount) {
//        Node* curr = head;
//        int count = 0;
//
//        // Count occurrences of the key
//        while (curr) {
//            if (curr->data == key) count++;
//            curr = curr->next;
//        }
//
//        // Reset curr to head to adjust occurrences
//        curr = head;
//
//        while (curr) {
//            if (count > maxCount) {
//                if (curr->data == key) {
//                    // Handle deletion
//                    Node* toDelete = curr;
//                    if (curr == head) {
//                        head = curr->next; // Update head if necessary
//                    }
//                    else {
//                        Node* temp = head;
//                        while (temp && temp->next != curr) {
//                            temp = temp->next;
//                        }
//                        if (temp) {
//                            temp->next = curr->next; // Bypass current node
//                        }
//                    }
//                    curr = curr->next; // Move to the next node
//                    delete toDelete; // Free the deleted node
//                    count--; // Decrement the count after deletion
//                    continue; // Continue without moving curr to next
//                }
//            }
//
//            if (count < maxCount) {
//                if (curr->data == key) {
//                    insertAfter(curr, key); // Insert after current
//                    count++; // Increment the count after insertion
//                    curr = curr->next; // Move to the next node
//                    continue; // Continue without moving curr to next
//                }
//            }
//
//            curr = curr->next; // Move to the next node in all other cases
//        }
//    }
//
//    void printList() {
//        Node* temp = head;
//        while (temp) {
//            std::cout << temp->data << " ";
//            temp = temp->next;
//        }
//        std::cout << std::endl;
//    }
//};
//
//int main() {
//    LinkedList list;
//    list.insert('a');
//    list.insert('b');
//    list.insert('a');
//    list.insert('c');
//    list.insert('b');
//    list.insert('d');
//
//    std::cout << "Original list: ";
//    list.printList();
//
//    list.equalizeOccurrences('a', 4);
//
//    std::cout << "Equalized list: ";
//    list.printList();
//
//    return 0;
//}
