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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m <= 0 || n <= 0 || m >= n)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *preM, *pre = &dummy;
        for(int i = 1; i <= n; i++){
            if(i == m)
                preM = pre;
            if(i > m && i <= n){
                //preM->next = head;
                pre->next = head->next;
                head->next = preM->next;
                preM->next = head;
                head = pre;
            }
            pre = head;
            head = head->next;
        }
        return dummy.next;
        
        
    }
};
