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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<pair<TreeNode*,int>> q;
        if (root != NULL)
        q.push(pair<TreeNode*, int>(root,0));
        
        while (!q.empty()){
            auto[node, level] = q.front();
            q.pop();
            
            if (ret.size() == level)
                ret.push_back(vector<int>());
            ret[level].push_back(node->val);
            
            if (node->left != NULL)
                q.push({node->left, level+1});
            
            if (node->right != NULL)
                q.push({node->right, level+1});
            
        }
        return ret;
    }
};
