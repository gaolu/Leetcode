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
        int prev = INT_MIN;
        return isValidBSTHelper(root, prev);
    }
    
    bool isValidBSTHelper(TreeNode *root, int &prev){
        if(!root)
            return true;
        if(isValidBSTHelper(root->left, prev)){
            // root value must be bigger than the left child node value
            if(root->val > prev){
                prev = root->val;
                return isValidBSTHelper(root->right, prev);
            }
            else
                return false;
        }
        else
            return false;
    }
};
