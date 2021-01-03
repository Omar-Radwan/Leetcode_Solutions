/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* s(Node*& h){
        Node* head = h;
        Node* ret = h;
        
        while (head != NULL){
            if (head->child != NULL){
                Node* last = s(head->child);
                last->next = head->next;
                
                if (head->next!=NULL)
                    head->next->prev = last;
                head->next = head->child;
                head->child->prev = head;
                head->child = NULL;
                head =last->next;
            }
            else 
                head = head->next;
        }
        
        while (ret->next!=NULL) 
            ret = ret->next;
        return ret;   
    }
    
    Node* flatten(Node* head) {
        if (head ==NULL) return head;
        s(head);
        return head;
    }
};
