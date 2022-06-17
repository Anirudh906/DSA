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
// -1 : you have a camera
// 0 : you are monitored by childen's camera
// 1 : dont place camera, ask upper nodes to have camera
class Solution {
public:
    int c = 0;
    int Cameras(TreeNode * root){
        if(!root)return 0;
        int lchild = Cameras(root -> left);
        int rchild = Cameras(root -> right);
        
        if(lchild == 1 || rchild == 1){
           c++;
            return -1;
        }
        if(lchild == - 1 || rchild == - 1) return 0;
        else return 1;
        }
    
    
    int minCameraCover(TreeNode* root) {
        if(Cameras(root) == 1)c++;
        return c;
    }
};