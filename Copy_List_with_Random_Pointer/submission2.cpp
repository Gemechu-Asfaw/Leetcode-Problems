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

        if (head==NULL){
            return NULL;
        }

        Node* temp = head;
        Node* head1 = new Node(head->val);
        Node* temp1 = head1;

        unordered_map<Node*,Node*> mapping;
        mapping[temp] = temp1;

        while (temp->next != NULL){
            temp = temp->next;
            Node* nodeToInsert = new Node(temp->val);
            temp1->next = nodeToInsert;
            temp1 = temp1->next;
            mapping[temp] = temp1;
        }

        temp = head;
        while (temp!=NULL){
            mapping[temp]->random = mapping[temp->random];
            temp = temp->next;
        }

        return head1;

    }
};