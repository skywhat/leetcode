class MyQueue {
private:
    stack<int> store, output;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        store.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(output.empty()){
            while(store.size()){
                output.push(store.top());
                store.pop();
            }
        }
        
        int front = output.top();
        output.pop();
        return front;
    }
    
    /** Get the front element. */
    int peek() {
        if(output.empty()){
            while(store.size()){
                output.push(store.top());
                store.pop();
            }
        }
        
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return store.empty()&&output.empty();
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
