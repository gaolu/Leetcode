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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        bool end1 = (l1 == NULL);
        bool end2 = (l2 == NULL);
        while(true){
            if(!end1){
                tail->val += l1->val;
                l1 = l1->next;
                end1 = (l1 == NULL);
            }
            if(!end2){
                tail->val += l2->val;
                l2 = l2->next;
                end2 = (l2 == NULL);
            }
            carry = tail->val >= 10 ? 1: 0;
            tail->val %= 10;
            if(!end1 || !end2 || carry == 1){
                tail->next = new ListNode(carry);
                tail = tail->next;
            }
            else
                break;
        }
        return head;
    }
};