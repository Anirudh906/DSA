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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root -> val == p ->val || root ->val == q -> val) return root;
        TreeNode *lcal= lowestCommonAncestor(root ->left, p, q);
        TreeNode *lcar= lowestCommonAncestor(root ->right, p, q);
        if(lcal!=NULL and lcar!=NULL) return root;
        if(lcal!=NULL)return lcal;
        else return lcar;
        
    }
};