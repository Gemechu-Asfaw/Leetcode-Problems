class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int element;
        while (!q1.empty()){
            if (q1.size() == 1){
                element = q1.front();
            } else {
                int front = q1.front();
                q2.push(front);
            }
            q1.pop();
        }

        while (!q2.empty()){
                int front = q2.front();
                q1.push(front);
                q2.pop();
        }

        return element;
    }
    
    int top() {
        int element;
         while (!q1.empty()){
            int front = q1.front();
            if (q1.size() == 1){
                element = front;
            }
            q2.push(front);
            q1.pop();
        }

        while (!q2.empty()){
            int front = q2.front();
            q1.push(front);
            q2.pop();
        }

        return element;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */