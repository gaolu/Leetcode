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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *slow = head, *fast = head;
        if(n == 1 && !head->next) return head->next;
        while(n > 0){
            fast = fast->next;
            n--;
        }
        // when fast reach to the end that means we remove the first node
        if(!fast) return head->next;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        // delete the next of slow (the node we want to delete)
        slow->next = slow->next->next;
        return head;
    }
};
