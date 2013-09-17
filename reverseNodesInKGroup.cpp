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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || k <= 1) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        int i = 0;
        while(head){
            ++i;
            // reverse every k nodes
            if(i % k == 0){
                prev = reverse(prev, head->next);
                head = prev->next;
            }
            else head = head->next;
        }
        return dummy.next;
        
    }
    // prev is the node before the starting node, after is the one after
    // starting node is the last, and the end of curr is the first
    // return the last so the main program proceed to the next k nodes
    ListNode *reverse(ListNode *prev, ListNode *after){
        ListNode *last = prev->next;
        ListNode *curr = last->next;
        while(curr != after){
            last->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = last->next;
        }
        return last;
    }
};
