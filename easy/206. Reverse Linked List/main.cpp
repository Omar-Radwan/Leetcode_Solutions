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
public:

    ListNode* reverseListIterative(ListNode* head) {
        
        ListNode* new_head = NULL;
        
        while (head != NULL){
            ListNode* next_node = head->next;
            head->next = new_head;
            new_head = head;
            head = next_node;
        }
        
        return new_head;
    }
    ListNode* reverseListRecursive(ListNode* current, ListNode* previous) {
        if (current->next == NULL){
            current->next = previous;
            return current;
        }
        ListNode* ret = reverseListRecursive(current->next, current);
        current->next = previous;
        return ret;
        
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        return reverseListIterative(head);

    }
};
