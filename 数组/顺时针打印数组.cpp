class Solution {
public:
    void PrintMatrixInCircle(vector<int>& vec,int start,vector<vector<int> > matrix,int rows,int columns){
        int endX=columns-1-start,endY=rows-1-start;
        /*
        只有一列：start=endX,只有一行：start=endY
        从左到右：start->endX，处于第start行
        从上到下：start+1->endY，处于第endX列
        从右到左：endX-1->start，处于第endy行
        从下到上：endY-1->start+1，处于第start列
        */
        for(int idx=start;idx<=endX;idx++)
            vec.push_back(matrix[start][idx]);
        for(int idx=start+1;idx<=endY;idx++)
            vec.push_back(matrix[idx][endX]);
        if(start<endY){//当start==endy时，只有一行，从左到右过程中已经遍历过，
            //至少有两行两列的时候，才能进行此次遍历，start-1>=endX,表示至少需要两列，条件包含在for循环里面
            for(int idx=endX-1;idx>=start;idx--)
                vec.push_back(matrix[endY][idx]);
        }
        if(start<endX){//start=endx时，只有一列，从上到下的时候已经遍历过
            //至少有三行两列的时候才能进行此次遍历,endY-1>=start+1，表示至少需要三行，条件包含在for循环里面
            for(int idx=endY-1;idx>=start+1;idx--)
                vec.push_back(matrix[idx][start]);
        }
    }
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int columns=matrix[0].size(),rows=matrix.size();
        vector<int> vec;
        if(columns==0||rows==0) return vec;//返回空的vector
        //循环条件，当两边空格个数等于列长或者行长的话，返回，因为已经无法容纳一个数字了
        //因此：两边格子总和：2*start<行长和列长
        for(int start=0;(start<<1)<rows&&(start<<1)<columns;start++)//start表示两边空白位置的长度
            PrintMatrixInCircle(vec,start,matrix,rows,columns);
        return vec;
    }
};