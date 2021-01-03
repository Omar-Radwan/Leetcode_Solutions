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
    vector<int> ret;
    void traverse(TreeNode* root, int depth){
        if (root == NULL) return;
        if (ret.size()<=depth)
            ret.push_back(root->val);
        traverse(root->right, depth+1), traverse(root->left, depth+1);
    
    }
    vector<int> rightSideView(TreeNode* root) {
        traverse(root, 0);
        return ret;
    }
};
