/**
 * @file LC20_Valid_Parentheses.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 1.1
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
        else if (c == ')' || c == '}' || c == ']'){
            if(st.empty()){
                return false;
            }
            else if (st.top() == '(' && c == ')'){
                st.pop();
            }
            else if (st.top() == '{' && c == '}'){
                st.pop();
            }
            else if (st.top() == '[' && c == ']'){
                st.pop();
            }  
            else{
                return false;
            }
        }
    }

    // if stack is empty, then paranteses are valid
    if (st.empty()){
        return true;
    }
    // else return false
    return false;
}


int main(){
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "]";
    string s4 = "(])";
    

    cout << isValid(s1) << endl << endl;
    cout << isValid(s2) << endl << endl;
    cout << isValid(s3) << endl;
}
