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
    int PreIdx;
    TreeNode *ctree(vector<int> preorder, vector<int> inorder, unordered_map<int, int> &mp, int l, int r){
         if(l > r) return NULL;
        TreeNode *root = new TreeNode(preorder[PreIdx++]);
        int idx = mp[root -> val];
        
        root ->left = ctree(preorder, inorder, mp, l, idx -1) ;
        root -> right = ctree(preorder, inorder, mp, idx + 1, r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         PreIdx = 0;
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp.insert({inorder[i], i});
        }
        return ctree(preorder, inorder, mp, 0, n-1);
    }
};