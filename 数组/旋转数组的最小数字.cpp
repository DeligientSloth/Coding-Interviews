先来个最简单的，顺序查找！
class Solution {
public:
int minNumberInRotateArray(vector<int> rotateArray) {
if(rotateArray.empty()) return INT_MAX;
int key=rotateArray[0],index=0,len=rotateArray.size();
while(index!=len&&rotateArray[index]>=key) index++;
return index>=len? key:rotateArray[index];
}
};
二分查找：
class Solution {
public:
int minNumberInRotateArray(vector<int> rotateArray) {
int low=0,high=rotateArray.size()-1,mid=low;
if(rotateArray[low]<rotateArray[high]) return rotateArray[mid];
while(high-low>1){
mid=(low+high)>>1;
if(rotateArray[mid]==rotateArray[low]&&rotateArray[mid]==rotateArray[high])//无法判别
{
for(int index=low;index<=high&&rotateArray[index]>=rotateArray[low];index++)
return index>high? rotateArray[low]:rotateArray[index];
}
if(rotateArray[mid]>=rotateArray[low]) low=mid;
else if(rotateArray[mid]<=rotateArray[high]) high=mid;
}
return rotateArray[high];
}
};
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        int low=0,high=rotateArray.size()-1,mid=low;
        if(rotateArray[low]<rotateArray[high]) return rotateArray[mid];
        while(high-low>1){
            mid=(low+high)>>1;
            if(rotateArray[mid]>rotateArray[low]) low=mid;
            else if(rotateArray[mid]<rotateArray[low]) high=mid;
            else low=low+1;
        }
        return rotateArray[high];
    }
};
​
