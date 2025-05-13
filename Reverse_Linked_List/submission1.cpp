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
    pair<ListNode*, ListNode*> solve(ListNode* &head){
        if (head==NULL || head->next==NULL){
            return {head, head};
        } else {
            ListNode* forward = head->next;
            head->next = NULL;
            pair<ListNode*, ListNode*> nextNode = solve(forward);
            nextNode.second->next = head;
            return {nextNode.first, head};
        }
    }

    ListNode* reverseList(ListNode* head) {
        return solve(head).first;
    }
};