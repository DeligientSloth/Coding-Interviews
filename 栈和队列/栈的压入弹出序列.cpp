链接：https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106?toCommentId=1124975
来源：牛客网

遍历出栈序列，在找到与当前出栈序列元素相同的出栈元素之前，将出栈元素压入栈中，如果没有找到则返回false，找到则pop
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size()||pushV.size()==0) return false;
        int len=pushV.size(),pushIdx=0;
        stack<int> S;
        for(int popIdx=0;popIdx!=len;popIdx++){
            while(S.empty()||(pushIdx!=len&&S.top()!=popV[popIdx]))
                    S.push(pushV[pushIdx++]);//压入最后一个元素的时候，pushIdx==len
            if(S.top()!=popV[popIdx]) return false;
            S.pop();
        }
        return true;
    }
};
更自然的解法是遍历压栈序列，如果到了出栈的时候就出栈，结束之后栈应该是空战
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size()||pushV.size()==0) return false;
        stack<int> S;
        int len=pushV.size(),popidx=0;
        for(int pushidx=0;pushidx!=len;pushidx++){//遍历压栈序列，一个个压入栈中
            S.push(pushV[pushidx]);
            while(popidx!=len&&S.empty()==false&&S.top()==popV[popidx]){
                S.pop();
                popidx++;
            }
        }
        return S.empty();
    }
};
