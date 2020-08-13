vector<int> twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> m;
    vector<int> ans;
    int n = A.size();
    
    for(int i=0;i<n;i++)
    {
        if(m.find(B-A[i])!=m.end())
        {
                ans.push_back(m[B-A[i]]+1);
                ans.push_back(i+1);
                return ans;
        }
        if(m.find(A[i])==m.end())
            m[A[i]] = i;
    }
    return ans;
}
