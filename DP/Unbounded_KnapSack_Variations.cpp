//Number of ways for coin change
int waysCoinChange(int coins[],int n,int S)
{
    vector<vector<int>> dp;
    dp.resize(n+1,vector<int>(S+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=S;j++)
        {
            if(i==0)
                dp[i][j] = 0;
            else if(j==0)
                dp[i][j] = 1;
            else if(coins[i-1]<=j)
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][S];
}


//Minimum number of coins to make the change
int numCoinChange(int coins[],int n,int S)
{
    vector<vector<int>> dp;
    dp.resize(n+1,vector<int>(S+1,INT_MAX));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=S;j++)
        {
            if(i==0)
                dp[i][j] = INT_MAX-1;
            else if(j==0)
                dp[i][j] = 0;
            else if(i==1 && j%coins[i-1]==0)
                dp[i][j] = j/coins[i-1];
            else if(coins[i-1]<=j)
                dp[i][j] = min(1+dp[i][j-coins[i-1]] , dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][S];
}