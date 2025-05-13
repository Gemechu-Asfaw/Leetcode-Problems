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
        int count = 0;
        while (head){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* merge(ListNode *&left, ListNode *&right){

        ListNode *head = NULL, *current = NULL;
        while (left && right){

            if (left->val <= right->val){
                ListNode* nextNode = left->next;
                if (current){
                    current->next = left;
                    current = current->next;
                } else {
                    head = current = left;
                }
                left = nextNode;
            } else {
                ListNode* nextNode = right->next;
                if (current){
                    current->next = right;
                    current = current->next;
                } else {
                    head = current = right;
                }
                right = nextNode;
            }
        }

        if (left){
            current->next = left;
        }

        if (right){
            current->next = right;
        }
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next){
            return head;
        } else {
            int length = getLength(head);
            ListNode *first = head, *second = head;

            for (int i=0; i<(length-1)/2; i++){
                second = second->next;
            }

            ListNode* nextToSecond = second->next;
            second->next = NULL;

            ListNode *left = sortList(first);
            ListNode *right = sortList(nextToSecond);

            ListNode* sortedList = merge(left, right);
            return sortedList;
        }
    }
};