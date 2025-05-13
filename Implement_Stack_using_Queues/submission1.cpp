class MyStack {
public:
    queue<int> q1;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int element, size = q1.size();
        for (int i=0; i<size; i++){
            int front = q1.front();
            q1.pop();
            if (i == size-1){
                element = front;
            } else {
                q1.push(front);
            }
        }

        return element;
    }
    
    int top() {
        int element, size = q1.size();
        for (int i=0; i<size; i++){
            int front = q1.front();
            q1.pop();
            if (i == size-1){
                element = front;
            } 
            q1.push(front);
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