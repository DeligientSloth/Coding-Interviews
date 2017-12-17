链接：https://www.nowcoder.com/questionTerminal/70610bf967994b22bb1c26f9ae901fa2?toCommentId=1127471
来源：牛客网

class Solution {
public:
int GetLowerBound(vector<int> data,int k){
if(data.empty()) return -1;
int low=0,high=data.size()-1;
while(low<=high){
int mid=low+((high-low)>>1);
if(data[mid]>k) high=mid-1;//mid->high都大于k
else if(data[mid]<k) low=mid+1;//low->mid都小于k
else{//相等的情况
if(mid==0||data[mid-1]!=k) return mid;
else high=mid-1;//到左边找
}
}
return -1;
}
int GetUpperBound(vector<int> data,int k){
if(data.empty()) return -1;
int low=0,high=data.size()-1;
while(low<=high){
int mid=low+((high-low)>>1);
if(data[mid]>k) high=mid-1;
else if(data[mid]<k) low=mid+1;
else{
if(mid==data.size()-1||data[mid+1]!=k) return mid;
else low=mid+1;//与lower不同，要到右边找
}
}
return -1;
}
int GetNumberOfK(vector<int> data ,int k) {
if(data.empty()) return 0;
int lowerBound=GetLowerBound(data,k);
int upperBound=GetUpperBound(data,k);
return lowerBound!=-1? upperBound-lowerBound+1:0;
}
};
这样写那两个函数也可以！
class Solution {
public:
    int GetLowerBound(vector<int> data,int k){
        if(data.empty()) return -1;
        int low=0,high=data.size()-1;
        while(low<high){
            int mid=low+((high-low)>>1);
            if(data[mid]>k) high=mid-1;//mid->high都大于k
            else if(data[mid]<k) low=mid+1;//low->mid都小于k
            else high=mid;
        }
        return data[low]==k? low:-1;
    }
    int GetUpperBound(vector<int> data,int k){
        if(data.empty()) return -1;
        int low=0,high=data.size()-1;
        while(low+1<high){
            int mid=low+((high-low)>>1);
            if(data[mid]>k) high=mid-1;
            else if(data[mid]<k) low=mid+1;
            else low=mid;//到右边找
        }
        if(data[high]==k) return high;
        if(data[low]==k) return low;
        return -1;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        int lowerBound=GetLowerBound(data,k);
        int upperBound=GetUpperBound(data,k);
        return lowerBound!=-1? upperBound-lowerBound+1:0;
    }
};
