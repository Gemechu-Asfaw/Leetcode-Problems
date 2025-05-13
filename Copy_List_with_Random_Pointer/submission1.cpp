/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> newToOld, oldToNew;
        Node *newHead = NULL, *temp = NULL, *current = head;

        while (current){
            if (!newHead){
                newHead = temp = new Node(current->val);
            } else {
                temp->next = new Node(current->val);
                temp = temp->next;
            }
            oldToNew[current] = temp;
            newToOld[temp] = current;
            current = current->next;
        }

        temp = newHead;
        while (temp){
            if (newToOld[temp]->random){
                temp->random = oldToNew[newToOld[temp]->random];
            }
            temp = temp->next;
        }

        return newHead;
    }
};