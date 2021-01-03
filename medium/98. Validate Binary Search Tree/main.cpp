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
    bool is_valid(TreeNode* root, long long min_val, long long max_val){
        if (root == NULL) return true;
        return  root->val >=min_val && root->val <= max_val &&
                is_valid(root->left, min_val, 1LL*root->val-1) && 
                is_valid(root->right,1LL*root->val+1, max_val);
    }
    
    bool isValidBST(TreeNode* root) {
        return is_valid(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};
