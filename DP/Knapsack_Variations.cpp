// Subset Sum
//MEMOIZE
vector<vector<int>> dp;
int subsetSum(vector<int> &arr,int sum,int n)
{
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    if(arr[n-1]<=sum)
        return dp[n][sum] = subsetSum(arr,sum-arr[n-1],n-1) || subsetSum(arr,sum,n-1);
    else
        return dp[n][sum] = subsetSum(arr,sum,n-1);
}

//TOP DOWN
int subsetSum(vector<int> &arr,int sum)
{
    int n = arr.size();
    vector<vector<int>> dp;
    dp.resize(n+1,vector<int>(sum+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                dp[i][j] = 1;
            else if(i==0)
                dp[i][j] = 0;
            else if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}


// Count of all subsets with given sum
int subsetSumCount(int arr[],int sum,int n)
{
    vector<vector<int>> dp;
    dp.resize(n+1,vector<int>(sum+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                dp[i][j] = 1;
            else if(i==0)
                dp[i][j] = 0;
            else if(arr[i-1]<=j)
                dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j])%mod;
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}


// Minimum Subset Sum Difference
int minDiff(vector<int> &arr,int sum)
{
    int n = arr.size();
    vector<vector<int>> dp;
    dp.resize(n+1,vector<int>(sum+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                dp[i][j] = 1;
            else if(i==0)
                dp[i][j] = 0;
            else if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=sum/2;i>=0;i--)
    {
        if(dp[n][i])
            return sum - 2*i;
    }
}


//Target Sum
int subsetSumDiff(vector<int> &arr,int sum)
{
    int n = arr.size();
    vector<vector<int>> dp;
    dp.resize(n+1,vector<int>(sum+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                dp[i][j] = 1;
            else if(i==0)
                dp[i][j] = 0;
            else if(arr[i-1] == 0)
                dp[i][j] = dp[i-1][j];
            else if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int findTargetSumWays(vector<int>& nums, int S) 
{
    int n = nums.size(),sum = 0,c = 0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
       if(nums[i]==0)
            c++;
    }
    if(S>sum)
        return 0;
    if((S+sum)%2!=0)
        return 0;
    int curr = (S+sum)/2;
    return pow(2,c)*subsetSumDiff(nums,curr);
}