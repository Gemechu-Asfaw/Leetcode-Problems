/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node* flattenList(Node* &head){
        Node *current = head, *previous = NULL;
        while (current){
            Node *forward = current->next;
            Node *child = current->child;
            if (child){
                current->next = child;
                child->prev = current;
                current->child = NULL;
                Node *flattenedNode = flattenList(child);
                if (forward){
                    flattenedNode->next = forward;
                    forward->prev = flattenedNode;
                } else {
                    return flattenedNode;
                }
            }
            previous = current;
            current = forward;
        }
        return previous;
    }

public:
    Node* flatten(Node* head) {
        flattenList(head);
        return head;
    }
};