/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      if (root == NULL) return root;
        
        int level = 1;
        bool broke = false;
        while (!broke){
            int last = (1<<level) - 1;
            Node* prev = NULL;
            for (int mask = 0 ;mask <=last ;mask++){
                Node* cur= root;
                for (int i= level-1; i >= 0 && cur!=NULL; i--)
                    cur = (((1<<i) & mask) == 0 ? cur->left : cur->right);
                if (mask == 0 && cur == NULL) {
                    broke = true;
                    break;
                }
                if (cur != NULL){
                    if (prev != NULL)
                        prev->next =cur;
                    prev = cur;
                }
            }
            level++;
        }
        
        return root;
    }
};
