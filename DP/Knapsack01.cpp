//Memoize
vector<vector<int>> dp;
int knap01(vector<int> &val, vector<int> &wt, int W, int n)
{
    if(W==0 || n==0)
        return 0;
        
    if(dp[n][W]!=-1)
        return dp[n][W];
        
    if(wt[n-1]<=W)
        return dp[n][W] = max(val[n-1]+knap01(val,wt,W-wt[n-1],n-1) , knap01(val,wt,W,n-1));
    else
        return dp[n][W] = knap01(val,wt,W,n-1);
}

int solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    dp.clear();
    dp.resize(n+1,vector<int>(C+1,-1));
    return knap01(A,B,C,n);
}

//Top-Down
int knap01(vector<int> &val, vector<int> &wt, int W)
{
    int n = val.size();
    vector<vector<int>> dp;
    dp.resize(n+1,vector<int>(W+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(wt[i-1]<=j)
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

//Unbounded Knapsack
int solve(const vector<int> &A, const vector<int> &wt, const vector<int> &val) {
    int res = 0, n = val.size();
    int W = *max_element(A.begin(),A.end());
    vector<vector<int>> dp;
    dp.resize(n+1,vector<int>(W+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(j==0)
                dp[i][j] = 0;
            else if(i==0)
                dp[i][j] = 1e9;
            else if(wt[i-1]<=j)
                dp[i][j] = min(val[i-1]+dp[i][j-wt[i-1]] , dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=0;i<A.size();i++)
        res+=dp[n][A[i]];
    return res;
}