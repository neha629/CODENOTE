vector<int> lszero(vector<int> &A) {
    int res=0,s = -1,e = -1,sum = 0;
    unordered_map<int,int> m;
    vector<int> ans;
    for(int i=0;i<A.size();i++)
    {
        sum += A[i];
        if(m.find(sum)==m.end())
            m[sum] = i;
        if(sum==0)
        {
            s = 0;
            e = i;
            res = i+1;
        }
        else if(i-m[sum]>res)
        {
            res = i-m[sum];
            s = m[sum] + 1;
            e = i;
        }
    }
    if(res == 0)
        return ans;
    ans.assign(A.begin()+s,A.begin()+e+1);
    return ans;
}
