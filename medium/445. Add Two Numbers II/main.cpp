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
    
    ListNode* reverse_list(ListNode* head){
        ListNode* new_head = NULL;
        
        while (head!=NULL){
            ListNode* tmp = head;
            head= head->next;
            tmp->next= new_head;
            new_head = tmp;
        }
        return new_head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* prev = result;
        bool carry = 0 ;
        l1 = reverse_list(l1),l2= reverse_list(l2);
        while (l1!=NULL || l2!=NULL){
            int v1 = l1==NULL?0:l1->val, v2 = l2==NULL?0:l2->val;

            int sum = v1+v2+carry;
            if (sum>=10)
                carry =1, sum-=10;
            else carry = 0 ;
            
            ListNode* cur = new ListNode(sum);
            prev->next = cur;
            prev = prev->next;
            
            if (l1!=NULL)
                l1 = l1->next;
            if (l2!=NULL)
                l2 = l2->next;
        }
        
        if (carry)
            prev->next = new ListNode(1);
        
        result = reverse_list(result->next);
        return result;
    }
};
