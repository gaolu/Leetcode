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
        // Recursively call the function to deal with first two nodes
        if(!head || !head->next) return head;
        ListNode *nextNode = head->next;
        head->next = nextNode->next;
        nextNode->next = head;
        head = nextNode;
        head->next->next = swapPairs(head->next->next);
        return head;
    }
};
