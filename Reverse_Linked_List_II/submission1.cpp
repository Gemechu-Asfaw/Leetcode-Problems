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
private:
    ListNode* nextElement(ListNode* current, int counter, int right){

        while (counter<=right){
            current = current->next;
            counter++;
        }

        return current;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* &current, int counter, int right){

        pair<ListNode*,ListNode*> ans;
        ans.second = current;

        ListNode* previous = NULL;

        while (counter<=right){
            ListNode* forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
            counter++;
        }

        ans.first = previous;

        return ans;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int counter = 1;
        ListNode* previous = NULL;
        ListNode* current =  head;

        while (counter<left){
            previous = current;
            current = current->next;
            counter++;
        }

        ListNode* nextNode = nextElement(current, counter, right);
        pair<ListNode*, ListNode*> reversedList = reverse(current, counter, right);

        if (previous!=NULL){
            previous->next = reversedList.first;
        }
        else{
            head = reversedList.first;
        }
        (reversedList.second)->next = nextNode;

        return head;
    }
};