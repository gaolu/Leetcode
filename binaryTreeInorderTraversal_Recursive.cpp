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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> treeNodes;
        if(root == NULL)
            return treeNodes;
        traversalNodes(root, treeNodes);
        return treeNodes;
    }

    void traversalNodes(TreeNode *root, vector<int> &treeNodes){
        if(root->left)
            traversalNodes(root->left, treeNodes);
        treeNodes.push_back(root->val);
        if(root->right)
            traversalNodes(root->right, treeNodes);
        return;
    }
};
