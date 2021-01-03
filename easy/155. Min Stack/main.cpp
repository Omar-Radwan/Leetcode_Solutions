class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st, min_st;
    
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        min_st.push((min_st.empty()? x: min(x,min_st.top())));
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
