class Coins {
public:
    int countWays(int n) {
        // write code here
        int dp[n+1],coins[4]={1,5,10,25};
        for(int j=0;j<=n;j++) dp[j]=1;//对应只用1分的情况
        for(int i=1;i<4;i++){
            for(int j=coins[i];j<=n;j++)
                dp[j]=(dp[j-coins[i]]+dp[j])%1000000007;
        }
        return dp[n];
    }
};
