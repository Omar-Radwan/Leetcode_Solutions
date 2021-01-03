/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head==null||head.next==null)return true;
        boolean isPal = true;

        int size = size(head);
        ListNode last = getIndx(head,(size/2)-1);

        ListNode start = head;

        while (start!=last){
            ListNode tmp = start.next;
            start.next = last.next;
            last.next = start;
            start = tmp;
        }

        ListNode l1 = last;
        ListNode l2 = getIndx(last,(size+1)/2);

        while (l2!=null){
            if (l1.val!=l2.val){
                isPal = false;
                break;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        return isPal;

    }

    public int size (ListNode head){
        ListNode cur = head;
        int size = 0 ;
        while (cur!=null){
            cur = cur.next;
            size++;
        }
        return size;
    }

    ListNode getIndx (ListNode head,int indx){
        int size = 0 ;
        ListNode cur = head;
        while (cur!=null&&size!=indx){
            cur = cur.next;
            size++;
        }
        return cur;
    }
}
