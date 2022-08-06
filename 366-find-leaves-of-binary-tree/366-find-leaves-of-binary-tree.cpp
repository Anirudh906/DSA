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
    int dfs(TreeNode *root, vector<vector<int>> &res){
        if(!root)return 0;
        int lvl = max(dfs(root -> left, res), dfs(root -> right, res)) + 1;
        if(lvl > res.size())res.push_back(vector<int>());
        res[lvl - 1].push_back(root -> val);
        return lvl;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
};