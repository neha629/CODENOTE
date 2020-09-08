//MEMOIZE
int lcs(string a,string b,int n,int m)
{
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(a[n-1]==b[m-1])
        return dp[n][m] = 1+lcs(a,b,n-1,m-1);
    else
        return dp[n][m] = max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
}


//TOP-DOWN
int lcs(string a,string b,int n,int m)
{
    vector<vector<int>> dp;
    dp.resize(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(a[i-1]==b[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}