class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        //pop是对stack2进行操作
        int data;
        if(stack2.empty()){
            while(!stack1.empty()){
                data=stack1.top();
                stack2.push(data);
                stack1.pop();
            }
        }
        if(stack2.empty()){
            cout<<"queue is empty"<<endl;
            return INT_MAX;
        };
        data=stack2.top();
        stack2.pop();
        return data;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
