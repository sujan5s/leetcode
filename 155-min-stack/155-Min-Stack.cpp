class MinStack {
public:
    stack<long long> st;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            mini=value;
            st.push(value);
        }else{
            if(value>=mini){
                st.push(value);
            }else{
                st.push(2LL*value-mini);
                mini=value;
            }
        }
    }
    
    void pop() {
    if (st.empty()) return;
    long long n = st.top();
    st.pop();
    if (n < mini) {
        mini = (int)(2LL * mini - n);
    }
}

int top() {
    if (st.empty()) return -1;
    long long n = st.top();
    if (n >= mini) return (int)n;
    return mini;
}
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */