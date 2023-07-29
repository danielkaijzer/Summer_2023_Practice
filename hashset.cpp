#include <iostream>
#include <vector>

class MyHashSet {
    private:
    std::vector<std::vector<int>> bucket;
    int hash_value = 3;
        
    public:
        // Constructor
        MyHashSet() {
            bucket = std::vector<std::vector<int>>(hash_value, std::vector<int>());
        }
        
        // Insert key value into hash set
        void add(int key) {
            // If key doesn't already exist in bucket
            if (!contains(key)){
                bucket[key%3].push_back(key);
            }
        }

        // Remove a value in the HashSet if it exists
        void remove(int key) {
            // go into row of bucket. Row = key % hash_value
            int row = key % hash_value;
            for (int col = 0; col < bucket.at(row).size(); col++){
                if (bucket.at(row).at(col) == key){
                    // replace value at current index with last column value and pop last column
                    int last_column = bucket.at(row).size() -1;
                    bucket.at(row).at(col) = bucket.at(row).at(last_column);
                    bucket.at(row).pop_back();
                }
            }
        }
        
        // Return whether the value exists in HashSet or not
        bool contains(int key) {
            // go into row of bucket. Row = key % hash_value
            int row = key % hash_value;
            for (int col = 0; col < bucket.at(row).size(); col++){
                if (bucket.at(row).at(col) == key){
                    return true;
                }
            }
            return false;
            
        }


        void print(){
            for (int i = 0; i < bucket.size(); i++){
                std::cout << "Bucket " << i << ": ";
                for (int j = 0; j < bucket.at(i).size(); j++){
                    if (j >= bucket.at(i).size()) {
                        throw std::out_of_range("Index out of range");
                    }
                    std::cout << bucket.at(i).at(j) << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(){
    MyHashSet v1 = MyHashSet();

    v1.add(1);
    v1.add(2);
    v1.add(3);
    v1.add(4);

    if(v1.contains(1)){
        std::cout << "Contains 1\n\n";
    }
    else{
        std::cout << "Does not contain 1\n\n";
    }

    // print elements
    try {
        v1.print();
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }

    v1.remove(1);
    if(v1.contains(1)){
        std::cout << "Contains 1\n\n";
    }
    else{
        std::cout << "Does not contain 1\n\n";
    }

    // print elements
    try {
        v1.print();
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }


    return 0;
}
