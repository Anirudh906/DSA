/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(!node) return NULL;
        Node* ans = NULL;
        if(node -> right == NULL){
            Node* par = node -> parent;
            while(par and par -> val < node -> val){
                par = par -> parent;
            }
           ans = par;
        } else {
            node = node -> right;
            while(node -> left){
                node = node -> left;
            }
            ans = node;
        }
        return ans;
    }
};