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
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prevNode = &dummy, *currNode = head;
        while(currNode){
            int currVal = currNode->val;
            if(currNode->next && currNode->next->val == currVal){
                while(currNode && currNode->val == currVal){
                    prevNode->next = currNode->next;
                    delete currNode;
                    currNode = prevNode->next;
                }
                currNode = prevNode;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }
        return dummy.next;
    }
};