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
    void convert(TreeNode*& node,int l, int r ,vector<int>& nums){
        if (l>r) return;
        int m = l+(r-l)/2;
        node = new TreeNode(nums[m]);
        convert(node->left, l, m-1, nums), convert(node->right, m+1, r, nums);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        convert(root, 0, nums.size()-1, nums);
        return root;
    }
};
