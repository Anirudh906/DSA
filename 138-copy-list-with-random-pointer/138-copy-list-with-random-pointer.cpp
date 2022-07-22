/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        
         for(Node* cur = head; cur != NULL;){
              Node* nxt = cur -> next;
              cur -> next = new Node(cur -> val);
              cur -> next -> next = nxt;
             cur = nxt;
        }
        for(Node* cur = head; cur != NULL; cur = cur -> next -> next){
            cur -> next -> random = (cur -> random) ? cur -> random -> next : NULL;
        }
        Node* original = head, *copy = head->next; 
  
     Node* temp = copy; 
  
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp;   
    
    }
};