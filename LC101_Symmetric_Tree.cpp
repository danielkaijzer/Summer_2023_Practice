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

// Bottom-Up "post-order" method to calculate maxDepth
int maxDepth(TreeNode* root){
    if (!root){
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return std::max(leftDepth, rightDepth) +1;
}

bool isSymmetricHelper(TreeNode* left, TreeNode*right){
    if (!left && !right){ // if we made it to leaf
        return true;
    }
    if(!left && right){
        return false;
    }
    if (left && !right){
        return false;
    }

    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);

    return (left->val == right->val);

    // return (left->val == right->val) && isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);

}

bool isSymmetric(TreeNode* root){
    // Left val = right val
    return isSymmetricHelper(root->left, root->right);
}

// Driver
int main(){

    // Test tree
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(9);
    root->right->right = new TreeNode(7);
    root->left->left = new TreeNode(5);

    int x = maxDepth(root);

    if (isSymmetric(root)){
        std::cout << "Tree is symmetric\n";
    }
    else{
        std::cout << "Tree is not symmetric\n";
    }

    // std::cout << x << std::endl;



    // for (int i = 0; i < values.size(); i++){ // iterate through 2D vector
    //     // iterate through 1D vector
    //     for (int j = 0; j < values.at(i).size(); j++){
    //         std::cout << values.at(i).at(j) << " ";
    //     }
    //     std::cout << std::endl;
    // }
}