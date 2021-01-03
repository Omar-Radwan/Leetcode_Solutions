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
    int px, py , dx, dy;
    void traverse(TreeNode* root, int&x, int&y, int depth){
        if (root == NULL) return;
        if (root->left != NULL){
            if (root->left->val == x) px = root->val, dx = depth+1;    
            if (root->left->val == y) py = root->val, dy = depth+1;
        }
        if (root->right != NULL){
            if (root->right->val == x) px = root->val, dx = depth+1;
            if (root->right->val == y) py = root->val, dy = depth+1;
        }
        traverse(root->left, x, y, depth+1), traverse(root->right, x, y, depth+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        px = -1,py = -1, dx = -1, dy = -1;
        traverse(root, x,y,0);
        return dx == dy && px != py;
    }
};
