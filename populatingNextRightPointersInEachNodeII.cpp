/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while(root){
            TreeLinkNode *nextStart = NULL;
            TreeLinkNode *runner = NULL;
            for( ; root; root = root->next){
                if(!nextStart)
                    nextStart = root->left ? root->left : root->right;
                if(root->left){
                    if(runner)
                        runner->next = root->left;
                    runner = root->left;
                }
                if(root->right){
                    if(runner)
                        runner->next = root->right;
                    runner = root->right;
                }
            }
            root = nextStart;
        }
    }
};