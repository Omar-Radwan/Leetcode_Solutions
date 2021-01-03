/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class Solution {
    public ListNode middleNode(ListNode head) {
        int size = 0 ;

        ListNode cur = head;

        while (cur!=null){
            size++;
            cur = cur.next;
        }

        int mid = size/2;
        size =0 ;
        cur = head;
        while (size!=mid){
            cur = cur.next;
            size++;
        }
        return cur;
    }
}
