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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return 0;
        return helper(root, false);
    }
    
    int helper(TreeNode *root, bool hasSibling){
        if(!root) return hasSibling ? INT_MAX : 0;
        int leftHeight = helper(root->left, root->right != NULL);
        int rightHeight = helper(root->right, root->left != NULL);
        return 1 + min(leftHeight, rightHeight);
    }
};
