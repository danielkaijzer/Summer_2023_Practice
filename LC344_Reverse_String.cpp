/**
 * @file LC344_Reverse_String.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

void reverseString(vector<char>& s) {

    stack<char> stk;

    // add chars to stack
    for (auto c : s){
        stk.push(c);
    }

    for (auto c : s){
        c = stk.top();
        stk.pop();
    }
}

int main(){

    vector<char> s1 = {'h','e', 'l', 'l', 'o'};

    // reverseString(s1);

    for (auto c : s1){
        cout << c;
    }
    cout << endl;

}
