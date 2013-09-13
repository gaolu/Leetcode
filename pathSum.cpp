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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return false;
        if(!root->left && !root->right && root->val == sum)
            return true;
        else
            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
