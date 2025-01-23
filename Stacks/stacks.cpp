//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// Task 1: Implement a template-based stack using a singly linked list
//template <typename T>
//class Stack {
//private:
//    struct Node {
//        T data;
//        Node* next;
//        Node(T const& element) : data(element), next(nullptr) {}
//    };
//
//    Node* topNode;
//    int stackSize;
//
//public:
//    Stack() : topNode(nullptr), stackSize(0) {}
//
//    int size() {
//        return stackSize;
//    }
//
//    bool isEmpty() {
//        return topNode == nullptr;
//    }
//
//    bool top(T& element) {
//        if (isEmpty())
//            return false;
//
//        element = topNode->data;
//        return true;
//    }
//
//    void pop() {
//        if (isEmpty()) {
//            cout << "Stack is empty." << endl;
//            return;
//        }
//
//        Node* tempTop = topNode;
//        topNode = topNode->next;
//        delete tempTop;
//
//        stackSize--;
//    }
//
//    void push(const T& element) {
//        Node* newNode = new Node(element);
//        newNode->next = topNode;
//        topNode = newNode;
//        stackSize++;
//    }
//    template <typename T>
//    void popAndDisplay(Stack<T>& stack1, Stack<T>& stack2) {
//        while (!stack1.isEmpty()) {
//            T element;
//            stack1.top(element);
//            stack1.pop();
//            stack2.push(element);
//        }
//
//        cout << "Stack  ";
//        stack2.display();
//    }
//    void display() {
//        Node* temp = topNode;
//        while (temp != nullptr) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//
//};
//
//// Task 2: Delete last element of a stack
//template <typename T>
//void deleteLastElement(Stack<T>& stack) {
//    Stack<T> tempStack;
//
//    while (!stack.isEmpty()) {
//        T element;
//        stack.top(element);
//        stack.pop();
//
//        if (!stack.isEmpty()) {
//            tempStack.push(element);
//        }
//    }
//
//    while (!tempStack.isEmpty()) {
//        T element;
//        tempStack.top(element);
//        tempStack.pop();
//        stack.push(element);
//    }
//}
//
//// Task 3: Convert infix to postfix
//int precedence(char op) {
//    if (op == '+' || op == '-') return 1;
//    if (op == '*' || op == '/') return 2;
//    return 0;
//}
//
//string infixToPostfix(string infix) {
//    Stack<char> s;
//    string postfix = "";
//
//    for (char c : infix) {
//        if (c == ' ') continue;
//
//        if (c == '(') {
//            s.push(c);
//        }
//        else if (c == ')') {
//            char topChar;
//            while (!s.isEmpty()) {
//                s.top(topChar);
//                if (topChar == '(') {
//                    s.pop();
//                    break;
//                }
//                postfix += topChar;
//                s.pop();
//            }
//        }
//        else if (c == '+' || c == '-' || c == '*' || c == '/') {
//            char topChar;
//            while (!s.isEmpty()) {
//                s.top(topChar);
//                if (topChar == '(' || precedence(c) > precedence(topChar)) break;
//                postfix += topChar;
//                s.pop();
//            }
//            s.push(c);
//        }
//        else {
//            postfix += c;
//        }
//    }
//
//
//    char topChar;
//    while (!s.isEmpty()) {
//        s.top(topChar);
//        postfix += topChar;
//        s.pop();
//    }
//
//    return postfix;
//}
//
//
//bool isPalindrome(string s) {
//    Stack<char> st;
//
//    for (char c : s) {
//        st.push(c);
//    }
//
//    for (char c : s) {
//        char topChar;
//        st.top(topChar);
//        if (c != topChar) return false;
//        st.pop();
//    }
//
//    return true;
//}
//template <typename T>
//void reverseAndDisplay(Stack<T>& stack) {
//    Stack<T> reversedStack;
//    T element;
//
//
//    while (!stack.isEmpty()) {
//        stack.top(element);
//        stack.pop();
//        reversedStack.push(element);
//    }
//
//
//    cout << " Stack (bottom to top) ";
//    reversedStack.display();
//
//
//    while (!reversedStack.isEmpty()) {
//        reversedStack.top(element);
//        reversedStack.pop();
//        stack.push(element);
//    }
//}
//
//int main() {
//
//    Stack<int> stack;
//    stack.push(1);
//    stack.push(2);
//    stack.push(3);
//    Stack<int> stackr;
//    reverseAndDisplay(stack);
//    cout << "Size: " << stack.size() << endl;
//    cout << "Empty (true = 1, false = 0): " << stack.isEmpty() << endl;
//
//    int topElement;
//    if (stack.top(topElement))
//        reverseAndDisplay(stack);
//    else
//        cout << "Stack is empty." << endl;
//
//    cout << "Deletion" << endl;
//    stack.pop();
//    reverseAndDisplay(stack);
//
//
//    Stack<int> stack2;
//    stack2.push(1);
//    stack2.push(2);
//    stack2.push(3);
//    stack2.push(4);
//    stack2.push(5);
//
//    cout << "Original stack: ";
//    reverseAndDisplay(stack2);
//
//    deleteLastElement(stack2);
//
//    cout << "After deleting last element: ";
//    stack2.display();
//
//
//    string infix = "A + B * C + D";
//    string postfix = infixToPostfix(infix);
//    cout << "Infix: " << infix << endl;
//    cout << "Postfix: " << postfix << endl;
//
//
//    string s = "sasas";
//    if (isPalindrome(s))
//        cout << "String is palindrome." << endl;
//    else
//        cout << "String is not palindrome." << endl;
//
//    return 0;
//}