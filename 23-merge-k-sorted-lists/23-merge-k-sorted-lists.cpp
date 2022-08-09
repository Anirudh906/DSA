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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        priority_queue<pair<int, ListNode*>> pq;
        for(int i = 0; i < n; i++){
            while(lists[i]){
                pq.push({-lists[i] -> val, lists[i]});
                lists[i] = lists[i] -> next;
            }
        }
        ListNode *head = NULL, *cur = NULL;
        if(pq.empty()) return NULL;
        auto k = pq.top(); pq.pop();
        head = k.second;
        cur = k.second;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            cur -> next = t.second;
            cur = cur -> next;
        } cur -> next = NULL;
        return head == NULL ? NULL : head;
    }
};