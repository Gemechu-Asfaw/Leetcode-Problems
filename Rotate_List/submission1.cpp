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

    ListNode* rotateRight(ListNode* head, int k) {
        int n = getLength(head);
        k = (n==0) ? 0 : k%n;

        if (k==0 || n==0){
            return head;
        }

        ListNode *temp = head;
        for (int i=0; i<n-k-1; i++){
            temp = temp->next;
        }

        ListNode* nextNode = temp->next;
        temp->next = NULL;
        
        temp = nextNode;
        while (temp && temp->next){
            temp = temp->next;
        }

        temp->next = head;
        return nextNode;
    }
};