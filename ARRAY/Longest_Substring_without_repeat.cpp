int lengthOfLongestSubstring(string A) {
    int n = A.length(),res=0;
    vector<int> m(256,-1);
    int j = 0;
    for(int i=0;i<n;i++)
    {
        j = max(j,m[A[i]]+1);
        res = max(res,i-j+1);
        m[A[i]] = i;
    }
    return res;
}
