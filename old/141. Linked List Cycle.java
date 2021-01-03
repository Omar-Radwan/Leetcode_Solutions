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

        HashSet<ListNode> x = new HashSet<>();

        boolean cycle = false;

        while (head!=null){
            if (x.contains(head)){
                cycle = true;
                break;
            }
            x.add(head);
            head = head.next;
        }

        return cycle;
    }
}
