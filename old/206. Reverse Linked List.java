/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */


class Solution {
    public ListNode reverseList(ListNode head) {
        if (head==null) return null;

        ListNode cur = head ;
        ListNode next = null;

        while (true){
            ListNode tmp = cur.next;
            cur.next = next;
            next = cur;
            if (tmp==null) break;
            cur = tmp;
        }

        return cur;


    }
}
