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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *cur = new ListNode();
         cur -> next = head;
        while(cur != NULL){
          for(int i = 0; i < m and cur != NULL; i++) cur = cur -> next;
            if(cur == NULL) break;
            ListNode *temp = cur;
            for(int j = 0; j < n and cur != NULL; j++) cur = cur -> next;
            temp -> next = cur ? cur -> next: NULL;
            
        }
        return head;
    }
};