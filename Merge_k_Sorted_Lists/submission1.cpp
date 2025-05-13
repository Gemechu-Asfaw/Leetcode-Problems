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

class cmp{
public:
    bool operator()(ListNode* &a, ListNode* &b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL, *temp = NULL;
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (int i=0; i<n; i++){
            if (lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        while (!pq.empty()){
            ListNode* top = pq.top();
            ListNode* next = top->next;
            pq.pop();
            top->next = NULL;
            if (next != NULL){
                pq.push(next);
            }

            if (head==NULL){
                head = temp = top;
            } else {
                temp->next = top;
                temp = temp->next;
            }
        }

        return head;
    }
};