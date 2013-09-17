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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // complexity is nlogk, n is the # of nodes in each list, k is the # of lists
        if(lists.size() <= 0) return NULL;
        if(lists.size() == 1) return lists[0];
        int numLists = lists.size();
        while(numLists > 1){
            int afterMerge = (numLists + 1) / 2;
            for(int i = 0; i < afterMerge && i + afterMerge < numLists; i++){
                lists[i] = mergeTwoLists(lists[i], lists[i + afterMerge]);
            }
            numLists = afterMerge;
        }
        return lists[0];
    }
    // merge two lists at a time
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
        ListNode *result = NULL;
        ListNode **runner = &result;
        while(list1 != NULL || list2 != NULL){
            if(list1 != NULL){
                ListNode *minNode;
                if(list2 == NULL || list1->val <= list2->val){
                    minNode = list1;
                    list1 = list1->next;
                }
                else if(list2 != NULL){
                    minNode = list2;
                    list2 = list2->next;
                }
                *runner = minNode;
                runner = &(minNode->next);
            }
            else{
                *runner = list2;
                break;
            }
        }
        return result;
    }
};
