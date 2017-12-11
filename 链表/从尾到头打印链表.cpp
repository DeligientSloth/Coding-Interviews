链接：https://www.nowcoder.com/questionTerminal/d0267f7f55b3412ba93bd35cfa8e8035
来源：牛客网

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> S;
        vector<int> v;
        ListNode* node=head;
        while(node!=NULL)
        {
            S.push(node->val);
            node=node->next;
        }
        while(!S.empty())
        {
            v.push_back(S.top());
            S.pop();
        }
        return v;
    }
};
或者：
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* node=head;
        vector<int> v;
        while(node!=NULL){
            v.push_back(node->val);
            node=node->next;
        }
        return vector<int>(v.rbegin(),v.rend());
    }
};

递归版本
class Solution {
public:
    void printListRecursion(ListNode* head,vector<int>& v)
    {
        if(head==NULL) return;
        printListRecursion(head->next,v);
        v.push_back(head->val);
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        if(head==NULL) return v;
        printListRecursion(head,v);
        return v;
    }
};
