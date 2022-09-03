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
    int longestConsecutive(TreeNode* root) {
        return search(root, 0, NULL);
    }
    
    int search(TreeNode* root, int val, TreeNode* parent){
        if(!root) return val;
        val = (parent and root ->val == parent -> val + 1) ? val + 1: 1;
        return max({val, search(root -> left, val, root), search(root -> right, val, root)});
    }
};