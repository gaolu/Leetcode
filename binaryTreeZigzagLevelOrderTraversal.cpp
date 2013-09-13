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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // used stack in this version
        // can also use queue but need to do the reverse alternatively
        vector<vector<int>> zigzag;
        if(!root)
            return zigzag;
        bool leftToRight = true;
        stack<TreeNode *> currentLevel, nextLevel;
        currentLevel.push(root);
        vector<int> nodes;
        while(!currentLevel.empty()){
            TreeNode *currNode = currentLevel.top();
            currentLevel.pop();
            nodes.push_back(currNode->val);
            if(leftToRight){
                if(currNode->left)
                    nextLevel.push(currNode->left);
                if(currNode->right)
                    nextLevel.push(currNode->right);
            }
            else{
                if(currNode->right)
                    nextLevel.push(currNode->right);
                if(currNode->left)
                    nextLevel.push(currNode->left);
            }
            if(currentLevel.empty()){
                leftToRight = !leftToRight;
                zigzag.push_back(nodes);
                nodes.clear();
                swap(currentLevel, nextLevel);
            }
        }
        return zigzag;
    }
};
