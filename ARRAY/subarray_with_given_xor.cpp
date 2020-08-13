int solve(vector<int> &A, int B) {
    int n = A.size(),ans=0;
    int x[n];
    unordered_map<int,int> m;
    x[0] = A[0];
    for(int i=1;i<n;i++)
        x[i] = A[i]^x[i-1];
    
    for(int i=0;i<n;i++)
    {
        int tmp = x[i]^B;
        ans += m[tmp];
        if(x[i] == B)
            ans++;
        m[x[i]]++;
    }
    return ans;
}
