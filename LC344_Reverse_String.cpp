/**
 * @file LC344_Reverse_String.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <stack>

// blah


using namespace std;

void reverseString(vector<char>& s) {

    for (int i = 0; i < (s.size()/2); ++i){
        swap(s[i],s[s.size()-1-i]);
    }
}

int main(){

    vector<char> s1 = {'h','e', 'l', 'l', 'o', 'q'};

    reverseString(s1);

    for (auto c : s1){
        cout << c;
    }
    cout << endl;

}
