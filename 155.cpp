/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
 * */
class MinStack {
private:
    stack<int> value, min_value;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        value.push(x);
        if(min_value.empty() || min_value.top()>=x){
            min_value.push(x);
        }
    }
    
    void pop() {
        if(!min_value.empty() && min_value.top() == value.top()){
            min_value.pop();
        }
        value.pop();
    }
    
    int top() {
        return value.top();
    }
    
    int getMin() {
        return min_value.top();
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
