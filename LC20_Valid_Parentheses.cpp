/**
 * @file LC20_Valid_Parentheses.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 1.3
 * @date 2023-08-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s){
        if (c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        else{
            if (st.empty() ||
                (st.top() == '(' && c != ')') || 
                (st.top() == '{' && c != '}') ||
                (st.top() == '[' && c != ']'))
            {
                return false;
            }
            st.pop();
        }
    }
    // if stack is empty, then paranteses are valid
    return st.empty();
}


int main(){
    string s1 = "()"; // true
    string s2 = "()[]{}"; // true
    string s3 = "]"; // false
    string s4 = "(])"; // false

    cout << isValid(s1) << endl;
    cout << isValid(s2) << endl;
    cout << isValid(s3) << endl;
    cout << isValid(s4) << endl;
}
