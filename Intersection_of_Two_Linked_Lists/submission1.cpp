/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *head){
        int ans = 0;
        while (head){
            head = head->next;
            ans++;
        }
        return ans;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA), lenB = getLength(headB);
        ListNode *ptr1 = headA, *ptr2 = headB;
        if (lenA > lenB){
            while (lenA > lenB){
                ptr1 = ptr1->next;
                lenA--;
            }
        } else {
            while (lenB > lenA){
                ptr2 = ptr2->next;
                lenB--;
            }
        }

        while (ptr1){
            if (ptr1 == ptr2){
                return ptr1;
            } else {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }

        return NULL;
    }
};