////#include <iostream>
////#include <cassert>
////#include <fstream>
////#include <string>
////using namespace std;
////
////template <typename v>
////struct HashItem {
////    int key;        
////    v value;        
////    short status;   // 0 = empty, 1 = deleted, 2 = occupied
////
////    HashItem() : key(0), value(v()), status(0) {}
////};
////
////// HASH MAP CLASS
////template <typename v>
////class HashMap {
////protected:
////    HashItem<v>* hashArray; 
////    int capacity;            
////    int currVal;      
////
////    // Func for linear probing
////    virtual int getNextCandidateIndex(int hashKey, int i) const { return (hashKey + i) % capacity; }
////
////    // Func for resize 
////    void doubleCapacity() {
////        int oldCapacity = capacity;
////        HashItem<v>* oldArray = hashArray;
////
////        capacity *= 2;
////        hashArray = new HashItem<v>[capacity];
////        currVal = 0;
////
////        for (int i = 0; i < oldCapacity; i++) {
////            if (oldArray[i].status == 2) {
////                insert(oldArray[i].key, oldArray[i].value);
////                currVal++; // reinsert existing elements using insert()
////            }
////           
////        }
////
////        delete[] oldArray;
////    }
////
////
////public:
////    // Default constructor
////    HashMap() : capacity(10), currVal(0) {
////        hashArray = new HashItem<v>[capacity];  
////    }
////
////    // Constructor with custom capacity
////    HashMap(int const capacity) : capacity(capacity), currVal(0) {
////        assert(capacity > 1);   
////        hashArray = new HashItem<v>[capacity];
////    }
////
////    // func for insertion 
////    void insert(int const hashKey, v const value) {
////        int index = hashKey % capacity;
////        int i = 0;
////
////       
////        while (i < capacity && hashArray[getNextCandidateIndex(index, i)].status == 2) {  i++; }
////
////        // If the map is full, resize it
////        if (i == capacity) {
////            cout << "HashMap full, resizing.." << endl;
////            doubleCapacity();   
////            insert(hashKey, value);
////            return;
////        }
////
////        // Insert in empty index 
////        int emptyIndex = getNextCandidateIndex(index, i);
////        hashArray[emptyIndex].key = hashKey;
////        hashArray[emptyIndex].value = value;
////        hashArray[emptyIndex].status = 2;  // Mark as occupied
////        currVal++;
////
////        //  check loadfactor 
////        if ((double)currVal / capacity >= 0.75) {
////            doubleCapacity();
////        }
////    }
////
////    // func for deletion of key  
////    bool deleteKey(int const hashKey) {
////        int index = hashKey % capacity;
////        int i = 0;
////
////        while (i < capacity && hashArray[getNextCandidateIndex(index, i)].status != 0) {
////            int curr = getNextCandidateIndex(index, i);
////            if (hashArray[curr].status == 2 && hashArray[curr].key == hashKey) {
////                hashArray[curr].status = 1;  // Mark as deleted
////                return true;
////            }
////            i++;
////        }
////        return false;  
////    }
////
////    // func for getting value  
////    v* get(int const hashKey) const {
////        int index = hashKey % capacity;
////        int i = 0;
////
////    
////        while (i < capacity && hashArray[getNextCandidateIndex(index, i)].status != 0) {
////            int curr = getNextCandidateIndex(index, i);
////            if (hashArray[curr].status == 2 && hashArray[curr].key == hashKey) {
////                return &hashArray[curr].value; 
////            }
////            i++;
////        }
////        return nullptr;   
////    }
////
////    // Destructor  
////    virtual ~HashMap() {
////        delete[] hashArray;
////    }
////};
////
////// QHashMap Class  
////template <typename v>
////class QHashMap : public HashMap<v> {
////protected:
////    // Quadratic probing
////    int getNextCandidateIndex(int hashKey, int i) const override {  return (hashKey + i * i) % this->capacity;}
////
////public:
////    // Constructor with default capacity
////    QHashMap(int capacity = 10) : HashMap<v>(capacity) {}
////};
////
////// DHashMap Class  
////template <typename v>
////class DHashMap : public HashMap<v> {
////public:
////    // Constructor with default capacity
////    DHashMap(int capacity = 10) : HashMap<v>(capacity) {}
////
////protected:
////    // func for - Double hashing
////    int getNextCandidateIndex(int hashKey, int i) const override {
////        int prime = 7;  
////        int firstValue = hashKey % this->capacity;
////        int secondValue = prime - (hashKey % prime);
////        return (firstValue + i * secondValue) % this->capacity;   
////    }
////};
////
////// func to populate hash map from a file
////void populateHash(string fName, HashMap<string>* h) {
////    ifstream file(fName);  // Open the file for reading
////    if (!file.is_open()) {
////        cerr << "Following file has not opened: " << fName << endl;
////        return;
////    }
////
////    int id;
////    string name;
////    while (file >> id && getline(file, name)) {
////        if (!name.empty() && name[0] == ' ') name.erase(0, 1); 
////        h->insert(id, name);   
////    }
////
////    file.close();   
////}
////
////// Main func to test the hash maps
////int main() {
////    HashMap<string>* map;
////    cout << "Assignment 4 Q2" << endl << endl;
////    cout << "Names from the file:" << endl << endl;
////   
////    map = new HashMap<string>;
////    populateHash("file.txt", map);
////    string* name = map->get(9);
////    if (name) cout << *name << endl;
////    map->deleteKey(9);
////    assert(map->get(9) == nullptr);   
////    delete map; 
////    if (map->get(9)) cout << "Found";
//    else cout << "Not found" << endl;
//    
// 
//    map = new QHashMap<string>;
//    populateHash("file.txt", map);
//    name = map->get(98);
//    if (name) cout << *name << endl;
//    map->deleteKey(98);
//    assert(map->get(98) == nullptr); 
//    delete map;  
//
//    
//    map = new DHashMap<string>;
//    populateHash("file.txt", map);
//    name = map->get(101);
//    if (name) cout << *name << endl;
//    map->deleteKey(101);
//    assert(map->get(101) == nullptr);   
//    delete map;  
//
//    return 0;
//}
