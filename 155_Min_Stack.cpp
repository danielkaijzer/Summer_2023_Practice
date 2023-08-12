/**
 * @file 155_Min_Stack.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-08-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class MinStack {

private:
    vector<int> data;
    int top_;
    int capacity_;
    int item_count_;

public:

    // initialize stack object
    MinStack() {

        
    }
    
    void push(int val) {
        
    }
    
    void pop() {
        
    }
    
    int top() {
        return top_;
    }
    
    int getMin() {
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */