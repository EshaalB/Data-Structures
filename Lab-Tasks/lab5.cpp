#include <iostream>
using namespace std;

// Q1 
int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Q2 
void findSubsets(string s, string current, int index) {
    if (index == s.size()) {
        cout << current << endl;
        return;
    }
    findSubsets(s, current + s[index], index + 1);
    findSubsets(s, current, index + 1);
}

// Q3
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return n % 10 + sumOfDigits(n / 10);
}

// Q4 
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Q5
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Q6 
class LinkedList {
    struct Node {
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
       
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head; 
        head = newNode;
    }

    bool searchLinkedList(int t) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == t) return true;
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    int option;

    do {
        cout << "Enter option:" << endl;
        cout << "1. Q1" << endl;
        cout << "2. Q2" << endl;
        cout << "3. Q3" << endl;
        cout << "4. Q4" << endl;
        cout << "5. Q5" << endl;
        cout << "6. Q6" << endl;
        cout << "7. Exit" << endl;

        cin >> option;

        switch (option) {
        case 1: {
            int n ; 
            cout << "Enter value:" << endl;
            cin >> n;
            cout << "Fibonacci of " << n << " is: " << fibonacci(n) << endl;
            break;
        }
        case 2: {
            string input;
            cout << "Enter string" << endl;
            cin >> input;
            cout << "Subsets of " << input << ":" << endl;
            findSubsets(input, "", 0);
            break;
        }
        case 3: {
            int n;
            cout << "Enter value:" << endl;
            cin >> n;
            cout << "Sum of digits of " << n << " is: " << sumOfDigits(n) << endl;  
            break;
        }
        case 4: {
            int n;
            cout << "Enter value:" << endl;
            cin >> n;
            cout << "Factorial of " << n << " is: " << factorial(n) << endl; 
            break;
        }
        case 5: {
            int a,b;
            cout << "Enter a and b :" << endl;
            cin >> a  >> b;
            cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;   
            break;
        }
        case 6: {
            LinkedList l1;
            l1.insert(3);
            l1.insert(1);
            l1.insert(2);
            int target;
            cout << "Enter target" << endl;
            cin >> target;
            cout << "Value " << target << " found in linked list: " << (l1.searchLinkedList(target) ? "True" : "False") << endl;  
            break;
        }
        case 7:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid." << endl;
            break;
        }
    } while (option != 7);

    return 0;
}
