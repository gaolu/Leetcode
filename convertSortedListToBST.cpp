/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = 0;
        ListNode *p = head;
        while(p){
            ++n;
            p = p->next;
        }
        if(n <= 0) return NULL;
        return helper(head, 0, n - 1);
    }
    
    TreeNode *helper(ListNode *& head, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode *leftChild = helper(head, start, mid - 1);
        TreeNode *currNode = new TreeNode(head->val);
        currNode->left = leftChild;
        head = head->next;
        TreeNode *rightChild = helper(head, mid + 1, end);
        currNode->right = rightChild;
        return currNode;
    }
};
