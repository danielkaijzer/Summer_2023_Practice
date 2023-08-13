/**
 * @file 155_Min_Stack.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.2
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
    int min_;
    int prev_min_;

public:

    // initialize stack object
    MinStack() {
    }
    
    void push(int val) {
        if (data.empty()){
            data.push_back(val);
        }
        data.push_back(val);
        top_ = data[data.size()-1];
        prev_min_ = min_;
        min_ = min(top_,min_);
        
    }
    
    void pop() {

        if (!data.empty()){
            if (min_ == top_){
                min_ = prev_min_;
            }
            data.pop_back();
            top_ = data[data.size()-1];
        }

    }
    
    int top() {
        if (!data.empty()){
            return top_;
        }
    }
    
    int getMin() {
        return min_;
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