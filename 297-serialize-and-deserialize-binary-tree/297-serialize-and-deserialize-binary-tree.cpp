/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int helper(string &data){
        int pos = data.find(',');
        int val = stoi(data.substr(0, pos));
        data = data.substr(pos + 1);
        return val;
    }
    // Encodes a tree to a single string.
    string res;
    string serialize(TreeNode* root) {
         if(root == NULL){
          return "#";
         } 
        
        return to_string(root -> val) + "," + serialize(root -> left) + "," + serialize(root -> right);
    }

    // Decodes your encoded data to tree.
   TreeNode * de(string &data){
        if(data[0] == '#'){
            if(data.size() > 1)data = data.substr(2);
            return NULL;
        }
        else{
            TreeNode *root = new TreeNode(helper(data));
            root -> left = de(data);
            root -> right = de(data);
            return root;
        }
    }
    TreeNode* deserialize(string data) {
       return de(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

 