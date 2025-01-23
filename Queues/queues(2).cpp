//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T>
//class Stack {
//    T* arr;
//    int currSize;
//    int maxSize;
//    int top;
//
//public:
//    Stack() : currSize(0), maxSize(10), top(0) {
//        arr = new T[maxSize];
//    }
//    ~Stack() { delete[] arr; }
//
//    bool push(T n) {
//        if (!isFull()) {
//            arr[top] = n;
//            top++;
//            currSize++;
//            return true;
//        }
//        return false;
//    }
//
//    bool pop() {
//        if (!isEmpty()) {
//            top--;
//            currSize--;
//            return true;
//        }
//        return false;
//    }
//
//    bool isFull() { return currSize == maxSize; }
//    int getSize() { return currSize; }
//    bool isEmpty() { return currSize == 0; }
//
//    T Top() {
//        if (!isEmpty()) {
//            return arr[top - 1];
//        }
//        cout << "Stack is Empty" << endl;
//    }
//
//    void print() {
//        for (int i = 0; i < currSize; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//template <typename T>
//class Queue {
//    T* arr;
//    int currSize;
//    int maxSize;
//    int front;
//    int rear;
//
//public:
//    Queue() : currSize(0), maxSize(10), front(0), rear(-1) {
//        arr = new T[maxSize];
//    }
//    ~Queue() { delete[] arr; }
//
//    bool push(T n) {
//        if (!isFull()) {
//            rear++;
//            arr[rear] = n;
//            currSize++;
//            return true;
//        }
//        return false;
//    }
//
//    bool pop() {
//        if (!isEmpty()) {
//            front++;
//            currSize--;
//            return true;
//        }
//        return false;
//    }
//
//    bool isFull() { return currSize == maxSize; }
//    int getSize() { return currSize; }
//    bool isEmpty() { return currSize == 0; }
//
//    T Front() {
//        if (!isEmpty()) {
//            return arr[front];
//        }
//        cout << "Queue is Empty" << endl;
//    }
//
//    T Rear() {
//        if (!isEmpty()) {
//            return arr[rear];
//        }
//        cout << "Queue is Empty" << endl;
//    }
//
//    void print() {
//        for (int i = front; i <= rear; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//template <typename T>
//class LinkedList {
//    struct Node {
//        T data;
//        Node* next;
//        Node(T val) : data(val), next(nullptr) {}
//    };
//    Node* head;
//
//public:
//    LinkedList() : head(nullptr) {}
//    ~LinkedList() {
//        while (head) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//    void insertTail(T element) {
//        Node* newNode = new Node(element);
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
//    void print() {
//        Node* temp = head;
//        while (temp) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//};
//
//class Patient {
//    int id;
//    string name;
//    int age;
//    int sevLevel;
//    string ttype;
//
//public:
//    Patient(int ID, string Name, int Age, int Sev, string type)
//        : id(ID), name(Name), age(Age), sevLevel(Sev), ttype(type) {}
//
//    Patient() : id(0), name(""), age(0), sevLevel(0), ttype("") {}
//
//    ~Patient() {}
//
//    int getSev() const { return sevLevel; }
//    string getType() const { return ttype; }
//    int getId()  const{  return id; }
//    void changeType(string newT) { ttype = newT; }
//
//    friend ostream& operator<<(ostream& os, const Patient& p) {
//        os << "Patient(ID: " << p.id << ", Name: " << p.name
//            << ", Severity: " << p.sevLevel << ", Type: " << p.ttype << ")";
//        return os;
//    }
//};
//
//class Hospital {
//    Queue<Patient> general;
//    Queue<Patient> emergency;
//    Queue<Patient> surgery;
//    Queue<Patient> comma;
//    Stack<Patient> dischargeS;
//
//public:
//    void reg(Patient* patient) {
//        if (patient->getSev() >= 1 && patient->getSev() <= 4) {
//            general.push(*patient);
//        }
//        else if (patient->getSev() >= 5 && patient->getSev() <= 7) {
//            emergency.push(*patient);
//        }
//        else if (patient->getSev() >= 8) {
//            surgery.push(*patient);
//        }
//        
//    }
//
//    void priorityEmergency() {
//        LinkedList<Patient> highPriorityList;
//        while (!emergency.isEmpty()) {
//            Patient curr = emergency.Front();
//            emergency.pop();
//
//            if (curr.getSev() >= 6) {
//                highPriorityList.insertTail(curr);
//            }
//            else {
//                general.push(curr);
//            }
//        }
//
//        cout << "Patients moved to high priority list: "<<endl;
//        highPriorityList.print();
//    }
//
//    void dischargeFromQueue(Queue<Patient>& queue, Stack<Patient>& dischargeStack) {
//        Queue<Patient> tempQueue;
//        while (!queue.isEmpty()) {
//            Patient curr = queue.Front();
//            queue.pop();
//
//            if (curr.getType() == "treated") {
//                dischargeStack.push(curr);
//            }
//            else {
//                tempQueue.push(curr);
//            }
//        }
//
//        while (!tempQueue.isEmpty()) {
//            queue.push(tempQueue.Front());
//            tempQueue.pop();
//        }
//    }
//
//    void dischargePatients() {
//        dischargeFromQueue(general, dischargeS);
//        dischargeFromQueue(emergency, dischargeS);
//        dischargeFromQueue(surgery, dischargeS);
//        cout << "Patients have been discharged." << endl;
//    }
//
//    void undoDischarge() {
//        if (!dischargeS.isEmpty()) {
//            Patient recover = dischargeS.Top();
//            dischargeS.pop();
//            reg(&recover);
//            cout << "Restored patient: " << recover << endl;
//        }
//        else cout << "No discharged patients to undo." << endl;
//    }
//
//    void markAsTreated(int id) {
//  
//        int size = general.getSize();
//        for (int i = 0; i < size; i++) {
//            Patient p = general.Front();
//            general.pop();
//
//            if (p.getId() == id) {
//           
//                p.changeType("treated");
//                cout << "Patient " << p << " marked as treated." << endl;
//
//              
//                dischargeS.push(p);
//                return;  
//            }
//            general.push(p);  
//        }
//
//      
//        size = emergency.getSize();
//        for (int i = 0; i < size; i++) {
//            Patient p = emergency.Front();
//            emergency.pop();
//
//            if (p.getId() == id) {
//             
//                p.changeType("treated");
//                cout << "Patient " << p << " marked as treated." << endl;
//
//                dischargeS.push(p);
//                return; 
//            }
//            emergency.push(p);
//        }
//        size = surgery.getSize();
//        for (int i = 0; i < size; i++) {
//            Patient p = surgery.Front();
//            surgery.pop();
//
//            if (p.getId() == id) {
//                // Mark as treated
//                p.changeType("treated");
//                cout << "Patient " << p << " marked as treated." << endl;
//
// 
//                dischargeS.push(p);
//                return; 
//            }
//            surgery.push(p); 
//        }
//        cout << "ID NOT FOUND" << endl;
//    }
//
//
//    void printAllPatients() {
//        cout << "General queue:" << endl;
//        general.print();
//        cout << "Emergency queue: " << endl;
//        emergency.print();
//        cout << "Surgery queue: " << endl;
//        surgery.print();
//    }
//};
//
//void displayMenu() {
//    cout << "\n--- Hospital Management System ---\n";
//    cout << "1. Register a patient\n";
//    cout << "2. Process emergency priorities\n";
//    cout << "3. Discharge treated patients\n";
//    cout << "4. Undo last discharge\n";
//    cout << "5. Mark patient as treated\n";
//    cout << "6. Print all patients\n";
//    cout << "7. Exit\n";
//    cout << "Select an option: ";
//}
//
//int main() {
//    Hospital hospital;
//    int choice;
//
//    do {
//        displayMenu();
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            int id, age, sev;
//            string name, type;
//            cout << "Enter patient ID: ";
//            cin >> id;
//            cout << "Enter patient name: ";
//            cin >> name;
//            cout << "Enter patient age: ";
//            cin >> age;
//            cout << "Enter severity level (1-10): ";
//            cin >> sev;
//            cout << "Enter treatment type: ";
//            cin >> type;
//
//            Patient p(id, name, age, sev, type);
//            hospital.reg(&p);
//            break;
//        }
//        case 2:
//            hospital.priorityEmergency();
//            break;
//        case 3:
//            hospital.dischargePatients();
//            break;
//        case 4:
//            hospital.undoDischarge();
//            break;
//        case 5: {
//            Patient p;
//            int id;
//            cout << "Enter patient ID to mark as treated: ";
//            cin >> id;
//            hospital.markAsTreated(id);
//            break;
//        }
//        case 6:
//            hospital.printAllPatients();
//            break;
//        case 7:
//            cout << "Exiting system...\n";
//            break;
//        default:
//            cout << "Invalid choice. Please try again.\n";
//        }
//    } while (choice != 7);
//
//    return 0;
//}
