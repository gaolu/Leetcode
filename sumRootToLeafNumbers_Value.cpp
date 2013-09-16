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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num = 0;
        return helper(root, num);
    }
    
    int helper(TreeNode *root, int num){
        if(!root) return 0;
        num = num * 10 + root->val;
        // reach leaf
        if(!root->left && !root->right) return num;
        else{
            return helper(root->left, num) + helper(root->right, num);
        }
    }
};
