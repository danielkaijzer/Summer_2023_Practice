/**
 * Binary_Tree_MaxDepth.cpp
 * @author Daniel Kaijzer
 * 
 * @brief caclulates max depth of binary tree
 * @version 0.1
 * @date 2023-07-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <algorithm>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int answer = 0;

// Top-Down "pre-orderish" method to calculate maxDepth
void maxDepthHelper(TreeNode* root, int depth){
    if (!root){
        return;
    }

    // if leaf
    if (!root->left && !root->right){
        answer = std::max(answer, depth);
    }
    maxDepthHelper(root->left, depth+1);
    maxDepthHelper(root->right, depth+1);
}

int maxDepth(TreeNode* root, int depth){
    maxDepthHelper(root, depth);
    return answer;
}


// Driver
int main(){

    // Test tree
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);

    int x = maxDepth(root, 1);

    std::cout << x << std::endl;
}