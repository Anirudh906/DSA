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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(!head -> next)return head;
        ListNode* cur = head;
        int n = 0;
        while(cur != NULL){cur = cur -> next; n++;}
        ListNode *oldTail = head;
        while(oldTail -> next != NULL){
            oldTail = oldTail -> next;
        }
        oldTail -> next = head;
        ListNode *newTail = head;
        for(int i = 0; i < n - k % n - 1; i++){
            newTail = newTail -> next;
        }
        ListNode* newHead = newTail -> next;
        newTail -> next = NULL;
        return newHead;
    }
};