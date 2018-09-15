// Design a max stack that supports push, pop, top, peekMax and popMax.
//
// push(x) -- Push element x onto stack.
// pop() -- Remove the element on top of the stack and return it.
// top() -- Get the element on the top.
// peekMax() -- Retrieve the maximum element in the stack.
// popMax() -- Retrieve the maximum element in the stack, and remove it. If you
// find more than one maximum elements, only remove the top-most one. Example 1:
// MaxStack stack = new MaxStack();
// stack.push(5);
// stack.push(1);
// stack.push(5);
// stack.top(); -> 5
// stack.popMax(); -> 5
// stack.top(); -> 1
// stack.peekMax(); -> 5
// stack.pop(); -> 1
// stack.top(); -> 5
// Note:
// -1e7 <= x <= 1e7
// Number of operations won't exceed 10000.
// The last four operations won't be called when stack is empty.

// using two stacks
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}

    void push(int x) {
        if (s2.empty() || s2.top() <= x) {
            s2.push(x);
        }
        s1.push(x);
    }

    int pop() {
        int t = s1.top();
        s1.pop();
        if (s2.top() == t) {
            s2.pop();
        }
        return t;
    }

    int top() { return s1.top(); }

    int peekMax() { return s2.top(); }

    int popMax() {
        int t = s2.top();
        s2.pop();
        stack<int> temp;
        while (s1.top() != t) {
            temp.push(s1.top());
            s1.pop();
        }
        s1.pop();
        while (!temp.empty()) {
            push(temp.top());
            temp.pop();
        }
        return t;
    }

private:
    stack<int> s1, s2;
};

// using list map
class MaxStack2 {
public:
    /** initialize your data structure here. */
    MaxStack() {}

    void push(int x) {
        st.push_front(x);
        m[x].push_back(st.begin());
    }

    int pop() {
        int t = *st.begin();
        st.pop_front();
        m[t].pop_back();
        if (m[t].empty()) {
            m.erase(t);
        }
        return t;
    }

    int top() { return *st.begin(); }

    int peekMax() {
        int t = (*m.rbegin()).first;
        return t;
    }

    int popMax() {
        int t = peekMax();
        auto it = m[t].back();
        m[t].pop_back();
        if (m[t].empty()) {
            m.erase(t);
        }
        st.erase(it);
        return t;
    }

private:
    list<int> st;
    map<int, vector<list<int>::iterator>> m;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
