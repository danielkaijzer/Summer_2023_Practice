/**
 * @file LC106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.1
 * @date 2023-07-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <map>

/* REMEMBER:
    • Inorder: Left, Root, Right
    • Postorder: Left, Right, Root

So if INORDER = [9,3,15,20,7] and POSTORDER = [9,15,7,20,3]
    • We know immediately that 9 must be on left because: 
        - its first in both vectors
    • We know 3 is root because:
        - it was second in INORDER and it was last in POSTORDER
    • We know 15 is last left node down right tree because:
        - it was third in INORDER and second in POSTORDER

*/

/* PLAN:
    • Iterate through vectors and map position values to each value in vector


*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


// prints tree inorder
void inorderHelper(TreeNode* root){
    while (root == NULL){
        return;
    }

    inorderHelper(root->left);
    std::cout << root->val << std::endl;
    inorderHelper(root->right);
}

// Left, Root, Right
void inorderTraversal(TreeNode* root) {
    inorderHelper(root);
}

//left, root, right
// TreeNode* buildInOrder(std::vector<int> input, TreeNode* root){

// }

// left, right, root
// TreeNode* buildPostOrder(std::vector<int> input, TreeNode* root){

// }

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    //if vector empty, return nullptr
    if (inorder.empty()){
        return NULL;
    }

    TreeNode* inorder_Tree = new TreeNode(inorder.at(1));
    inorder.erase(inorder.begin()+1);

    for (int i = 0; i < inorder.size(); i++){
        std::cout << inorder.at(i) << std::endl;
    }
    
    // TreeNode* inOrder = buildInOrder(inorder, inorder_Tree);

    return inorder_Tree;
}


// Driver
int main(){

    std::vector<int> inorder = {9,3,15,20,7};
    std::vector<int> postorder = {9,15,7,20,3};

    TreeNode * tree1 = buildTree(inorder, postorder);
}