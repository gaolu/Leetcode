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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode *lf, TreeNode *rt){
        if(lf == NULL && rt == NULL) return true;
        if(lf == NULL || rt == NULL) return false;
        if(lf->val != rt->val) return false;
        return helper(lf->left, rt->right) && helper(lf->right, rt->left);
    }
};