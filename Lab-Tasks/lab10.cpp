#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class HashTable;

class HashItem {
    friend class HashTable;
private:
    int key;       // Index where your value will be stored
    string value;  // Actual value to be stored in HashTable
    int status;    // 0: Empty, 1: Deleted, 2: Occupied

    HashItem() : key(0), value(""), status(0) {}
};

class HashTable {
private:
    HashItem* hashArray;
    int capacity;
    int currentElements;
    int getNextCandidateIndex(int key, int i) {
        return (key + i ) % capacity;
    }

    int getNextCandidateIndexQuad(int key, int i) {
        return (key + i * i) % capacity;
    }

    void doubleCapacity() {
        int oldCapacity = capacity;
        HashItem* oldArray = hashArray;

        // Double the capacity
        capacity *= 2;
        hashArray = new HashItem[capacity];
        currentElements = 0;

        // Rehash all items from the old array
        for (int i = 0; i < oldCapacity; i++) {
            if (oldArray[i].status == 2) { // Only rehash occupied items
                insert(oldArray[i].key, oldArray[i].value);
            }
        }

        delete[] oldArray; // Delete old array
    }

public:
    HashTable() : currentElements(0), capacity(10) {
        hashArray = new HashItem[capacity];
    }

    HashTable(int const cap) : currentElements(0), capacity(cap) {
        if (capacity < 1) {
            cout << "Your capacity is less than one " << endl;
            capacity = 10;
        }
        hashArray = new HashItem[capacity];
    }

    void insert(int const key, string const value) {
        int index = key % capacity;
        int i = 0;

        // Use quadratic probing to find the next available slot
        while (i < capacity && hashArray[getNextCandidateIndex(index, i)].status == 2) {
            i++;
        }

        if (i == capacity) {
            cout << "Table is full, cannot insert key: " << key << endl;
            return;
        }

        int emptyIndex = getNextCandidateIndex(index, i);
        hashArray[emptyIndex].key = key;
        hashArray[emptyIndex].value = value;
        hashArray[emptyIndex].status = 2;
        currentElements++;

        // Check load factor and resize if needed
        if (currentElements >= 0.75 * capacity) doubleCapacity();
    }

    bool deleteKey(int const key) {
        int index = key % capacity;
        int i = 0;
        while (i < capacity && hashArray[getNextCandidateIndex(index, i)].status != 0) {
            int currIndex = getNextCandidateIndex(index, i);
            if (hashArray[currIndex].status == 2 && hashArray[currIndex].key == key) {
                hashArray[currIndex].status = 1; // Mark as deleted
                return true;
            }
            i++;
        }
        return false;
    }

    string get(int const key) {
        int index = key % capacity;
        int i = 0;
        while (i < capacity && hashArray[getNextCandidateIndex(index, i)].status != 0) {
            int currIndex = getNextCandidateIndex(index, i);
            if (hashArray[currIndex].status == 2 && hashArray[currIndex].key == key) {
                return hashArray[currIndex].value;
            }
            i++;
        }
        return "not found";
    }

    ~HashTable() {
        delete[] hashArray;
        hashArray = nullptr;
    }
};

int main() {
    HashTable hashtable(5); // Initialize the hash table with capacity 5

    int choice;
    do {
        cout << "\nHash Table Menu:\n";
        cout << "1. Insert a key-value pair\n";
        cout << "2. Get a value by key\n";
        cout << "3. Delete a key\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int key;
            string value;
            cout << "Enter key (integer): ";
            cin >> key;
            cout << "Enter value (string): ";
            cin.ignore(); // Ignore leftover newline character
            getline(cin, value);
            hashtable.insert(key, value);
            cout << "Key-value pair inserted successfully.\n";
            break;
        }

        case 2: {
            int key;
            cout << "Enter key to search: ";
            cin >> key;
            string result = hashtable.get(key);
            if (result != "not found") {
                cout << "Value at key " << key << ": " << result << endl;
            }
            else {
                cout << "Key " << key << " not found.\n";
            }
            break;
        }

        case 3: {
            int key;
            cout << "Enter key to delete: ";
            cin >> key;
            if (hashtable.deleteKey(key)) {
                cout << "Key " << key << " deleted successfully.\n";
            }
            else {
                cout << "Key " << key << " not found or already deleted.\n";
            }
            break;
        }

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
