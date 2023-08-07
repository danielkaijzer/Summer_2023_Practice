/**
 * @file LC622_Design_Circular_Queue.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.2
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
    int item_count_;

public:
    // Constructor
    MyCircularQueue(int capacity) {
        capacity_ = capacity;
        data_ = new int[capacity_];
        front_ = -1; // see deQueue for reasoning behind this start value
        rear_ = -1;  // see enQueue for reasoning behind this start value
        item_count_ = 0;
    }

    // Destructor
    ~MyCircularQueue() {
        delete[] data_;
    }
    
    bool enQueue(int value) {
        if (isFull()){
            return false;
        }
        rear_ = (rear_+1)%capacity_;
        data_[rear_] = value;
        item_count_++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()){
            return false;
        }
        front_ = (front_+1) %capacity_;
        item_count_--;
        return true;
    }
    
    int Front() {
        return data_[front_];
    }
    
    int Rear() {
        return data_[rear_];
    }
    
    bool isEmpty() {
        return (item_count_ == 0);
    }
    
    bool isFull() {
        return (!isEmpty());
    }
};

int main(){

    MyCircularQueue myCircularQueue = new MyCircularQueue(3);
    cout << myCircularQueue.enQueue(1); // return True
    cout << myCircularQueue.enQueue(2); // return True
    cout << myCircularQueue.enQueue(3); // return True
    cout << myCircularQueue.enQueue(4); // return False
    cout << myCircularQueue.Rear();     // return 3
    cout << myCircularQueue.isFull();   // return True
    cout << myCircularQueue.deQueue();  // return True
    cout << myCircularQueue.enQueue(4); // return True
    cout << myCircularQueue.Rear();     // return 4
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