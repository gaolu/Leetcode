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
        int num = 0, sum = 0;
        helper(root, num, sum);
        return sum;
    }
    
    void helper(TreeNode *root, int &num, int &sum){
        if(!root) return;
        num = num * 10 + root->val;
        // reach leaf
        if(!root->left && !root->right) sum += num;
        else{
            helper(root->left, num, sum);
            helper(root->right, num, sum);
        }
        // return back to upper node
        num /= 10;
    }
};
