/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == null) return head;
        RandomListNode node = head;
        RandomListNode temp = null;
        // duplicate nodes
        while(node != null){
            temp = node.next;
            RandomListNode newNode = new RandomListNode(node.label);
            node.next = newNode;
            newNode.next = temp;
            node = temp;
        }
        // assign random ptr
        node = head;
        while(node != null){
            if(node.random != null) node.next.random = node.random.next;
            node = node.next.next;
        }
        RandomListNode newHead = head.next;
        node = head;
        RandomListNode newNode = node.next;
        // restore the original list
        while(node != null){
            node.next = newNode.next;
            if(newNode.next != null) newNode.next = newNode.next.next;
            node = node.next;
            if(node != null) newNode = node.next;
        }
        return newHead;
    }
}