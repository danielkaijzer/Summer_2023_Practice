/**
 * @file LC652_FindDuplicateSubtrees.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode{

    int val;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    // CONSTRUCTORS
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void addNode(int x) {
        if (x < this->val){
            if (this->left == nullptr){
                this->left = std::make_unique<TreeNode>(x);
            }
            else{
                this->left->addNode(x);
            }
        }
        else{
            if (this->right == nullptr){
                this->right = std::make_unique<TreeNode>(x);
            }
            else{
                this->right->addNode(x);
            }
        }
        return;
    }

    void printTree(){

        if (this == nullptr){
            return;
        }

        std::cout << this->val << std::endl;
        left->printTree();
        right->printTree();
        // printTree(left.get());
        // printTree(right.get());
    }

};

// Driver
int main(){

    // Construct a binary tree
    // TreeNode tree = TreeNode(1);
    std::unique_ptr<TreeNode> tree = std::make_unique<TreeNode>(2);
    tree->left = std::make_unique<TreeNode>(2);
    tree->right = std::make_unique<TreeNode>(3);
    // tree->left->left = std::make_unique<TreeNode>(2);

    tree->printTree();

}