//#include <iostream>
//using namespace std;
//template <typename T>
//class LinkedList {
//	struct Node
//	{
//		T data;
//		Node* next;
//		Node(T data) {
//			this->data = data;
//			this->next = NULL;
//		}
//	};
//	Node* head;
//	Node* tail;
//
//public:
//	LinkedList() :head(NULL), tail(NULL) {}
//	bool insert(T data) {
//		Node* newNode = new Node(data);
//		if (newNode == NULL) return false;
//
//		Node* current = head;
//		Node* previous = NULL;
//
//		while (current != NULL && current->data < newNode->data)
//		{
//			previous = current;
//			current = current->next;
//		}
//		newNode->next = current;
//		if (current == head) head = newNode;
//		else  previous->next = newNode;
//	     return true;
//	}
//	int getSize() {
//		Node* current = head;
//		int size = 0;
//		while (current != NULL)
//		{
//			current = current->next;
//			size++;
//		}
//		return size;
//	}
//	void kNode(int k) {
//		int length = getSize();
//		Node* temp = head;
//
//		for (int i = 0; i < length - k; i++)
//		{
//			temp = temp->next;
//		}
//		cout << "K node value is" << temp->data;
//
//	}
//	void printMiddle() { // method 1
//		Node* current = head;
//		int listSize = getSize();
//		int middle = listSize / 2;
//		int count = 0;
//		while (current != NULL && count < middle)
//		{
//			current = current->next;
//			count++;
//		}
//		if (current != NULL) {
//			cout << "Middle is: " << current->data;
//		}
//	}
//	void  printMiddle1() { // method 2
//		Node* fast = head;
//		Node* slow = head;
//		while (fast != NULL && fast->next != NULL)
//		{
//			fast = fast->next->next;
//			slow = slow->next;
//		}
//		if (slow != NULL) {
//			cout << "Middle is: " << slow->data;
//		}
//	}
//	void deleteLastOccurrence(int key) {
//		if (head == NULL) return;  
//
//		Node* temp = head;
//		Node* temp1 = NULL;   
//
//		 
//		while (temp->next != NULL) {
//			if (temp->next->data == key) {
//				temp1 = temp;  
//			}
//			temp = temp->next;
//		}
//
// 
//		if (temp1 != NULL) {
//			Node* toDelete = temp1->next;   
//			temp1->next = toDelete->next;   
//			delete toDelete;                      
//		}
//		 
//		else if (head->data == key) {
//			Node* toDelete = head;
//			head = head->next;
//			delete toDelete;
//		}
//	 
//	}
//	void countOccurence(int key) {
//		if (head == NULL) return;
//
//		Node* temp = head;
//		int count = 0;
//		while (temp!= NULL)
//		{
//			if (temp->data == key)count++;
//			temp = temp->next;
//		}
//		 
//		cout << endl;
//		cout << "count is:" << count;
//	}
//	void deleteMN(int n,int m) {
//		Node* curr = head;
//		Node* temp =NULL;
//
//		while (curr!=NULL)
//		{
//			for (int i = 1; i < m; i++) curr = curr->next;
//
//			if (curr == NULL) return ;
//
//			temp = curr->next;
//
//			for (int i = 1; i <= n; i++)
//			{
//				Node* delNode = temp;
//				 temp = temp->next;
//				delete delNode;
//			}
//			curr->next = temp;
//			curr = temp;
//			 
//
//		}
//
//	}
//	void pairwiseSwap() {
//		Node* curr = head;
//		while (curr!=NULL && curr->next!=NULL)
//		{
//			swap(curr->data, curr->next->data);
//			curr = curr->next->next;
//		}
//	}
//	void sorting() {
//
//		Node* curr = head;
//		Node* prev = NULL;
//		if (head == NULL || head->next == NULL) return;
//		while (curr->next!=NULL)
//		{
//			if (curr->data  < curr->next->data) {
//				prev = curr;
//				curr = curr->next;
//			}
//				 
//		}
//		prev->next = NULL;
//	}
//	void rearrange() {
//		Node* oddHead = NULL;
//		Node* evenHead = NULL;
//		Node* oddTail = NULL;
//		Node* evenTail = NULL;
//
//		Node* curr = head;
//		while (curr)
//		{
//			if (curr->data % 2 != 0) {
//				if (!oddHead) oddHead = oddTail = curr;
//				else {
//					oddHead->next = curr;
//					oddTail = oddTail->next;
//				}
//			}
//			else {
//				if (!evenHead) evenHead = evenTail = curr;
//				else {
//					evenHead->next = curr;
//					evenTail = evenTail->next;
//				}
//			}
//			curr = curr->next;
//		}
//		if (oddTail) oddTail->next = NULL;
//		if (evenTail) evenTail->next = NULL;
//
//		head = NULL;
//		Node* tail = NULL;
//		while (oddHead && evenHead) {
//			if (!head) {
//				head = oddHead;
//				tail = oddHead;
//				oddHead = oddHead->next;
//			} else{ 
//				tail->next = oddHead;
//				tail = tail->next;
//				oddHead = oddHead->next;
//			}
//			tail->next = evenHead;
//			tail = tail->next;
//			evenHead = evenHead->next;
//		}
//		if (oddHead) tail->next = oddHead;
//		if (evenHead) tail->next = evenHead;
//	}
//	void reverseSublists(int m, int n) {
//		if (m >= n || head == NULL) return;
//
//		Node* curr = head;
//		Node* prev = NULL;
// 
//		for (int i = 1; curr != NULL && i < m; i++) {
//			prev = curr;
//			curr = curr->next;
//		}
//
//		if (curr == NULL) return;  
//
//		 
//		Node* con = prev;   
//		Node* tail = curr;  
//
//		Node* nextNode = NULL;
//		prev = NULL;
// 
//		for (int i = m; curr != NULL && i <= n; i++) {
//			nextNode = curr->next;
//			curr->next = prev;
//			prev = curr;
//			curr = nextNode;
//		}
//
//	 
//		if (con != NULL) {
//			con->next = prev;  
//		}
//		else {
//			head = prev;  
//
//		tail->next = curr;  
//	}
//
//	void print() {
//		Node* current = head;
//		while (current!=NULL)
//		{
//			cout << current->data << " ";
//			current = current->next;
//		}
//		cout << endl;
//	}
//	 
//};
// 
//int main() { 
//	LinkedList<int> l1;
//	l1.insert(1);
//	l1.insert(3);
//	l1.insert(4);
//	l1.insert(3);
//	l1.insert(5);
//	l1.insert(6);
//	l1.insert(2);
//	l1.insert(3);
//	l1.rearrange();
//	l1.print();
//	l1.printMiddle();
//	cout << endl;
//	l1.printMiddle1();
//	cout << endl;
//
//	l1.kNode(3);
//	cout << endl;
//	l1.deleteLastOccurrence(3);
//	l1.print();
//	l1.pairwiseSwap();
//	l1.print();
//	l1.countOccurence(3);
//	cout << endl;
//	  l1.deleteMN(1, 1);
//	  l1.print();
//
//	   
//	return 0;
//}