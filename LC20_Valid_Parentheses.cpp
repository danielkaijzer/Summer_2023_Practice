/**
 * @file LC20_Valid_Parentheses.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.2
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

    int index = 0;

    for (char c : s){
        if (index < s.size()/2){
            cout << "A" << c << endl;
            st.push(c);
        }

        else if (!st.empty()){
            if (st.top() == '(' && c == ')'){
                st.pop();
                cout << "B" << c << endl;
            }
            else if (st.top() == '{' && c == '}'){
                st.pop();
                cout << "C" << c << endl;
            }
            else if (st.top() == '[' && c == ']'){
                st.pop();
                cout << "D" <<c << endl;
            }  
        }
        index++;
    }

    if (st.empty()){
        return true;
    }
    // else return false
    return false;
}


int main(){
    string s1 = "()";
    string s2 = "()[]{}";

    // cout << isValid(s1) << endl;
    cout << isValid(s2) << endl;
}
