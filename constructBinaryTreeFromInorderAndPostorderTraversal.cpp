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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.size() != postorder.size()) return NULL;
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode *helper(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd){
        if(inStart > inEnd) return NULL;
        if(postStart > postEnd) return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int newRoot = inStart - 1;
        while(++newRoot <= inEnd && inorder[newRoot] != postorder[postEnd]){
            ;
        }
        int leftSize = newRoot - inStart;
        int rightSize = inEnd - newRoot;
        root->left = helper(inorder, inStart, newRoot - 1, postorder, postStart, postStart + leftSize - 1);
        root->right = helper(inorder, newRoot + 1, inEnd, postorder, postEnd - rightSize, postEnd - 1);
        return root;
    }
};
