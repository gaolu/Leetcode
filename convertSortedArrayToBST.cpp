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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() == 0) return NULL;
        return helper(num, 0, num.size() - 1);
    }
    
    TreeNode *helper(vector<int> &num, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = helper(num, start, mid - 1);
        node->right = helper(num, mid + 1, end);
        return node;
    }
};
