剑指offer上的做法
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows=array.size(),columns=array[0].size();//行数和列数
        if(!rows||!columns) return false;//避免传入空vector
        int rowIndex=0,columnIndex=columns-1;//定位右上角
        while(rowIndex<rows&&columnIndex>=0){
            if(array[rowIndex][columnIndex]==target) return true;
            else if(target<array[rowIndex][columnIndex]) columnIndex--;
            else rowIndex++;
        }
        return false;
    }
};
或者进行二分查找
 for(int i=0;i<array.size();i++){//遍历每一行
            int low=0,high=array[i].size()-1;//对每一行进行二分查找
            while(low<=high){
                int mid=(low+high)>>1;
                if(array[i][mid]==target) return true;
                else if(target>array[i][mid]) low=mid+1;
                else high=mid-1;
            }
        }
        return false;
​
