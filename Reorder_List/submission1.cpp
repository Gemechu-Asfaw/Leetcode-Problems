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

    ListNode* getMiddle(ListNode* head){

        ListNode* slow = head, *fast = head->next;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void reorderList(ListNode* head) {
        
        ListNode* middle = getMiddle(head);
        ListNode* nextNode = middle->next;
        middle->next = NULL;
        nextNode = reverse(nextNode);

        ListNode* head1 = head, *head2 = nextNode;
        ListNode* next1, *next2;

        while (head2){
            next1 = head1->next;
            next2 = head2->next;

            head2->next = NULL;
            head1->next = head2;
            head2->next = next1;
            head1 = next1;
            head2 = next2;
        }
    }
};