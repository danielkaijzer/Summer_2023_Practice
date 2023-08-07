/**
 * @file LC622_Design_Circular_Queue.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-08-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

using namespace std;

class MyCircularQueue {

private:
    int * data_; 
    int front_;
    int rear_;
    int capacity_;

public:
    // Constructor
    MyCircularQueue(int capacity) {
        capacity_ = capacity;
        data_ = new int[capacity_];
        front_ = -1;
        rear_ = -1;
    }

    // Destructor
    ~MyCircularQueue() {
        delete[] data_;
    }
    
    bool enQueue(int value) {
        return false;
    }
    
    bool deQueue() {
        return false;
    }
    
    int Front() {
        return -1;
    }
    
    int Rear() {
        return -1;
    }
    
    bool isEmpty() {
        return false;
    }
    
    bool isFull() {
        return false;
    }
};

int main(){
    int k = 1;
    int value = 1;

    MyCircularQueue* obj = new MyCircularQueue(k);
    bool param_1 = obj->enQueue(value);
    bool param_2 = obj->deQueue();
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */