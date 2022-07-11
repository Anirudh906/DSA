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
    void preorder(TreeNode *root, int l, vector<int> &res){
        if(root == NULL) return;
        
        if(res.size() < l)res.push_back(root -> val);
        preorder(root -> right, l + 1, res);
        preorder(root -> left, l + 1, res);
        
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
     vector<int> res;
        preorder(root, 1, res);
        return res;
    }
};