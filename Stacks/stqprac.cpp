//#include <iostream>
//#include <queue>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int countStudents(vector<int>& students, vector<int>& sandwiches) {
//    queue<int> studentQueue;
//
//    // Fill the student queue
//    for (int student : students) {
//        studentQueue.push(student);
//    }
//
//    int sandwichIndex = 0;
//    int attempts = 0;
//
//    while (!studentQueue.empty() && attempts < studentQueue.size()) {
//        if (studentQueue.front() == sandwiches[sandwichIndex]) {
//            // If the student at the front of the queue takes the sandwich
//            studentQueue.pop();
//            sandwichIndex++;
//            attempts = 0; // Reset attempts as a match was made
//        }
//        else {
//            // If the student doesn't take the sandwich, move them to the back of the queue
//            studentQueue.push(studentQueue.front());
//            studentQueue.pop();
//            attempts++;
//        }
//    }
//
//    // Remaining students in the queue are unable to eat
//    return studentQueue.size();
//}
//
//string removeDuplicates(string S) {
//    stack<char> charStack;
//
//    // Traverse the string
//    for (char ch : S) {
//        // If the stack is not empty and the top character is the same as the current character, pop the stack
//        if (!charStack.empty() && charStack.top() == ch) {
//            charStack.pop();
//        }
//        else {
//            // Otherwise, push the current character onto the stack
//            charStack.push(ch);
//        }
//    }
//
//    // Build the result string from the stack
//    string result = "";
//    while (!charStack.empty()) {
//        result = charStack.top() + result; // Add characters in reverse order
//        charStack.pop();
//    }
//
//    return result;
//}
//
//int main() {
//    vector<int> students = { 1, 1, 1, 0, 0, 1 };
//    vector<int> sandwiches = { 1, 0, 0, 0, 1, 1 };
//
//    int result = countStudents(students, sandwiches);
//    cout << "Number of students unable to eat: " << result << endl;
//
//    string S = "abbaca";
//    string finalString = removeDuplicates(S);
//    cout << "Final string after removing duplicates: " << finalString << endl;
//
//    return 0;
//}
