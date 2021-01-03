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
    
    int size(ListNode* head){
        int result = 0 ;
        while (head!=NULL)
            head = head->next, result++;
        return result;
    }
    ListNode* find(int i, ListNode* head){
        while (i-->0 && head!=NULL)
            head = head->next;
        return head;
    }
    
    ListNode* reverse(ListNode* head){
         ListNode* result = NULL;
         while (head!=NULL){
             ListNode* tmp = head->next;
             head->next = result;
             result = head;
             head = tmp;
         }
        return result;
    }
    
    bool compare(ListNode* head1, ListNode* head2){
        while (head1!=NULL && head2!=NULL){
            if (head1->val != head2->val)
                return false;
            head1 = head1->next, head2 = head2->next;
        }
        return true;
    }
    
    
    bool isPalindrome(ListNode* head) {
        int length = size(head);
        if (length <= 1) return true;
        int mid = (length+1)/2;
        
        ListNode* head2 = reverse(find(mid, head));
        
        return compare(head, head2);
        
    }
};
