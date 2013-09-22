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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return 0;
        int currentSum;
        int maxSum = INT_MIN;
        helper(root, currentSum, maxSum);
        return maxSum;
    }
    
    void helper(TreeNode *root, int &currentSum, int &maxSum){
        if(!root){
            currentSum = 0;
            return;
        }
        int leftSum, rightSum;
        helper(root->left, leftSum, maxSum);
        helper(root->right, rightSum, maxSum);
        currentSum = max(root->val, max(root->val + leftSum, root->val + rightSum));
        // we have already considered the situation where only one node in the path
        // as we update maxSum evern for the leaf nodes
        maxSum = max(maxSum, max(currentSum, root->val + leftSum + rightSum));
    }
};
