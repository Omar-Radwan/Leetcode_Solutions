/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {

      ListNode cur = node;

      while (true){
        int tmp = cur.val;
        cur.val = cur.next.val;
        cur.next.val = tmp;
        if (cur.next.next==null){
            cur.next=null;
          break;
        }
        cur = cur.next;
      }





    }
}
