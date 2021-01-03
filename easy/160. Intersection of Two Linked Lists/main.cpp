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
    int size(ListNode* head){
        int ret = 0;
        while (head != NULL) ret++, head = head->next;
        return ret;
    }
    ListNode* traverse(ListNode*& head, int steps){
        while (steps-- && head!=NULL)
            head = head->next;
        return head;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a_size = size(headA);
        int b_size = size(headB);
        
        if (a_size > b_size) swap(headA, headB), swap(b_size, a_size);
        traverse(headB,  b_size-a_size);
        
        while (headA != headB)
            headA = headA->next, headB = headB->next;
        
        return headA;
    }
};
