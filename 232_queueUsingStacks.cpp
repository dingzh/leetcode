class MyQueue {
    stack<int> input_buf, output_buf;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input_buf.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (output_buf.empty()) transfer();
        int ret = output_buf.top();
        output_buf.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (output_buf.empty()) transfer();
        return output_buf.top();
    }
    
    void transfer() {
        while(!input_buf.empty()) {
            output_buf.push(input_buf.top());
            input_buf.pop();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input_buf.empty() && output_buf.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
