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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(preorder.size() != inorder.size()) return NULL;
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode *helper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd){
        TreeNode *root;
        if(preStart > preEnd) return NULL;
        root = new TreeNode(preorder[preStart]);
        int newRoot = inStart - 1;
        while(++newRoot <= inEnd && inorder[newRoot] != preorder[preStart]){
            ;
        }
        int leftSize = newRoot - inStart;
        root->left = helper(preorder, preStart + 1, preStart + leftSize, inorder, inStart, newRoot - 1);
        root->right = helper(preorder, preStart + leftSize + 1, preEnd, inorder, newRoot + 1, inEnd);
        return root;
    }
};
