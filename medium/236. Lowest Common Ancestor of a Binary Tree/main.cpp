/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool search(TreeNode* root, TreeNode* req, stack<TreeNode*>& path){
        if (root == NULL) return false;
        path.push(root);
        if (root->val == req->val) 
            return true;
        bool l = false, r = false;
        
        l = search(root->left, req, path);        
        r = search(root->right, req, path);
        
        if (!(l||r))
            path.pop();
        return l||r;
    }
    
    TreeNode* lca(stack<TreeNode*>& small, stack<TreeNode*>& large){
       while (large.size()>small.size())
           large.pop();
       
        while (large.top()->val != small.top()->val)
            large.pop(),small.pop();
    
        return large.top();
    }
            
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> sp, sq;
        search(root, p, sp);
        search(root, q, sq);
        return sp.size() > sq.size()? lca(sq,sp):lca(sp,sq);
    }
};
