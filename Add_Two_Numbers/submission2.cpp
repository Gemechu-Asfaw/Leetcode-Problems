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
    ListNode* findAns(ListNode* l1, ListNode* l2){

        int carry = 0;
        ListNode* head = l1;
        while (true){

            int value = carry + l1->val;
            if (l2!=NULL){
                value = value + l2->val;
            }
            l1->val = value%10;
            carry = value/10;
            if (l2!=NULL){
                l2 = l2->next;
            }

            if (l1->next!=NULL){
                l1 = l1->next;
            }
            else{
                break;
            }
        }

        if (carry){
            ListNode* lastNode = new ListNode(carry);
            l1->next = lastNode;
        }

        return head;

    }

    int findLength(ListNode* head){
        int count = 0;
        while (head!=NULL){
            count++;
            head = head->next;
        }

        return count;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int length1 = findLength(l1);
        int length2 = findLength(l2);

        if (length1>length2){
            return findAns(l1,l2);
        }
        return findAns(l2,l1);

    }
};