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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *a = new ListNode(0);
        ListNode *b = new ListNode(0);
        ListNode *pSmaller = a;
        ListNode *pLarger = b;
        if(head == NULL)
            return head;
        while(head != NULL){
            if(head->val < x){
                pSmaller->next = head;
                pSmaller = head;
                head = head->next;
            }
            else{
                pLarger->next = head;
                pLarger = head;
                head = head->next;
            }
        }
        pLarger->next = NULL;
        pSmaller->next = b->next;
        return a->next;
    }
};
