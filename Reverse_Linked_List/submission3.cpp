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
    ListNode* solve(ListNode* &head, ListNode* &previous){

        if (head == NULL){
            return previous;
        } 
        ListNode* forward = head->next;
        head->next = previous;
        return solve(forward, head);
    }

    ListNode* reverseList(ListNode* head) {
        
        if (head==NULL){
            return head;
        } 
        ListNode* previous = NULL;
        return solve(head, previous);
    }
};