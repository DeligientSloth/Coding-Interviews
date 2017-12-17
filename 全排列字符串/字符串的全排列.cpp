链接：https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7?toCommentId=1127845
来源：牛客网

class Solution {
public:
vector<string> retS;
void myPermutation(string str,int start){
if(str[start]=='\0') retS.push_back(str);
else{
for(int i=start;str[i]!='\0';i++){
if(i!=start&&str[start]==str[i]) continue;
swap(str[start],str[i]);//逐个与i交换
myPermutation(str,start+1);//进入下一轮
//swap(str[start],str[i]);//换回来，换回来不满足字典序
}
}
}
vector<string> Permutation(string str) {
if(str.empty()) return retS;
sort(str.begin(),str.end());//保证字典序
myPermutation(str,0);
return retS;
}
};
非递归的方法：
class Solution {
public:
    vector<string> retS;
    void Reverse(string& s,int start,int end){
        while(start<end) swap(s[start++],s[end--]);
    }
    bool next_Permutation(string& s,int start,int end){
        /*1.找到第一个非逆序元素。2.在逆序元素中找到大于该元素的最小整数。3.交换他们。4.逆序*/
        int cur=end,pre=cur-1;//cur和pre分别指向最后两个元素
        while(cur>start&&s[pre]>=s[cur]){
            pre--;cur--;
        }
        if(cur<=start) return false;//全部逆序，没救了
        //pre为该非逆序元素
        for(cur=end;s[cur]<=s[pre];cur--);
        swap(s[pre],s[cur]);
        Reverse(s,pre+1,end);
        return true;
    }
    vector<string> Permutation(string str) {
        if(str.empty()) return retS;
        sort(str.begin(),str.end());//保证字典序
        do{
            retS.push_back(str);
        }while(next_Permutation(str,0,str.length()-1));
        return retS;
    }
};
