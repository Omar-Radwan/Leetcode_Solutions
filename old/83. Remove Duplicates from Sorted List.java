/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {

        TreeSet<ListNode> x = new TreeSet<>();

        boolean cycle = false;

        while (head!=null){
            if (x.contains(head)){
                cycle = true;
                break;
            }
            x.put(head);
            head = head.next;
        }

        return cycle;
    }
}
