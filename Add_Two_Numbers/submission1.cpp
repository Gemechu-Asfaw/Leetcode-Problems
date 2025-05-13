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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *current = NULL, *head = NULL;
        while (l1 || l2){
            int sum = carry;
            if (l1) sum = sum + l1->val;
            if (l2) sum = sum + l2->val;
            int digit = sum%10;
            carry = sum/10;

            if (l1 && l2){
                if (!current){
                    head = current = new ListNode(digit);
                } else {
                    current->next = new ListNode(digit);
                    current = current->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1){
                current->next = new ListNode(digit);
                current = current->next;
                l1 = l1->next;
            } else {
                current->next = new ListNode(digit);
                current = current->next;
                l2 = l2->next;
            }
        }

        if (carry){
            current->next = new ListNode(1);
        }

        return head;
    }
};