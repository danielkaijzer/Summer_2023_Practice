/**
 * @file 155_Min_Stack.cpp
 * @author Daniel Kaijzer
 * @brief Use pairs to store top value in first field 
 * and current minimum value 
 * within stack in second field (at the top of stack)
 * 
 * @version 1
 * @date 2023-08-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class MinStack {

private:
    vector<pair<int,int>> data;
    int top_;
    int min_;

public:

    // initialize stack object
    MinStack() {
    }
    
    void push(int val) {
        pair<int,int> cur;

        if (data.empty()){
            cur.first = val;
            cur.second = val;
            data.push_back(cur);
        }
        else{
            cur.first = val;
            cur.second = min(val,data.back().second); 
            data.push_back(cur);
        }
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        return data.back().first; // returns value at top of stack
    }
    
    int getMin() {
        return data.back().second; // returns min value within stack
    }
};

int main(){
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl; // return -3
    minStack->pop();
    cout <<minStack->top()<< endl;    // return 0
    cout <<minStack->getMin()<< endl; // return -2
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */