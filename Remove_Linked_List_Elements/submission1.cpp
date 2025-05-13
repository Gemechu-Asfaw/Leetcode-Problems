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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL){
            return head;
        }

        ListNode* nextNode = head->next;
        if (head->val == val){
            delete head;
            return removeElements(nextNode, val);
        } else {
            head->next = removeElements(nextNode, val);
            return head;
        }
    }
};