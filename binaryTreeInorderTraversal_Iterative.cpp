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
        stack<TreeNode*> s;
        vector<int> treeNodes;
        if(root == NULL)
            return treeNodes;
        TreeNode *current = root;
        bool isVisited = false;
        while(!s.empty() || current){
            if(current){
                if(current->left && !isVisited){
                    s.push(current); // 24
                    current = current->left;
                }
                else{
                    treeNodes.push_back(current->val);
                    current = current->right;
                }
                isVisited = false;
            }
            else{
                current = s.top();
                s.pop();
                isVisited = true;
            }
        }
        return treeNodes;
    }
};
