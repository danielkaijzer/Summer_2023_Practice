/**
 * @file LC94_Inorder_Traversal.cpp
 * @author Daniel Kaijzer
 * 
 * @brief Left, root, right
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

void inorderHelper(TreeNode* root){
    while (root == NULL){
        return;
    }

    inorderHelper(root->left);
    output.push_back(root->val);
    inorderHelper(root->right);
}

// Left, Root, Right
std::vector<int> inorderTraversal(TreeNode* root) {
    inorderHelper(root);
    return output;
}

// Driver
int main(){

    // Task 1: Construct a tree for testing
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);

    TreeNode * cur = root;

    std::vector<int> values = inorderTraversal(root);

    for (int i = 0; i < values.size(); ++i){
        std::cout << values.at(i) << std::endl;
    }

    // for (auto itr = values.begin(); itr != values.end(); ++itr){
    //     std::cout << itr << std::endl;
    // }

     

}