class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        mn.push( mn.empty() ? val : min(val, mn.top()) );
    }
    
    void pop() {
        stk.pop();
        mn.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mn.top();
    }
    
    stack<int> stk, mn;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */