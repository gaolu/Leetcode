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
        queue<TreeNode *> lf, rt;
        TreeNode *l, *r;
        lf.push(root->left);
        rt.push(root->right);
        while(!lf.empty() && !rt.empty()){
            l = lf.front();
            r = rt.front();
            lf.pop();
            rt.pop();
            // reach leaves
            if(l == NULL && r == NULL)
                continue;
            if(l == NULL || r == NULL)
                return false;
            if(l->val != r->val)
                return false;
            lf.push(l->left);
            lf.push(l->right);
            rt.push(r->right);
            rt.push(r->left);
        }
        if(lf.empty() && rt.empty())
            return true;
        else
            return false;
    }
};