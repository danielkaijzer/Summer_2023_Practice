/**
 * @file LC739_Daily_Temperatures.cpp
 * @author Daniel Kaijzer
 * @brief Use stack to track indices
 * 
 * Every time there is a temp increase we update the stack value
 * 
 * We then update the days value at that index where we encounter increase
 * And update the value to the num of days, which is 
 * the difference between the current index and index val at top of stack
 * 
 * @version 1.1
 * @date 2023-08-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> s;
    s.push(0); // index of first temp
    vector<int> output(temperatures.size(),0); // init all vals to 0

    for (int i = 1; i < temperatures.size(); i++){

        while (!s.empty()){
            bool flag = false;

            // if temp at i is warmer than temp at top of stack
            if (temperatures[s.top()] < temperatures[i]){
                output[s.top()] = i-(s.top());
                s.pop();
                flag = true; // indicates we've encountered warmer temp
            }
            
            // if we have not yet encountered warmer temp,
            // then add current index at top of stack
            if (!flag || s.size() == 0){
                s.push(i);
                break; // breaks out of while loop
            }
        }
    }

    return output;
}


int main(){

    vector<int> temps = {73,74,75,71,69,72,76,73};

    vector<int> output = dailyTemperatures(temps);

    for (int i = 0; i < output.size(); i++){
        cout << output[i] << endl;
    }

}
