#include <iostream>
using namespace std;
template <typename T>
class SortedSet {
    struct Node {
        T data;
        Node* next;
        Node(T const& element) : data(element), next(NULL) {}
    };
    Node* head;
    Node* tail;
public:
    //TASK 1 CONSTRUCTOR 
    SortedSet():head(NULL),tail(NULL){}

    //TASK 2 INSERT FUNCTION
    bool insert(T const data) {
       
        Node* newNode = new Node(data);
        if (newNode == NULL) return false;  
        
        if (head == NULL) {
            head = newNode;
            return true;
        }
        //Sorted insertion
        Node* current = head;
        Node* previous = NULL;
         
        while (current != NULL && current->data < newNode->data) {
            previous = current;
            current = current->next;
        }
        newNode->next = current;
        if (previous == NULL)   head = newNode;
           
        else previous->next = newNode;
       
        current = head;  
        //Getting rid of duplicates 
          while (current != NULL && current->next != NULL) {
            if (current->data == current->next->data)  current->next = current->next->next;
                  
            else  current = current->next;
        }

        return true;
    }

  //TASK 3 DELETE  FUNCTION

    bool deleteIndex(int const index) {
        Node* current = head;
        Node* previous = NULL;
        int count = 1;
        while (count<index && current!=NULL) // iiterating to the index which needs to be deleted
        {
            previous = current;
            current = current->next;
            count++;
        }
        previous->next = current->next;
        delete current;

        return true;
    }
    //TASK 4  PRINT  FUNCTION
    void print() const {
        Node* current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }

    }
    //TASK 5  UNION  FUNCTION
     
    void unionSet(SortedSet<T> const& otherSet) {
        Node* temp1 = head;            
        Node* temp2 = otherSet.head;   
        Node* prev = NULL;          

        while (temp1 != NULL && temp2 != NULL) {
            if (temp2->data < temp1->data) {
                
                Node* newNode = new Node(temp2->data);
                if (prev == NULL) {
                    newNode->next = head;
                    head = newNode;
                }
                else {
                    prev->next = newNode;
                    newNode->next = temp1;
                }
                prev = newNode;
                temp2 = temp2->next;
            }
            //remove duplicates
            else if (temp2->data == temp1->data) temp2 = temp2->next;
                 
            else {
                prev = temp1;
                temp1 = temp1->next;
            }
        }
    
        while (temp2 != NULL) {
            Node* newNode = new Node(temp2->data);
            if (prev == NULL) {
                newNode->next = head;
                head = newNode;
            }
            else prev->next = newNode;
                 
            prev = newNode;
            temp2 = temp2->next;
        }
    }


   // Q2 LINKED LIST ROTATION BY K NODES 
   
    void rotate(int k) {
        if (head == NULL || head->next == NULL) return;  

        Node* current = head;
        int size = 1;

        //size calculation
        while (current->next != NULL) {
            current = current->next;
            size++;
        }

        k = k % size; // make sure k is less than size 
        if (k == 0) return;  

        // convert singly to circular for ease 
        current->next = head;

        
        for (int i = 0; i < k; i++) current = current->next;
             
         // break circular ll 
        head = current->next;
        current->next = NULL;
    }



    // Q3 REVERSING THE SORTED LINKED LIST 
    void reverse(){
        Node* current = head;
        Node* prev = NULL;
        while (current!=NULL)
        {
            tail = current->next;
            current->next = prev;
            prev = current;
            current = tail;
        }
        head = prev;
    }
    ~SortedSet()
    {
        Node* temp1, * temp2;
        temp1 = head;
        while (temp1 != NULL)
        {
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }
    }
};
int main() {
    SortedSet<int> s1;
    SortedSet<int> s2;
    SortedSet<int> s3;
    int choice;

    do {
        cout << "[ASSIGNMENT1]" << endl;
        cout << "1. Q1 " << endl;
        cout << "2. Q2 " << endl;
        cout << "3. Q3 " << endl;
        cout << "4. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Insert elements into Set 1
            
            s1.insert(60);
            s1.insert(50);
            s1.insert(40);
            s1.insert(12);
            cout << "AFTER INSERTION: ";
            cout << "SET1: ";
            s1.print();
            cout << endl << endl;

            // Insert elements into Set 2
            s2.insert(60);
            s2.insert(50);
            s2.insert(40);
            s2.insert(12);
            cout << "SET2: ";
            s2.print();
            cout << endl << endl;

            // Delete an index from both sets
            s1.deleteIndex(2);
            s2.deleteIndex(3);
            cout << "AFTER DELETING INDEX IN SET1: ";
            s1.print();
            cout << endl;
            cout << "AFTER DELETING INDEX IN SET2: ";
            s2.print();
            cout << endl << endl;

            // Union of the sets
            s1.unionSet(s2);
            cout << "AFTER TAKING UNION: ";
            s1.print();
            cout << endl << endl;

            break;
        }
        case 2: {
            // Rotate operation
            s3.insert(10);
            s3.insert(20);
            s3.insert(30);
            s3.insert(60);
            s3.insert(50);
            s3.insert(40);
            cout << "SET3: ";
            s3.print();
            cout << endl << endl;
            int value;
        EnterValue:
            cout << "Enter value for rotation: ";
            cin >> value;
            if (value <= 0) {
                cout << "Error! Please enter a positive number." << endl;
                goto EnterValue;
            }

          
            s3.rotate(value);
            cout << "AFTER ROTATING SET1: ";
            s3.print();
            cout << endl << endl;

            break;
        }
        case 3: {
            s3.insert(10);
            s3.insert(20);
            s3.insert(30);
            s3.insert(40);
            s3.insert(14);
            cout << "SET3: ";
            s3.print();
            cout << endl << endl;
            // Reverse operation
            cout << "AFTER REVERSE: ";
            s3.reverse();
            s3.print();
            cout << endl;

            break;
        }
        case 4: {
          
            cout << "Exiting the program" << endl;
            break;
        }
        default: {
            
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 4);
    return 0;
}