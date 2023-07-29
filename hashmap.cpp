#include <iostream>
#include <vector>
#include <list>

class MyHashMap {
private:
    std::vector<std::list<int>> hashmap;
    int hash_value = 3;
    
public:

    // Constructor
    // initializes the object with an empty map
    MyHashMap() {
        hashmap = std::vector<std::list<int>>(hash_value);
    }

    // inserts a (key, value) pair
    // into the HashMap
    // If the key already exists
    // update corresponding value
    void put(int key, int value) {
        // check if key already exists
        hashmap[key%hash_value].push_back(value);
    }
    
    // returns the value 
    // to which the specified key is mapped
    // or -1 if this map contains
    // no mapping for the key
    int get(int key) {
        if (hashmap[key%hash_value].empty())
            return -1;
        else{
            return (hashmap[key%hash_value].back());
        }
    }
    
    // removes the key and its corresponding value
    // if the map contains the mapping for the key 
    void remove(int key) {
        if (hashmap[key%hash_value].empty())
            return;
        else{
            hashmap[key%hash_value].clear();
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(){

    MyHashMap map1 = MyHashMap();
    map1.put(1, 1);
    map1.put(2, 2);
    
    std::cout << map1.get(1) << std::endl; // returns 1
    std::cout << map1.get(3) << std::endl; // returns -1 (not found)

    map1.put(2, 4); // update the existing value
    std::cout << map1.get(2) << std::endl; // returns 1
    map1.remove(2); // remove the mapping for 2
    std::cout << map1.get(2) << std::endl; // returns -1 (not found)

    return 0;

}
