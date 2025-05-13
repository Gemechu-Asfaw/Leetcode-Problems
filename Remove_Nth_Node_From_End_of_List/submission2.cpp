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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* temp = head;

        while (n--){
            temp = temp->next;
        }

        while (temp != NULL){
            temp = temp->next;
            previous = current;
            current = current->next;
        }

        if (previous==NULL){
            current = current->next;
            head->next = NULL;
            delete head;
            return current;
        } else {
            previous->next = current->next;
            current->next = NULL;
            delete current;
            return head;
        }
    }
};