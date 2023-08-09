/**
 * @file LC752_Open_the_Lock.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.3
 * @date 2023-08-09
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
    
    // if target is start point
    if (target == start) return 0;

    // initialize hash set for visited configs, include deadends
    unordered_set<string> visited(begin(deadends), end(deadends));

    // if start is a deadend
    if (visited.count(start)) return -1;

    // initialize queue object
    queue<string> q(deque<string> {start});

    string main, cur, prev;

    int size = q.size();
    int level =1;


    // BFS

    while (!q.empty()){

        main = cur = prev = q.front(); 
        q.pop();

        for (int i =0; i<4;i++){
            if (cur[i] == '9'){
                cur[i] += -9;
            }
            else{
                cur[i] += 1;
            }
            if (cur == target) return level;
            if (!visited.count(cur)){
                q.push(cur);
                visited.insert(cur);
            }


            if (prev[i] == '0'){
                prev[i] -= -9;
            }
            else{
                prev[i] -= 1;
            }
            if (prev == target) return level;
            if (!visited.count(prev)){
                q.push(prev);
                visited.insert(prev);
            }

            cur = prev = main;
        }
    
        size--;
        level++;
    }




    return -1; // if target not found
    
}

int main(){
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";

    cout << openLock(deadends, target) << endl;

}