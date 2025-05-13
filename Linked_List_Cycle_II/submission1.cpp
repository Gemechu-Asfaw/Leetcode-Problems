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
    ListNode *detectCycle(ListNode *head) {

        if (!head){
            return NULL;
        }

        ListNode *slow = head, *fast = head;
        while (fast){
            slow = slow->next;
            fast = fast->next;
            if (fast){
                fast = fast->next;
            }

            if (slow==fast){
                break;
            }
        }

        if (!fast){
            return NULL;
        }

        slow = head;
        while (true){
            if (slow == fast){
                break;
            } else {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow;
    }
};