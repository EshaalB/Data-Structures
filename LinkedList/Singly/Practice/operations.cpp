//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* next;
//    Node(int data) {
//        this->data = data;
//        this->next = NULL;
//    }
//};
//// display
//void traverse(Node* root) {
//    Node* temp = root;
//    while (temp != NULL) {
//        cout << temp->data << " ";
//        temp = temp->next;
//    }
//    cout << endl;
//}
////display selected node 
//void traverseCustom(Node* root,int position) {
//    Node* temp = root;
//    int currentPosition = 0;
//    while (currentPosition<position && temp != NULL) {
// 
//        temp = temp->next;
//        currentPosition++;
//    }
//    cout << temp->data << " ";
//    cout << endl;
//}
//void insertStart(Node*& root, int data) {
//    Node* newNode = new Node(data);   
//    newNode->next = root;             // next = address of prev root
//    root = newNode;                   // root having value of new node 
//}
//
//void insertEnd(Node*& root, int data) {
//    Node* newNode = new Node(data);  
//    if (root == NULL) {            
//        root = newNode;
//        return;
//    }
//    Node* temp = root;
//    while (temp->next != NULL) {     // Traverse until you reach the last node
//        temp = temp->next;
//    }
//
//    temp->next = newNode;            //next of last node to value of newNode
//}
//
//void insertMiddle(Node*& root, int data, int position) {
//    Node* newNode = new Node(data);   
//    if (position == 0) {              
//        insertStart(root, data);
//        return;
//    }
//
//    Node* temp = root;
//    int currentPosition = 0;
//
//    // Traverse to the node just before the desired position
//    while (currentPosition < position - 1 && temp->next != NULL) {
//        temp = temp->next;
//        currentPosition++;
//    }
//
//    // Now temp is at the node just before the desired position
//    newNode->next = temp->next;  // New node points to the next node
//    temp->next = newNode;        // Previous node points to the new node
//}
//Node* findMiddle(Node*& root) {
//
//    Node* fast = root;
//    Node* slow = root;
//
//    while (fast != NULL and fast->next != NULL)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
// }
//void deleteStart(Node*& root) {
//    if (root == NULL) {
//        cout << "List is empty, nothing to delete." << endl;
//        return;
//    }
//    Node* temp = root;         // Temporarily store the first node
//    root = root->next;         // Move root to the next node
//    delete temp;               // Delete the old first node
//}
//
//void deleteEnd(Node*& root) {
//    if (root == NULL) {
//        cout << "List is empty, nothing to delete." << endl;
//        return;
//    }
//
//    if (root->next == NULL) {    
//        root = NULL;
//        return;
//    }
//
//    Node* temp = root;
//    Node* prev = NULL;
//
//    // Traverse to the last node while keeping track of the second-to-last node
//    while (temp->next != NULL) {
//        prev = temp;
//        temp = temp->next;
//    }
//
//    prev->next = NULL;  // Set the second-to-last node's next pointer to NULL
//    delete temp;        // Delete the last node
//}
//
//void deleteMiddle(Node*& root, int position) {
//    if (root == NULL) {
//        cout << "List is empty, nothing to delete." << endl;
//        return;
//    }
//
//    if (position == 0) { // If position is 0, delete the first node
//        deleteStart(root);
//        return;
//    }
//
//    Node* temp = root;
//    Node* prev = NULL;
//    int currentPosition = 0;
//
//    // Traverse to the node just before the desired position
//    while (currentPosition < position && temp != NULL) {
//        prev = temp;
//        temp = temp->next;
//        currentPosition++;
//    }
//
//    if (temp == NULL) {
//        cout << "Position out of bounds." << endl;
//        return;
//    }
//
//    // Now temp is the node to be deleted, and prev is the node before it
//    prev->next = temp->next;
//    delete temp;
//}
//void sorting(Node*& head) {
//    if (head == NULL || head->next == NULL) return;  // Handle empty or single element list
//
//    bool swapped;
//    Node* curr =head;
//    Node* end = NULL;  // Marks the sorted boundary
//
//    do {
//        swapped = false;
//        curr = head;
//
//        while (curr->next != NULL) {
//            if (curr->data > curr->next->data) {
//                // Swap the data if current node's data is greater than the next node's
//                swap(curr->data, curr->next->data);
//                swapped = true;  // A swap occurred
//            }
//            curr = curr->next;  // Move to the next node
//        }
//
//        end = curr;  // Update end to the last sorted element
//    } while (swapped);  // Repeat while swaps occur
//}
//void rearrange(Node*& head) {
//    Node* oddHead = nullptr, * evenHead = nullptr;
//    Node* oddTail = nullptr, * evenTail = nullptr;
//
//    Node* curr = head;
//    while (curr) {
//        if (curr->data % 2 != 0) { // Odd
//            if (!oddHead) {
//                oddHead = oddTail = curr;
//            }
//            else {
//                oddTail->next = curr;
//                oddTail = oddTail->next;
//            }
//        }
//        else { // Even
//            if (!evenHead) {
//                evenHead = evenTail = curr;
//            }
//            else {
//                evenTail->next = curr;
//                evenTail = evenTail->next;
//            }
//        }
//        curr = curr->next;
//    }
//
//    // Terminate the lists
//    if (oddTail) oddTail->next = nullptr;
//    if (evenTail) evenTail->next = nullptr;
//
//    // Reconstruct the linked list
//    if (oddHead) {
//        head = oddHead; // Start with the odd head
//        if (evenHead) {
//            oddTail->next = evenHead; // Attach even list
//        }
//    }
//    else {
//        head = evenHead; // If no odds, start with evens
//    }
//}
//
//int main() {
//    Node* n1 = new Node(10);         // Create the first node
//    Node* root = n1;
//
//    traverse(root);                  // Traverse the initial list
//
//    insertStart(root, 5);            // Insert at the start
//    traverse(root);                  // Traverse the updated list
//
//    insertEnd(root, 1);             // Insert at the end
//    insertEnd(root, 7);             // Insert at the end
//    insertEnd(root, 4);             // Insert at the end
//    traverse(root);                  // Traverse the updated list
//    sorting(root);
//    traverse(root);
//    traverseCustom(root, 2);
//    rearrange(root);
//    traverse(root);
//    insertMiddle(root, 12, 2);       // Insert at position 2 (0-based index)
//    traverse(root);                  // Traverse the final list
//
//
//    Node* middle = findMiddle(root);
//    if (middle != NULL) {
//        cout << "Middle element: " << middle->data << endl;
//    }
//    else {
//        cout << "List is empty." << endl;
//    }
//
//
//    deleteStart(root);               // Delete the first node
//    traverse(root);                  // Traverse the list after deletion
//
//    deleteEnd(root);                 // Delete the last node
//    traverse(root);                  // Traverse the list after deletion
//
//    deleteMiddle(root, 1);           // Delete node at position 1
//    traverse(root);                  // Traverse the list after deletion
//    sorting(root);
//    traverse(root);
//
//    return 0;
//}
