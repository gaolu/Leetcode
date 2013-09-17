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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // Iterate the list and we need THREE ListNodes to store and re-link the nodes
        if(!head || !head->next) return head;
        ListNode *firstOfPrev = NULL, *prev = head, *curr = head->next;
        while(curr){
            prev->next = curr->next;
            curr->next = prev;
            if(firstOfPrev) firstOfPrev->next = curr;
            else head = curr;
            
            firstOfPrev = prev;
            prev = prev->next;
            if(prev) curr = prev->next;
            else curr = NULL;
        }
        return head;
    }
};
