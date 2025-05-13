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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        ListNode* temp = head;
        int length = 0;

        while (temp!=NULL){
            length++;
            temp = temp->next;
        }

        int mainLength = length/k;
        int sideLength = length%k;

        vector<ListNode*> ans (k, NULL);
        int i = 0;
        ListNode* current = head;
        ListNode* previous = NULL;

        while (i<k && current!=NULL){

            ans[i] = current;

            for (int i=0; i<mainLength; i++){
                if (previous==NULL){
                    previous = head;
                }
                else{
                    previous = current;
                }
                current = current->next;
            }

            if (sideLength){
                if (previous==NULL){
                    previous = head;
                }
                else{
                    previous = current;
                }
                current = current->next; 
                sideLength--;
            }

            previous->next = NULL;
            i++;
        }

        return ans;
    }
};