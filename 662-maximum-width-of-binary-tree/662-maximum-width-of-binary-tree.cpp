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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long res = 0;
        while(!q.empty()){
            unsigned long long left= q.front().second, right = 0;
            
            int s = q.size();
            
        
            for(int i = 0; i < s; i++){
                auto temp = q.front();
                right = temp.second;
                q.pop();
                if(temp.first -> left) q.push({temp.first -> left, 2 * temp.second + 1});
                if(temp.first -> right) q.push({temp.first -> right, 2 * temp.second + 2});
            }
            res = max(res, right - left + 1);
        }
        return res;
        
    }
};