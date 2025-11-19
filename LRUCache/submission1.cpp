class Node {
    public:
        int key;
        int value;
        Node * next;
        Node * prev;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }
};

void insertNode(int key, int value, Node *start)
{
    Node * p = start->next;
    Node * q = new Node(key, value);
    start->next = q;
    q->prev = start;
    q->next = p;
    p->prev = q;
}

void deleteNode(Node *p)
{
    Node *left = p->prev;
    Node *right = p->next;
    left->next = right;
    right->prev = left;
    delete p;
}

class LRUCache {
public:
    int cap;
    int n;
    unordered_map<int, Node*> m;
    Node * start;
    Node * end;
    LRUCache(int capacity) {
        start = new Node(-1, -1);
        end = new Node(-1, -1);
        start->next = end;
        end->prev = start;
        cap = capacity;
        n = 0;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        int v = m[key]->value;
        deleteNode(m[key]);
        m.erase(key);
        insertNode(key, v, start);
        m[key] = start->next;
        return v;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            int v = m[key]->value;
            deleteNode(m[key]);
            m.erase(key);
            insertNode(key, value, start);
            m[key] = start->next;
            return;
        }
        if(n<cap)
        {
            insertNode(key, value, start);
            m[key] = start->next;
            n++;
        }
        else
        {
            Node * lru = end->prev;
            m.erase(lru->key);
            deleteNode(lru);
            insertNode(key, value, start);
            m[key] = start->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
