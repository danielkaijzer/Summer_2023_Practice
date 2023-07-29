/**
 * @file hashmap_v2.cpp
 * @author Daniel Kaijzer
 * @brief Implements a hashmap/hashtable in C++ using 
 * vectors to implement an array of buckets 
 * and where each bucket contains a linked list of key-value pairs to resolve collisions
 * @version 0.2
 * @date 2023-06-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <list>
#include <utility>

class MyHashMap {
private:
    std::vector<std::list<std::pair<int,int>>> hashmap;
    int hash_value = 3;
    
public:

    // Constructor
    // initializes the object with an empty map
    MyHashMap() {
        hashmap = std::vector<std::list<std::pair<int,int>>>(hash_value);
    }

    int hashFunction(int key){
        return (key%hash_value);
    }

    // inserts a (key, value) pair
    // into the HashMap
    // If the key already exists
    // update corresponding value
    void put(int key, int value) {
        int index = hashFunction(key);

        // check if bucket empty
        if (!hashmap[index].empty()){ // if not empty
            // check if key input is already used
            // iterate through nodes at bucket and compare keys to input key
            // if the key matches, update the value there
            for (auto it = hashmap[index].begin(); it != hashmap[index].end(); ++it){
                if (it->first == key){
                    it->second = value;
                    return;
                }
            }
        }
        // if bucket empty or the input key is unique, add to back of linked list
        std::pair<int,int> new_pair(key,value); // doing this because push_back() can only take one argument
        hashmap[index].push_back(new_pair);
    }
    
    // returns the value 
    // to which the specified key is mapped
    // or -1 if this map contains
    // no mapping for the key
    int get(int key) {
        int index = hashFunction(key);

        if (hashmap[key%hash_value].empty())
            return -1;
        else{
            // check for key
            for (auto it = hashmap[index].begin(); it != hashmap[index].end(); ++it){
                if(it->first == key){ // if keys match
                    return it->second; // return value
                }
            }
            // if no key matches return -1
            return -1;
        }
    }
    
    // removes the key and its corresponding value
    // if the map contains the mapping for the key 
    void remove(int key) {
        int index = hashFunction(key);

        if (hashmap[index].empty())
            return;
        else{
            // check if keys match
            for (auto it = hashmap[index].begin(); it != hashmap[index].end(); ++it){
                if (it->first == key){
                    hashmap[index].erase(it);
                    return;
                }
            }

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

    map1.put(5, 6); // update the existing value
    std::cout << map1.get(2) << std::endl; // returns 1
    map1.remove(2); // remove the mapping for 2
    std::cout << map1.get(2) << std::endl; // returns -1 (not found)

    return 0;

}
