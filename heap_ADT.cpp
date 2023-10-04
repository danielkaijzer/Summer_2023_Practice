/**
 * @file heap_ADT.cpp
 * @author Daniel Kaijzer
 * @brief implements a heap using an array
 * @version 0.1
 * @date 2023-08-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>


using namespace std;

class maxHeap{
    private:
        vector<int> data;

    public:
        maxHeap(){

        }

        maxHeap(int root){
            cout << data.size() << endl;
            data.resize(data.size() + 2);
            data.at(1) = root;
            cout << root << endl;
        }

        void insert(int val){
            data.resize(data.size() + 1);
            
            if (val <= data.front()){
                
            }

        }

};




int main(){
    maxHeap test = maxHeap(5);
}
