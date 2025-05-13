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
    ListNode* getMiddle(ListNode* head){

        ListNode* head1 = head, *head2 = head->next;
        while (head2 && head2->next){
            head1 = head1->next;
            head2 = head2->next;
            if (head2){
                head2 = head2->next;
            }
        }

        return head1;
    }

    ListNode* reverse(ListNode* &head){

        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* forward;

        while (current){
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }

        return previous;
    }

    bool isPalindrome(ListNode* head) {
        
        ListNode* middle = getMiddle(head);
        ListNode* temp1 = head, *temp2 = middle;
        ListNode* nextNode = temp2->next;
        temp2->next = reverse(nextNode);
        temp2 = temp2->next;

        while (temp2){
            if (temp1->val != temp2->val){
                return false;
            } else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        return true;
    }
};