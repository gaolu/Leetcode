/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return;
        TreeNode *leftChild = root->left;
        TreeNode *rightChild = root->right;
        if(leftChild){
            root->right = leftChild;
            root->left = NULL; // don't forget to delete left subtree
            TreeNode *rightMost = leftChild;
            while(rightMost->right)
                rightMost = rightMost->right;
            rightMost->right = rightChild;
        }
        flatten(root->right);
    }
};