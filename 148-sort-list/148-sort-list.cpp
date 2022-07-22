/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1)return l2;
        if(!l2)return l1;
        
        ListNode* head = (l1 -> val < l2 -> val) ? l1 : l2;
        
         if(l1 -> val < l2 -> val){
             head -> next = merge(l1 -> next, l2);
         }else{
            head -> next =  merge(l1, l2 -> next);
         }
         return head;
        }
    ListNode* sortList(ListNode* head) {
   if(head == NULL || head -> next == NULL)return head;
    ListNode* fast = head; ListNode * slow = head;
    
    while(fast -> next and fast ->next -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    //Node* res = merge(head, slow -> next);
    ListNode * newHead = slow -> next;
    slow -> next = NULL;
    return merge(sortList(head), sortList(newHead));
    }
};