/**
 * @file LC144_Preorder_Traversal.cpp
 * @author Daniel Kaijzer
 * 
 * @brief 
 * @version 0.1
 * @date 2023-07-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

std::vector<int> output;

// Root, left, right
void depthFirstSearch(TreeNode* root){
    if (root == NULL){
        return;
    }

    output.push_back(root->val);
    depthFirstSearch(root->left);
    depthFirstSearch(root->right);
}

std::vector<int> preorderTraversal(TreeNode* root) {
    depthFirstSearch(root);
    return output;
}


// Driver
int main(){

    // Task 1: Construct a tree for testing
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);

    TreeNode * cur = root;

    std::vector<int> values = preorderTraversal(root);

    for (int i = 0; i < values.size(); ++i){
        std::cout << values.at(i) << std::endl;
    }

    // for (auto itr = values.begin(); itr != values.end(); ++itr){
    //     std::cout << itr << std::endl;
    // }

     

}