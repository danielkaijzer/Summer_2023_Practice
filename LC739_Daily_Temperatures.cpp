/**
 * @file LC739_Daily_Temperatures.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.3
 * @date 2023-08-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> output;

    // add all elements to hashmap
    for (int i = 0; i < temperatures.size(); i++){
        // find num of days until higher temp
        int j = i;
        while (temperatures[i] >= temperatures[j] && j < temperatures.size()-1){
            j++;
        }
        if (temperatures[j] > temperatures[i]){
            int num_days = j-i;
            output.push_back(num_days);
        }
        else{
            output.push_back(0);
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
