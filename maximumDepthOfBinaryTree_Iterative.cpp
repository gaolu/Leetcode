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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return 0;
        stack<TreeNode *> s;
        TreeNode *pre = NULL;
        int maxHeight = 0;
        s.push(root);
        while(!s.empty()){
            TreeNode *curr = s.top();
            if(!pre || pre->left == curr || pre->right == curr){
                if(curr->left) s.push(curr->left);
                else if(curr->right) s.push(curr->right);
            }
            else if(curr->left == pre){
                if(curr->right) s.push(curr->right);
            }
            else s.pop();
            
            pre = curr;
            //maxHeight = max(maxHeight, s.size());
            if(s.size() > maxHeight)
                maxHeight = s.size();
        }
        return maxHeight;
    }
};
