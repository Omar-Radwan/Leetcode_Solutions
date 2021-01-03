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
    int ans;
    int traverse(TreeNode* root){
        if (root == NULL) return 0;
        int longest_left = traverse(root->left);
        int longest_right = traverse(root->right);
        ans = max(ans, longest_left + longest_right);
        return 1+max(longest_left, longest_right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0; 
        traverse(root);
        return ans;
    }
};
