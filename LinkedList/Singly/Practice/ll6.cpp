//#include <iostream>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left, * right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//struct DoublyListNode {
//    int val;
//    DoublyListNode* next, * prev;
//    DoublyListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
//};
//
//void flatten(TreeNode* root) {
//     
//}
//
//void printList(ListNode* head) {
//    while (head != nullptr) {
//        cout << head->val << " ";
//        head = head->next;
//    }
//    cout << endl;
//}
//void printList1(DoublyListNode* head) {
//    while (head != nullptr) {
//        cout << head->val << " ";
//        head = head->next;
//    }
//    cout << endl;
//}
//void printList2(DoublyListNode* head) {
//    // Traverse to the last node (tail)
//    DoublyListNode* tail = head;
//    while (tail != nullptr && tail->next != nullptr) {
//        tail = tail->next;
//    }
//
//    // Print the list in reverse order by following prev pointers
//    while (tail != nullptr) {
//        cout << tail->val << " ";
//        tail = tail->prev;
//    }
//    cout << endl;
//}
//
//void rearrangeEvenOdd(ListNode* head) {
//    ListNode* oddHead = nullptr;
//    ListNode* oddTail = nullptr;
//    ListNode* evenHead = nullptr;
//    ListNode* evenTail = nullptr;
//    ListNode* curr = head;
//    while (curr) {
//        if (curr->val % 2) {
//            if (!oddHead) oddHead = oddTail = curr;
//            else {
//                oddTail->next = curr;
//                oddTail = curr;
//            }
//        }
//        else {
//            if (!evenHead) evenHead = evenTail = curr;
//            else {
//                evenTail->next = curr;
//                evenTail = curr;
//            }
//        } 
//
//        curr = curr->next;
//    }
//    if (oddTail) oddTail->next = nullptr;
//    if (evenTail) evenTail->next = nullptr;
//    if (oddTail) {
//        oddTail->next = evenHead;
//    }
//
//    // Adjust curr to traverse the updated list
//    curr = oddHead;  // Start at the head of the odd list
//
//}
//DoublyListNode* reverse(DoublyListNode* head2) {
//    DoublyListNode* temp = nullptr;
//    DoublyListNode* curr = head2;
//
//    // Traverse the list and reverse the links
//    while (curr != nullptr) {
//        // Swap next and prev pointers
//        temp = curr->prev;
//        curr->prev = curr->next;
//        curr->next = temp;
//
//        // Move to the next node (which is prev after swapping)
//        curr = curr->prev;
//    }
//
//    // After the loop, curr is nullptr, so temp will be pointing to the last node (new head)
//    return temp;  // temp points to the new head after reversal
//}
//
//
//int main() {
//    // Create a binary tree
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
//
//    // Flatten the binary tree into a linked list
//    flatten(root);
//
//    // Print the resulting linked list
//    ListNode* head = nullptr; // This should be set by your flatten function
//    printList(head);
//    ListNode* head1 = new ListNode(1);
//    head1->next = new ListNode(2);
//    head1->next->next = new ListNode(3);
//    head1->next->next->next = new ListNode(4);
//    head1->next->next->next->next = new ListNode(5);
//
//
//
//    // Rearrange the linked list
//    rearrangeEvenOdd(head1);
//    printList(head1);
//
//    DoublyListNode* head2 = new DoublyListNode(1);
//    head2->next = new DoublyListNode(2);
//    head2->next->prev = head2;
//    head2->next->next = new DoublyListNode(3);
//    head2->next->next->prev = head2->next;
//
//    // Reverse the doubly linked list
//   // DoublyListNode* rev;reverse(head2);
//    printList2(head2);
//    return 0;
//}
