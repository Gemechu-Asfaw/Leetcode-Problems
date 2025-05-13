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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1==NULL){
            return list2;
        }
        else if (list2==NULL){
            return list1;
        }

        ListNode* head = new ListNode();
        if (list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }

        ListNode* temp = head;

        while (list2!=NULL && list1!=NULL){

            ListNode* newNode = new ListNode();
            if (list1->val <= list2->val){
                newNode->val = list1->val;
                list1 = list1->next;
            }
            else{
                newNode->val = list2->val;
                list2 = list2->next;
            }
            temp->next = newNode;
            temp = temp->next;
        }

        while (list1!=NULL){
            ListNode* newNode = new ListNode();
            newNode->val = list1->val;
            list1 = list1->next;
            temp->next = newNode;
            temp = temp->next;
        }

        while (list2!=NULL){
            ListNode* newNode = new ListNode();
            newNode->val = list2->val;
            list2 = list2->next;
            temp->next = newNode;
            temp = temp->next;
        }

        return head;

    }
};