
class MinStack {
private:
    stack<int> st;       // Main stack to store all elements
    stack<int> minSt;    // Stack to keep track of minimum elements

public:
    MinStack() {
        // Constructor initializes empty stacks
    }

    // Push element onto the stack
    void push(int val) {
        st.push(val);
        
        // Push the minimum between the new value and the current minimum
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        } else {
            minSt.push(minSt.top());
        }
    }

    // Remove the element on top of the stack
    void pop() {
        if (!st.empty()) {
            st.pop();
            minSt.pop();
        }
    }

    // Get the top element
    int top() {
        return st.top();
    }

    // Retrieve the minimum element in the stack
    int getMin() {
        return minSt.top();
    }
};