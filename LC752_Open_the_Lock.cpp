/**
 * @file LC752_Open_the_Lock.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.2
 * @date 2023-08-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int openLock(vector<string>& deadends, string target) {
    
    string start = "0000";
    unordered_set<string> visited;
    
    for (auto s : deadends){
        if (s == start){ // start point is in deadends, return -1
            return -1; 
        }
        // add deadends to visited
        visited.insert(s);
    }

    queue<string> q;
    int step = 0;

    q.push(start); // add start point to queue


    // BFS
    while (!q.empty()){

    }




    return -1; // if target not found
    
}

int main(){
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";

    cout << openLock(deadends, target);

}