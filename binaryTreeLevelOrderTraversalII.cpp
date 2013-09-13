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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> levelNodes;
        if(!root) return levelNodes;
        queue<TreeNode*> q;
        q.push(root);
        int nodesInCurrentLevel = 1;
        int nodesInNextLevel = 0;
        vector<int> temp;
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            temp.push_back(p->val);
            --nodesInCurrentLevel;
            
            if(p->left){
                q.push(p->left);
                ++nodesInNextLevel;
            }
            if(p->right){
                q.push(p->right);
                ++nodesInNextLevel;
            }
            if(nodesInCurrentLevel == 0){
                levelNodes.push_back(temp);
                temp.clear();
                nodesInCurrentLevel = nodesInNextLevel;
                nodesInNextLevel = 0;
            }
        }
        reverse(levelNodes.begin(), levelNodes.end());
        return levelNodes;
    }
};