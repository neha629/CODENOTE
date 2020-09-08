//RECURSIVE
int lis(int a[],int n,int *res)
{
    if(n==0)
        return 1;
    
    int max_ending_here = 1,curr;
    
    for(int i=0;i<n;i++)
    {
        curr = lis(a,i,res);
        if(a[n]>a[i] && curr>=max_ending_here)
            max_ending_here = curr + 1;
    }
    
    *res = max(*res,max_ending_here);
    return max_ending_here;
}

//DP
int lis(const vector<int> &A) {
    int n = A.size();
    int lis[n];
    lis[0] = 1;
    for(int i=1;i<n;i++)
    {
        lis[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(A[i]>A[j] && lis[i]<=lis[j])
                lis[i] = lis[j] + 1;
        }
    }
    return *max_element(lis,lis+n);
}