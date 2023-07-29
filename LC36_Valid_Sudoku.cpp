/**
 * @file LC36_Valid_Sudoku.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-06-17
 * ki98
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::unordered_map<char, std::vector<std::pair<int,int>>> SudokuMap; // key: char, value: array of indices char appears at

    int row_index = 0; // initialize row index
    int col_index = 0; // initialize col index

    // check for repeated values in rows
    for (auto row : board){ // iterate through each row (which is a vector of chars)

        col_index = 0; // re-initialize column index for every row

        for (char c : row){ // iterate through each char in row

            if (SudokuMap.count(c) > 0){ // if current number has appeared before on Sudoku board

                // iterate through vector of indices, check if new char is valid addition to board
                for (auto itr = SudokuMap[c].begin(); itr != SudokuMap[c].end(); ++itr){
                    int row = itr->first;
                    int col = itr->second;

                    if (row == row_index){ // if value already exists in same row
                        std::cout << "Repeated value in row" << row_index << std::endl;
                        return false;
                    }
                    else if(col == col_index){ // if value already exists in same column
                        std::cout << "Repeated value in col" << row_index << std::endl;
                        return false;
                    }
                    else{ // Check if value exists in same 3x3 subgrid
                        if (row < 3 && row_index < 3){ // Top rows 0-2
                            if (col < 3 && col_index < 3){ // top left subgrid
                                std::cout << c << " at [" << row_index << "," << col_index << "] Subgrid 1 fails 3x3 check \n";
                                return false;
                            }
                            else if ((col > 2 && col < 6) && (col_index > 2 && col_index < 6)){ // top center
                                std::cout << c << " at [" << row_index << "," << col_index << "] Subgrid 2 fails 3x3 check \n";
                                return false;
                            }
                            else if (col > 5 && col_index > 5){ // top right
                                std::cout << c << " at [" << row_index << "," << col_index << "] Subgrid 3 fails 3x3 check \n";
                                return false;
                            }
                        }
                        else if ((row > 2 && row < 6) && (row_index > 2 && row_index < 6)){ // Center rows 3-5
                            if (col < 3 && col_index < 3){ // center left subgrid
                                std::cout << c << " at [" << row_index << "," << col_index << "] Subgrid 4 fails 3x3 check \n";
                                return false;
                            }
                            else if ((col > 2 && col < 6) && (col_index > 2 && col_index < 6)){ // center
                                std::cout << c << " at [" << row_index << "," << col_index << "] Subgrid 5 fails 3x3 check \n";
                                return false;
                            }
                            else if (col > 5 && col_index > 5){ // middle right
                                std::cout << c << " at [" << row_index << "," << col_index << "] Subgrid 6 fails 3x3 check \n";
                                return false;
                            }
                        }
                        else if (row > 5 && row_index > 5){ // Bottom rows 6-8
                            if (col < 3 && col_index < 3){ // bottom left subgrid
                                std::cout << c << " at [" << row_index << "," << col_index << "] Subgrid 7 fails 3x3 check \n";
                                return false;
                            }
                            else if ((col > 2 && col < 6) && (col_index > 2 && col_index < 6)){ // bottom center
                                std::cout << c << " at [" << row_index << "," << col_index << "] Subgrid 8 fails 3x3 check \n";
                                return false;
                            }
                            else if (col > 5 && col_index > 5){ // bottom right
                                std::cout << c << " at [" << row_index << "," << col_index << "] Subgrid 9 fails 3x3 check \n";
                                return false;
                            }
                        }
                    }

                }
            }

            // If current number is a valid entry to Sudoku board, 
            if (c <= '9' && c >= '0'){
                // add indices to array of indices mapped to that value
                SudokuMap[c].push_back(std::make_pair(row_index,col_index));
            }

            col_index++; // iterate column index
        }
        row_index++; // iterate row index
    }
    
    return true;
}

// Driver
int main(){

    std::vector<std::vector<char>> board_1 = {
    {'8', '3', '.', '.', '7', '.', '.', '.', '.'}, // row 0
    {'.', '.', '.', '1', '9', '5', '.', '.', '.'}, // row 1
    {'.', '9', '.', '.', '.', '.', '.', '6', '.'}, // row 2
    {'.', '.', '.', '.', '6', '.', '.', '.', '3'}, // row 3
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, // row 4
    {'7', '.', '.', '.', '2', '.', '6', '.', '.'}, // row 5
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, // row 6
    {'6', '.', '.', '4', '1', '9', '.', '.', '5'}, // row 7
    {'6', '.', '.', '.', '8', '.', '.','7', '9'}  // row 8
    };


    if (isValidSudoku(board_1)){
        std::cout << "True\n";
    }
    else{
        std::cout << "False\n";
    }

    return 0;
}