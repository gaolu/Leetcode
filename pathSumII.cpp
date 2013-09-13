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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> pathes;
        if(!root) return pathes;
        vector<int> path;
        helper(root, sum, pathes, path);
        return pathes;
    }
    
    void helper(TreeNode *root, int sum, vector<vector<int>> &pathes, vector<int> &path){
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right && root->val == sum){
            pathes.push_back(path);
            path.pop_back();
            return;
        }
        if(root->left) helper(root->left, sum - root->val, pathes, path);
        if(root->right) helper(root->right, sum - root->val, pathes, path);
        path.pop_back();
        return;
    }
};
