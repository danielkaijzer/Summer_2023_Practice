/**
 * @file LC200_Number_of_Islands
 * @author Daniel Kaijzer
 * 
 * @brief Given an m x n 2D binary grid grid 
 * which represents a map of '1's (land) and '0's (water), 
 * return the number of islands.
 * 
 * An island is surrounded by water
 * and is formed by connecting adjacent lands 
 * horizontally or vertically. 
 * You may assume all four edges of the grid are all 
 * surrounded by water.
 * 
 * @version 0.1
 * @date 2023-08-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// helper function to perform dfs
void dfs(vector<vector<char>>& grid, int i, int j){
    // check if we are out of bounds or if we have reached a 0
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1'){
        return;
    }

    // set the current cell to 0
    grid[i][j] = '0';

    // call dfs on the 4 adjacent cells
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);

}

int numIslands(vector<vector<char>>& grid) {
    int numIslands = 0;

    // loop through the grid
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){

            // if we find a 1, increment numIslands and call dfs
            if(grid[i][j] == '1'){
                numIslands++;
                dfs(grid, i, j);
            }
        }
    }

    return numIslands;
    
}

int main(){
    // initialize a 5x4 grid of chars using a vector of vectors
    vector<vector<char>> grid1 = {{'1','1','1','1','0'},
                                 {'1','1','0','1','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','0','0','0'}};

    vector<vector<char>> grid2 = {{'1','1','0','0','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','1','1'}};

    cout << numIslands(grid1) << endl;
    cout << numIslands(grid2) << endl;

}