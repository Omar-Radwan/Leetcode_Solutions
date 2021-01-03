import java.util.HashSet;

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; next = null; } }
 */
public class Solution {
	public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        int l1 = length(headA);
        int l2 = length(headB);

        if (l1>l2){
            headA = traverse(headA,l1-l2);
        }
        else {
            headB = traverse(headB,l2-l1);
        }

        while (headA!=null&&headA!=headB){
            headA = headA.next;
            headB=  headB.next;
        }

        return headA;

    }

    public int length (ListNode head){
        int size= 0 ;
        while (head!=null){
            size++;
            head = head.next;

        }
        return size;
    }

    public ListNode traverse(ListNode head,int n ){
        int size = 0;
        while (head!=null&&size<n){
            size++;
            head = head.next;
        }
        return head;
    }
}
