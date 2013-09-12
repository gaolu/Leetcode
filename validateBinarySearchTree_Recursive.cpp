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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValidBSTRecursive(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBSTRecursive(TreeNode *root, int low, int high){
        if(!root)
            return true; // reach leaves
        if(low < root->val && root->val < high)
            return isValidBSTRecursive(root->left, low, root->val) && isValidBSTRecursive(root->right, root->val, high);
        else
            return false;
    }
};
