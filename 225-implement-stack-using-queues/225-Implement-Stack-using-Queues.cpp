class MyStack {
public:
    queue<int> obj;
    MyStack() {
        
    }
    
    void push(int x) {
        int size = obj.size();
        obj.push(x);
        for(int i=0 ;i<size;i++){
            obj.push(obj.front());
            obj.pop();
        }
    }
    
    int pop() {
        int del = obj.front();
        obj.pop();
        return del;
    }
    
    int top() {
        return obj.front();
    }
    
    bool empty() {
        return obj.empty();
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