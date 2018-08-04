class MinStack {
    
    stack<int> data, aux;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if (aux.empty() || aux.top() >= x) aux.push(x);
    }
    
    void pop() {
        int ret = data.top();
        data.pop();
        if (!aux.empty() && aux.top() == ret) aux.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return aux.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
