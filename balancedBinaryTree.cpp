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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        int leftSubHeight = getHeight(root->left);
        int rightSubHeight = getHeight(root->right);
        if(abs(leftSubHeight - rightSubHeight) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getHeight(TreeNode *root){
        if(!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};
