分治法，时间复杂度o(nlogn)，有空再补上动态规划的，动态规划时间复杂度是o(n)
class Solution {
public:
    int myFindGreatSum(vector<int> array,int low,int high){
        /*在[low,high]中寻找连续最大值，分为三种情况
        1. 连续最大和区间位于[low,mid] 2.连续最大和区间位于[mid+1,high]
        3.最大和区间横跨mid*/
        if(array.empty()) return 0;//数组内没有值
        if(low==high) return array[low];//只有一个元素，直接返回
        int mid=(low+high)>>1;
        int Max=max(myFindGreatSum(array,low,mid),myFindGreatSum(array,mid+1,high));
        int L=array[mid],R=array[mid+1],sumCross=0;//分别表示以mid为起点向左的最大值，以mid+1为起向右最大值，sum保存中间结果
        for(int i=mid;i>=low;i--) L=max(L,sumCross+=array[i]);
        for(int i=mid+1,sumCross=0;i<=high;i++) R=max(R,sumCross+=array[i]);
        return max(L+R,Max);
    }
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        return myFindGreatSum(array,0,array.size()-1);
    }
};