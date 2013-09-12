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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // get left and right subtrees, respectively and then iterate them to get nodes
        if(n == 0)
            return *generateTrees(1, 0);
        return *generateTrees(1, n);
    }
    
    vector<TreeNode*> *generateTrees(int start, int end){
        vector<TreeNode*> *subTree = new vector<TreeNode*>();
        if(start > end){
            subTree->push_back(NULL);
            return subTree;
        }
        
        for(int i = start; i <= end; i++){
            vector<TreeNode*> *leftSub = generateTrees(start, i - 1);
            vector<TreeNode*> *rightSub = generateTrees(i + 1, end);
            for(int m = 0; m < leftSub->size(); m++){
                for(int n = 0; n < rightSub->size(); n++){
                    TreeNode *node = new TreeNode(i);
                    node->left = (*leftSub)[m];
                    node->right = (*rightSub)[n];
                    subTree->push_back(node);
                }
            }
        }
        return subTree;
    }
};
