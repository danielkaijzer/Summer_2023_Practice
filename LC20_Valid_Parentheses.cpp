/**
 * @file LC20_Valid_Parentheses.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
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

    for (int i =0; i < s.size()/2 -1; i++){
        // st.push(s[i]);
        cout << s[i] << endl;
    }

    for (int i = s.size()/2-1; i < s.size()-1;i++){
        // if (st.top() == '(' && s[i] == ')'){
        //     st.pop();
        // }
        // else if (st.top() == '{' && s[i] == '}'){
        //     st.pop();
        // }
        // else if (st.top() == '[' && s[i] == ']'){
        //     st.pop();
        // }

        cout << s[i] << endl;
    }

    if (st.empty()){
        return true;
    }
    // else return false
    return false;
}


int main(){
    string s = "()";

    isValid(s);
}
