/**
 * LC102 Binary Tree Level Order Traversal
 * @author Daniel Kaijzer
 * 
 * @brief We use a queue because it will for every level
 * @version 0.1
 * @date 2023-07-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <queue>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// std::vector<std::vector<int>> output;


// Track levels and add elements at a certain level to appropriate vector 
//within vector of vectors
// Each 1D vector within 2D vector will represent a level in the tree

// Preorder traversal helper function
void depthFirstSearch(TreeNode* root){
    
    if (root == NULL){
        return;
    }

    // output.push_back(root->val);
    depthFirstSearch(root->left);
    depthFirstSearch(root->right);
}

std::vector<std::vector<int>> levelOrder(TreeNode* root) {

    std::vector<std::vector<int>> output;
    if(root==nullptr){
        return output;
    }
    
    std::queue<TreeNode*> level_queue; // queue stores nodes from tree
    level_queue.push(root);

    while(!level_queue.empty()){
        
        int n = level_queue.size();
        std::vector<int> temp(n,0); // initialize a vector

        // iterate through queue at level to store values 
        // at that level in current temp vector
        for (int i = 0; i < n; i++){

            auto curr=level_queue.front();

            if(curr->left){ //if value on left, add to queue
                level_queue.push(curr->left);
            }
            if(curr->right){ // if value right, add to queue
                level_queue.push(curr->right);
            }

            temp[i]=curr->val;
            level_queue.pop();
        }

        output.push_back(temp); // at every level we push a new vector to output
    }

    return output;

}


// Driver
int main(){

    // Test tree
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);

    std::vector<std::vector<int>> values = levelOrder(root);

    // std::cout << values.at(0).at(0) << std::endl;

    for (int i = 0; i < values.size(); i++){ // iterate through 2D vector
        // iterate through 1D vector
        for (int j = 0; j < values.at(i).size(); j++){
            std::cout << values.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}