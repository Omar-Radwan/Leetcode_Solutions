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
    int ret = -1;
    
    int size(TreeNode* root, int k){
        if (root == NULL) return 0;
        int l_size = size(root->left, k), r_size = 0;
        if (l_size == k-1)
            ret = root->val;
        if (ret == -1)
            r_size = size(root->right, k-l_size-1);
        return 1+r_size+l_size;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        size(root, k);
        return ret;
    }
};
