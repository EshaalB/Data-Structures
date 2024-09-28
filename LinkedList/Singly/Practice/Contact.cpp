//#include <iostream>
//using namespace std;
//template <typename T>
// 
//class ContactManager
//{
//	class Contact
//	{
//	 
//	public:
//		T name;
//		T phoneNo;
//		Contact* next;
//		Contact(T name, T phoneNo) : name(name), phoneNo(phoneNo), next(NULL) {}
//	};
//private:
//	Contact* head;
//	Contact* tail;
//public:
//	ContactManager(): head(NULL),tail(NULL) {}
//	// ~ContactManager();
//	void addContact(string name,string phoneNo) {
//		Contact* newContact = new Contact(name,phoneNo);
//		Contact* current = head;
//
//		newContact->next = head;
//		head = newContact;
//	}
//	void displayContacts() {
//		Contact* current = head;
//		while (current!=NULL)
//		{
//			cout <<"Name:"<< current->name << " " <<"Phone No:" << current->phoneNo << " ";
//			current = current->next;
//			cout << endl;
//		}
//		 
//
//	}
//	bool search(string name) { 
//		Contact* current = head;
//		while (current!=NULL)
//		{
//			if (current->name == name) 
//				cout << "Found:" << "Name:" << current->name << " " << "Phone No:" << current->phoneNo << " ";
//			
//			
//			current = current->next;
//		}
//		return true;
//		 
//	}
//    bool deleteContact(string name) {
//        Contact* current = head;
//        Contact* previous = NULL;
//      
//
//        while (current != NULL) {
//            if (current->name == name) {
//                if (current == head) {
//                    head = current->next;
//                }
//                else {
//                    previous->next = current->next;
//                }
//                Contact* temp = current;
//                current = current->next;
//                delete temp;
//               
//            }
//            else {
//                previous = current;
//                current = current->next;
//            }
//        }
//
//        return true;
//    }
//
//};
// 
// 
//int main() {
//	ContactManager <string> c1;
//    string name, phoneNo;
//	 
//    int choice;
//
//    do {
//        cout << "\n===== ASSIGNMENT  =====\n";
//        cout << "1. Add a new contact \n";
//        cout << "2. Display all contacts \n";
//        cout << "3. Search Contact by name \n";
//        cout << "4. Delete Contact by name\n";
//        cout << "5. EXIT \n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            cout << "Enter name:";
//            cin >> name;
//			cout << "Enter number:";
//            cin >> phoneNo;
//            c1.addContact(name,phoneNo );
//            c1.displayContacts();
//			cout << endl;
// ;
//
//            break;
//        }
//        case 2: {
//			cout << "All contacts:" << endl;
//			c1.displayContacts();
//            break;
//        }
//        case 3: {
//			cout << "Enter name that you want to find :";
//			cin >> name;
//			if (c1.search(name)) cout << "Search Complete" << endl;
//			
//			else cout << "No contact found with name: " << name << endl;
//            break;
//        }
//        case 4: {
//
//			cout << "Enter name that you want to delete :";
//			cin >> name;
//			if (c1.deleteContact(name)) cout << "Deleted" << endl;
//			else cout << "Name is not found " << endl;
//            break;
//        }case 5: {
//
//            cout << "Exiting..." << endl;
//            break;
//        }
//        default: {
//
//            cout << "Invalid choice. Please try again." << endl;
//            break;
//        }
//        }
//    } while (choice != 5);
//
//    return 0;
//}