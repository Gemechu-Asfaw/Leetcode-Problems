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
    bool hasCycle(ListNode *head) {
        
        unordered_map<ListNode*, bool> occurance;
        while (head!=NULL){
            if (occurance.find(head) != occurance.end()){
                return true;
            }
            occurance[head] = true;
            head = head->next;
        }

        return false;
    }
};