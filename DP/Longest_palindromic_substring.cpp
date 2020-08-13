string Solution::longestPalindrome(string A) {
    int n = A.length();
    int dp[n][n] = {0};
    int start  = 0, maxlen = 1;
    
    for(int i=0;i<n;i++)
        dp[i][i] = 1;
    
    for(int i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1])
        {
            dp[i][i+1] = 1;
            if(maxlen<2)
            {
                maxlen = 2;
                start = i;
            }
        }
    }
    
    for(int k=3;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j = i+k-1;
            if(A[i]==A[j] && dp[i+1][j-1]==1)
            {
                dp[i][j] = 1;
                if(k>maxlen)
                {
                    maxlen = k;
                    start = i;
                }
            }
        }
    }
    return A.substr(start,maxlen);
}
