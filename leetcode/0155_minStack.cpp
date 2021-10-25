class MinStack {
public:
    std::stack <int> order, mn_order;
    
    MinStack() {
            
    }
    
    void push(int val) {
        order.push(val);
        if(mn_order.empty() or mn_order.top()>=val){
            mn_order.push(val);
        }
    }
    
    void pop() {
        if(!mn_order.empty() and mn_order.top()==top()){
            mn_order.pop();
        }
        order.pop();
    }
    
    int top() {
        return order.top();
    }
    
    int getMin() {
        return mn_order.top();
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
