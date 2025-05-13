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
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* reverse(ListNode* &head){
        ListNode *prev = NULL, *current = head;
        while (current){
            ListNode* forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        int length = getLength(head);

        ListNode *first = head, *second = head;
        for (int i=0; i<(length-1)/2; i++){
            second = second->next;
        }

        second->next = reverse(second->next);
        second = first;
        for (int i=0; i<(length-1)/2+1; i++){
            second = second->next;
        }

        int count = 0;
        while (second){
            if (second->val != first->val){
                cout << first->val << " " << second->val << " " << count << endl;
                return false;
            } else {
                first = first->next;
                second = second->next;
            }
            count++;
        }

        return true;
    }
};