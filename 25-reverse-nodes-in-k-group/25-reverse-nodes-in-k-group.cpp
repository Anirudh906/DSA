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
    ListNode* reverseKGroup(ListNode* head, int k) {
     ListNode *cur = head; 
        ListNode *prevFirst = NULL;
        bool firstPass = true;
        int len = 0;
	    for(ListNode *p = head; p; p = p->next) len++;
        int times = len / k;
        while(times--){
            ListNode *first = cur, *prev = NULL;
            int c = 0;
            
            while(cur != NULL and c < k){
               ListNode *nxt = cur -> next;
               cur -> next = prev;
                prev = cur;
                cur = nxt;
               c++;
            }
            if(firstPass){head = prev; firstPass = false;}
            else {
                prevFirst -> next = prev;
            }
            prevFirst = first;
        }
        prevFirst -> next = cur;

        return head;
    }
};