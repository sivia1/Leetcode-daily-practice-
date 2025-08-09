class MinStack {
public:
//PROBLEM --> We NEED to remember the previous minimum when the current minimum gets popped
//utilise two stack approach
stack<int> st;
stack<int> minStk;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(minStk.empty() || val <= minStk.top()) {
            minStk.push(val);
        }
    }
    
    void pop() {
        if(st.top() == minStk.top()) {
            minStk.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */