/**
 * LC112_Path_Sum.cpp
 * @author Daniel Kaijzer
 * 
 * @brief Given root node and targetSum, 
 * return true if tree has path 
 * s.t. sum of node vals on that path == targetSum
 * @version 0.1
 * @date 2023-07-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
// #include <algorithm>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

bool pathSum(TreeNode* root, int temp_sum, int targetSum){
    if (!root){
        return 0;
    }

    temp_sum += root->val;

    if (!root->left && !root->right){ // if leaf, check pathSum
        // std::cout << temp_sum << " Check\n";
        return (temp_sum == targetSum);
    }

    return pathSum(root->left, temp_sum, targetSum) || 
    pathSum(root->right, temp_sum, targetSum);
}

bool hasPathSum(TreeNode* root, int targetSum){
    if (!root){ // if there is no root node, return false
        return false;
    }

    return pathSum(root, 0, targetSum);
}

// Driver
int main(){

    // Test tree
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);

    int target = 1;

    if (hasPathSum(root, target)){
        std::cout << "True\n";
    }
    else{
        std::cout << "False\n";
    }

}