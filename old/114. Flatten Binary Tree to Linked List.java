/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public void flatten(TreeNode root) {
        if (root==null) return ;
        traverse(root);
    }

    public TreeNode  traverse (TreeNode root){

        if (root.left==null&&root.right==null){
            return root;
        }

        if (root.right==null||root.left==null){
            if (root.right==null){
            root.right=root.left;
            root.left = null;
            }
            return traverse(root.right);
        }

        else {
            TreeNode lowestLeft = traverse(root.left);
            TreeNode lowestRight = traverse(root.right);
            lowestLeft.right=root.right;
            root.right = root.left;
            root.left =null;
            return lowestRight;
        }


    }
}
