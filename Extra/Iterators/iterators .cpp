//#include <iostream>
//#include <vector>
//#include <list>
//#include <map>
//#include <iterator> // For next, prev, distance
//
//using namespace std;
//
//int main() {
//    // Vector example
//    vector<int> numbers = { 10, 20, 30, 40, 50 };
//    vector<int>::iterator it;
//
//    cout << "Vector operations:\n";
//
//    // Advance iterator by 2
//    it = numbers.begin();
//    advance(it, 2); // Points to 30
//    cout << "Iterator after advancing 2 steps: " << *it << endl;
//
//    // Insert at iterator position
//    numbers.insert(it, 5); // Insert 5 before 30
//    cout << "Vector after inserting 5: ";
//    for (it = numbers.begin(); it != numbers.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    // Erase element at iterator position (points to 30 now)
//    it = numbers.begin();
//    advance(it, 3); // Points to 30
//    numbers.erase(it); // Erases 30
//    cout << "Vector after erasing 30: ";
//    for (it = numbers.begin(); it != numbers.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    // Distance between two iterators
//    int dist = distance(numbers.begin(), numbers.end());
//    cout << "Distance between first and last element: " << dist << endl;
//
//    // List example
//    list<string> tasks = { "Math homework", "Clean room", "Study DSA", "Go for a walk" };
//    list<string>::iterator lit;
//
//    cout << "\nList operations:\n";
//    // Traverse and print list elements
//    for (lit = tasks.begin(); lit != tasks.end(); ++lit) {
//        cout << *lit << " ";
//    }
//    cout << endl;
//
//    // Erase an element (e.g., "Clean room")
//    lit = tasks.begin();
//    advance(lit, 1); // Points to "Clean room"
//    tasks.erase(lit); // Erases "Clean room"
//    cout << "List after erasing 'Clean room': ";
//    for (lit = tasks.begin(); lit != tasks.end(); ++lit) {
//        cout << *lit << " ";
//    }
//    cout << endl;
//
//    // Map example
//    map<int, string> students = { {1, "Alice"}, {2, "Bob"}, {3, "Charlie"} };
//    map<int, string>::iterator mit;
//
//    cout << "\nMap operations:\n";
//    // Traverse and print map elements
//    for (mit = students.begin(); mit != students.end(); ++mit) {
//        cout << mit->first << ": " << mit->second << " ";
//    }
//    cout << endl;
//
//    // Insert a new element in the map
//    students.insert({ 4, "David" });
//    cout << "Map after inserting (4, 'David'): ";
//    for (mit = students.begin(); mit != students.end(); ++mit) {
//        cout << mit->first << ": " << mit->second << " ";
//    }
//    cout << endl;
//
//    // Reverse iteration with reverse iterators (rbegin, rend)
//    cout << "Map in reverse order: ";
//    for (auto mit = students.rbegin(); mit != students.rend(); ++mit) {
//        cout << mit->first << ": " << mit->second << " ";
//    }
//    cout << endl;
//
//    // Using next and prev
//    mit = next(students.begin(), 2); // Points to the element with key 3 (Charlie)
//    cout << "Element 2 steps ahead from the beginning: " << mit->first << ": " << mit->second << endl;
//
//    mit = prev(students.end(), 1); // Points to the last element (David)
//    cout << "Element 1 step before the end: " << mit->first << ": " << mit->second << endl;
//
//    return 0;
//}
