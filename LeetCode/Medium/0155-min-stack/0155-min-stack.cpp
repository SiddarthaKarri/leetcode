class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()){
            mini=val;
            s.push(val);
            return;
        }
        if(val>mini)
            s.push(val);
        else{
            s.push(2LL*val-mini);
            mini = val;
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        long long x=s.top();
        s.pop();
        if(x<mini)
            mini = 2LL*mini-x;
    }
    
    int top() {
        if(s.empty())
            return -1;
        long long x= s.top();
        if(x>mini)
            return x;
        return mini;
    }
    
    int getMin() {
        return mini;
    }
private:
    stack <long long> s;
    long long mini;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */