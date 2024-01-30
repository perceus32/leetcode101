class MinStack {
    stack<int> s, mins;
    // stack<long long> s;
    // long long mini;
public:
    MinStack() {
        // mini=INT_MAX;
    }
    
    void push(int val) {
        s.push(val);
        if(mins.empty()){mins.push(val);}
        else{if(mins.top()>=val){
            mins.push(val);
        }}
        // if(s.empty()){
        //     s.push(val);
        //     mini=val;
        // }else{
        //     if(val<mini){
        //         s.push(2*(long long)val - mini);
        //         mini=val;
        //     }else{
        //         s.push(val);
        //     }
        // }
    }
    
    void pop() {
        if(mins.top()==s.top()){
            mins.pop();
        }
        s.pop();
        // if(s.empty()) return;
        // if(s.top()<mini){
        //     mini = 2*mini - s.top();
        //     s.pop();
        // }else{
        //     s.pop();
        // }
    }
    
    int top() {
        return s.top();
        // if(s.top()<mini){
        //     return 2*mini - s.top();
        // }else{
        //     return s.top();
        // }
    }
    
    int getMin() {
        return mins.top();
        // return mini;
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