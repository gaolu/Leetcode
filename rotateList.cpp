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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
            return head;
        int listLength = 1;
        ListNode * runner = head;
        while(runner->next){
            listLength++;
            runner = runner->next;
        }
        ListNode *listEnd = runner;
        k %= listLength;
        runner = head;
        int leftOver = listLength - (k + 1);
        while(leftOver){
            leftOver--;
            runner = runner->next;
        }
        listEnd->next = head;
        head = runner->next;
        runner->next = NULL;
        return head;
        }
};
