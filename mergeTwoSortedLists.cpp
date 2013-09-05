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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!l1 && l2)
            return l2;
        if(l1 && !l2)
            return l1;
        if(!l1 && !l2)
            return NULL;
        ListNode *newList = NULL;
        ListNode **runner = &newList;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                *runner = l1;
                l1 = l1->next;
            }
            else{
                *runner = l2;
                l2 = l2->next;
            }
            runner = &((*runner)->next);
        }
        if(l1)
            *runner = l1;
        else
            *runner = l2;
        return newList;
    }
};
