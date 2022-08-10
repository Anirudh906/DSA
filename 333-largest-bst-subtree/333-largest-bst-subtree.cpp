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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        int mn = INT_MIN, mx = INT_MAX;
        BSTUtil(root, mn, mx, res);
        return res;
    }
    bool BSTUtil(TreeNode* root, int &mn, int &mx, int &res){
        if(!root) return true;
        
        int l_min = INT_MIN, l_max = INT_MAX, l_c = 0;
        bool l = BSTUtil(root -> left, l_min, l_max, l_c);
        
        int r_min = INT_MIN, r_max = INT_MAX, r_c = 0;
        bool r = BSTUtil(root -> right, r_min, r_max, r_c);
        
        if(left and right){
            if((root -> left == NULL || root -> val > l_max) and (root -> right == NULL || root -> val < r_min)){
                res = 1 + l_c + r_c;
                
                mn = root -> left ? l_min: root -> val;
                mx = root -> right ? r_min : root -> val;
                return true;
            }
         }
        res = max(l_c, r_c);
        return false;
    }
    
};