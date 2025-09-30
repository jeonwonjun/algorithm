class MyQueue {
        stack<int> i;
        stack<int> o;
        int k;
public:
    MyQueue() {}
    
    void push(int x) {
        i.push(x);
    }
    
    int pop() {
        peek();
        int k = o.top();
        o.pop();
        return k;
    }
    
    int peek() {
        if (o.empty()){
            while(!i.empty()){
                o.push(i.top());
                i.pop();
            }
        }
        return o.top();
    }
    
    bool empty() {
        if(i.empty() && o.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */