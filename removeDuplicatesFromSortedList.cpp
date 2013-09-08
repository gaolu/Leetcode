/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
            return head;
        ListNode *prevNode = head;
        ListNode *currNode = head;
        while(currNode->next){
            currNode = currNode->next;
            if(prevNode->val == currNode->val){
                prevNode->next = currNode->next;
                delete currNode;
                currNode = prevNode;
            }
            else
                prevNode = currNode;
        }
        return head;
    }
};