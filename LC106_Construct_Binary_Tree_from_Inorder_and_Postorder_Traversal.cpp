/**
 * @file LC106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp
 * @author Daniel Kaijzer
 * @brief 
 * @version 0.2
 * @date 2023-07-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

/* REMEMBER:
    • Inorder: Left, Root, Right
    • Postorder: Left, Right, Root

So if INORDER = [9,3,15,20,7] and POSTORDER = [9,15,7,20,3]
    • We know immediately that 9 must be on left because: 
        - its first in both vectors
    • We know 3 is root because:
        - it was last in POSTORDER
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

// prints tree inorder: LEFT, ROOT, RIGHT
void inorderHelper(TreeNode* root){
    while (root == NULL){
        return;
    }

    inorderHelper(root->left);
    std::cout << root->val << std::endl;
    inorderHelper(root->right);
}
void inorderTraversal(TreeNode* root) {
    inorderHelper(root);
}


TreeNode* buildTreeHelper(std::vector<int>& postorder,int postorder_start, int postorder_end,std::vector<int>& inorder, int inorder_start, int inorder_end, std::unordered_map<int,int> &mp){
    // Base case
    if (inorder_start > inorder_end || postorder_start > postorder_end){
        return NULL;
    }

    // Add Node
    TreeNode* node = new TreeNode(postorder[postorder_end]);

    // root is last in postorder, so we store index of root
    int root_index = mp[postorder[postorder_end]];
    int remaining_values = root_index - inorder_start;

    // recursive calls
    node->left = buildTreeHelper(
                                postorder, postorder_start,
                                postorder_start+remaining_values-1,
                                inorder,
                                inorder_start, root_index-1,
                                mp
                                );
    node->right = buildTreeHelper(
                                postorder, postorder_start+remaining_values,
                                postorder_end-1,
                                inorder,
                                root_index+1, inorder_end,
                                mp
                                );          
    return node;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    //if vector empty, return nullptr
    // if (inorder.empty() || postorder.empty()){
    //     return NULL;
    // }
    // // if input vectors don't match
    // if (inorder.size() != postorder.size()){
    //     return NULL;
    // }
    std::unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++){
        mp[inorder[i]] = i;
    }
    return buildTreeHelper(postorder, 0, postorder.size()-1,inorder, 0, inorder.size()-1,mp);
}


// Driver
int main(){

    std::vector<int> inorder = {9,3,15,20,7};
    std::vector<int> postorder = {9,15,7,20,3};

    TreeNode * tree1 = buildTree(inorder, postorder);
}