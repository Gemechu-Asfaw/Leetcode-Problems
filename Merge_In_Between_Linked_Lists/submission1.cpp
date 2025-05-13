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

    ListNode* findTail(ListNode* head){
        while (head->next){
            head = head->next;
        }
        
        return head;
    }

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode *temp=list1, *tail=findTail(list2);
        
        for (int i=0; i<=b; i++){
            if (i==a-1){
                ListNode* current = temp->next;
                temp->next = list2;
                temp = current;
            } else if (i==b){
                tail->next = temp->next;
            } else {
                temp = temp->next;
            }
        }

        return list1;
    }
};