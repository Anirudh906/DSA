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
    void count(TreeNode* root, int &c, int v){
       if(!root) return;
        if(root -> val >= v){
            c++; v = root -> val;
        }
        count(root -> left, c, v);
        count(root -> right, c, v);
    }
    int goodNodes(TreeNode* root) {
     int c = 0;
        count(root, c, INT_MIN);
        return c;
    }
};