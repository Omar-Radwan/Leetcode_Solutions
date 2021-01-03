/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int maxDepthRecursive(TreeNode* root) {
        if (root == NULL) return 0;
        return 1+ max(maxDepth(root->left), maxDepth(root->right));
    }
    
    
    int maxDepthIterative(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;
        
        if (root != NULL)
        q.push(make_pair(root,1));
        
        int ans = 0;
        while (!q.empty()){
            auto [node, depth] = q.front();
            q.pop();
            
            if (node->left != NULL)
                q.push(make_pair(node->left, depth+1));
            
            if (node->right != NULL)
                q.push(make_pair(node->right, depth+1));
            
            if (q.empty())
                ans = depth;
            
            
        }
        
        return ans;
        
    }

    int maxDepth(TreeNode* root) {
        return maxDepthIterative(root);
    }
};
