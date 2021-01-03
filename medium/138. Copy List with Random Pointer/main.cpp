/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* new_head = new Node(0), *tmp = head, *prev = new_head;
        unordered_map<Node*, Node*> mp;
        
        while (tmp!=NULL){
            prev->next = new Node(tmp->val);
            mp[tmp] = prev->next;
            tmp = tmp->next, prev = prev->next;
        }
        Node* cur = new_head->next;
        tmp = head;
        while (tmp!=NULL){
            cur->random = mp[tmp->random];
            tmp = tmp->next, cur = cur->next;
        }
        
        return new_head->next;
    }
};
