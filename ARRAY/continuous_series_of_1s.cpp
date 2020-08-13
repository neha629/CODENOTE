vector<int> maxone(vector<int> &A, int m) {
    int s = -1,e = -1,res = 0;
    int i = 0,j = 0,n = A.size(),cnt = 0;
    while(j<n)
    {
        if(cnt<=m)
        {
            if(A[j]==0)
                cnt++;
            j++;
        }
        if(cnt>m)
        {
            if(A[i]==0)
                cnt--;
            i++;
        }
        if((j-i)>res && cnt<=m)
        {
            res = j-i;
            s = i;
            e = j-1;
        }
    }
    vector<int> ans;
    if(s==-1)
        return ans;
    for(int i=s;i<=e;i++)
        ans.push_back(i);
    return ans;
}
