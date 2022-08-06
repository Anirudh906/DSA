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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        
        unordered_map<TreeNode*, int> inDeg;
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto t = q.front();
            int child = 0;
            q.pop();
            if(t -> left) {
                child++;
                mp[t -> left].push_back(t);
                q.push(t -> left);
            } if(t -> right){
                child++;
                mp[t -> right].push_back(t);
                q.push(t -> right);
            }
            
           inDeg[t] = child;
        }
        
        
        queue<TreeNode *> q2;
        
        for(auto &x: inDeg){
            if(x.second == 0) q2.push(x.first);
        }
        
        while(!q2.empty()){
            int s = q2.size();
            vector<int> temp;
         for(int i = 0; i < s; i++){
            auto t = q2.front();
             temp.push_back(t -> val);
            q2.pop();
            
            for(auto &x: mp[t]){
                inDeg[x]--;
                if(inDeg[x] == 0) q2.push(x);
            }
          }
            res.push_back(temp);
        }
        return res;
    }
};