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
    ListNode* reverseList(ListNode *head){
        ListNode *prev = NULL;
        while(head != NULL){
            ListNode *temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *forHead = new ListNode();
        
        forHead -> next = head;
        
        //maintain Head, prev, nextHead, tail
        
        
        ListNode *prev = forHead;
        
        for(int len = 1; len < 1e5 and head; len++){
            ListNode *tail = head, *nextHead = NULL;
            int j = 1;
            while(j < len and tail -> next) {
                tail = tail -> next;
                j++;
            }
            
            nextHead = tail -> next;
            if((j % 2) == 0){
                tail -> next = NULL;
                prev -> next = reverseList(head);
                prev = head;
                head -> next = nextHead;
                head = nextHead;
            }else {
                prev = tail;
                head = nextHead;
            }
            
        }
        return forHead -> next;
        
    }
};