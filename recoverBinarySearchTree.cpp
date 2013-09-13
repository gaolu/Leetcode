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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // O(n) push nodes into list and find two mis-positioned nodes then swap their values
        // O(1) uses two nodes to store the mis-positioned nodes and then do the swap
        TreeNode *pre = new TreeNode(INT_MIN);
        TreeNode *big, *small;
        bool first = true;
        helper(root, pre, big, small, first);
        int temp = big->val;
        big->val = small->val;
        small->val = temp;
    }
    
    void helper(TreeNode *root, TreeNode *&pre, TreeNode *&big, TreeNode *&small, bool &first){
        if(root){
            helper(root->left, pre, big, small, first);
            if(pre->val > root->val && first){
                big = pre;
                first = false;
            }
            if(pre->val > root->val){
                small = root;
            }
            pre = root;
            helper(root->right, pre, big, small, first);
        }
    }
};
