#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int N;
    while(cin>>N){//输入n
        vector<vector<int>> arr(N,vector<int>(N,0));//初始化vector
        int circle=N%2? N/2+1:N/2;//圈数
        int n=1;
        for(int x=0;x<circle;x++){
            for(int y=x;y<N-x;y++) arr[x][y]=n++;//n=4 end//列变化
            for(int y=x+1;y<N-x;y++) arr[y][N-x-1]=n++;//行变化
            for(int y=N-x-2;y>=x;y--) arr[N-x-1][y]=n++;//列变化
            for(int y=N-x-2;y>=x+1;y--) arr[y][x]=n++;//行变化
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                if(i==N-1&&j==N-1) cout<<arr[i][j];
                else cout<<arr[i][j]<<" ";
        }
    }
    return 0;
}