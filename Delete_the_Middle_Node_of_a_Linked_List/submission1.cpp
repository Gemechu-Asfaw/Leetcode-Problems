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
    int getLength(ListNode* head){
        int length = 0;
        while (head){
            head = head->next;
            length++;
        }
        return length;
    }

    ListNode* deleteMiddle(ListNode* head) {
        int length = getLength(head);
        ListNode *prev = NULL, *current = head;

        for (int i=0; i<length/2; i++){
            prev = current;
            current = current->next;
        }

        if (prev){
            prev->next = current->next;
            current->next = NULL;
        } else {
            ListNode *nextHead = head->next;
            head->next = NULL;
            head = nextHead;
        }

        return head;
    }
};