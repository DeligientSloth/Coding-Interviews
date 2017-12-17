class BinarySearch {
public:
int getPos(vector<int> A, int n, int val) {
// write code here
if(A.empty()||n<=0) return -1;
int low=0,high=n-1,mid;
while(low<high){
mid=low+((high-low)>>1);
if(A[mid]>val) high=mid-1;//low->mid-1之间，mid->high都大于mid
else if(A[mid]<val) low=mid+1;//low->mid都是小于val的
else high=mid;//相等，第一个位置可能是mid以及左边，此时若循环条件为low=high会出现死循环
}
return A[low]==val? low:-1;
}
};
这样效率高一些：
class BinarySearch {
public:
    int getPos(vector<int> A, int n, int val) {
        // write code here
        if(A.empty()||n<=0) return -1;
        int low=0,high=n-1,mid;
        while(low<=high){
            mid=low+((high-low)>>1);
            if(A[mid]>val) high=mid-1;//low->mid-1之间，mid->high都大于mid
            else if(A[mid]<val) low=mid+1;//low->mid都是小于val的
            //else high=mid;//相等，第一个位置可能是mid以及左边，此时若循环条件为low=high会出现死循环
            else{
                if(mid==0||A[mid-1]!=val) return mid;
                else high=mid-1;//满足mid!=0且A[mid-1]==val
            }
        }
        return -1;
    }
};
​​
