/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {

        ListNode ret = head;

        while (ret!=null&&ret.val == val)
            ret = ret.next;

        if (ret==null)
            return null;

        head = ret;

        while (head!=null&&head.next!=null){
            if (head.next.val==val){
                head.next = head.next.next;
            }
            else {
                head = head.next;
            }
        }

            return ret;
    }


}
