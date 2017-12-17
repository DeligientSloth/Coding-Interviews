class Solution {
public:
    stack<int> stack_data;
    stack<int> stack_min;
    void push(int value) {
        stack_data.push(value);
        if(stack_min.empty()||stack_min.top()>value)
            stack_min.push(value);
        else
            stack_min.push(stack_min.top());
    }
    void pop() {
        if(stack_data.empty()==false) stack_data.pop();
        stack_min.pop();
    }
    int top() {
        return stack_data.top();
    }
    int min() {
        return stack_min.top();
    }
};