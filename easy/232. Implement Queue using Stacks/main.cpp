class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> push_stack, pop_stack;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        push_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = peek();
        pop_stack.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (pop_stack.empty()){
            while (!push_stack.empty()){
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }   
        }
        return pop_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return push_stack.empty() && pop_stack.empty();
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
