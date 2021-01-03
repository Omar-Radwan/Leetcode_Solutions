/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:ls
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        ListNode* prev = head, *current = head->next;
        while (current != NULL){
            if (current->val == val){
                prev->next = current->next;
                current = current->next;
            }
            else prev = prev->next, current = current->next;
        }
        
        return head->next;
        
    }
};
