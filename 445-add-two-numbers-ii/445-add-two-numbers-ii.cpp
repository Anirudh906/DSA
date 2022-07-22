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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *t = &dummy;
        l1 = reverseList(l1);
        l2 = reverseList(l2); 
        int c = 0;
        while(c || l1 || l2){
            c += (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0);
            t -> next = new ListNode(c % 10);
            t = t -> next;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
            c /= 10;
        }
        ListNode *p = reverseList(dummy.next);
        return p;
    }
};