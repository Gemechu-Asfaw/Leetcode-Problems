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
    ListNode* reverse(ListNode *&head){
        ListNode *previous = NULL, *current = head;
        while (current){
            ListNode* forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }
        return previous;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *first = head, *second = head;
        ListNode *newHead = NULL, *previous = NULL;
        while (first){
            int x = 1;
            while (x<k && second->next){
                second = second->next;
                x++;
            }

            ListNode *nextNode = second->next;
            second->next = NULL;

            if (x==k){
                first = reverse(first);
                if (previous) previous->next = first;
                if (!newHead) newHead = first;

                while (first->next){
                    first = first->next;
                }
                first->next = nextNode;
                previous = first;
            }

            first = second = nextNode;
        }

        return newHead;
    }
};