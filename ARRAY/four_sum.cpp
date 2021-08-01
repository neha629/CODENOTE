vector<vector<int> > fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    unordered_map<int,vector<pair<int,int>>> m;
    int n = A.size();
    set<vector<int>> ans;
    vector<vector<int>> res;
    
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            m[A[i]+A[j]].push_back({i,j});
            
        
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum = A[i]+A[j];
            if(m.find(B-sum)!=m.end())
            {
                for(auto p:m[B-sum])
                {
                    if(p.first!=i && p.first!=j && p.second!=i && p.second!=j)
                    {
                        vector<int> temp = {A[p.first],A[p.second],A[i],A[j]};
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
    }
    for(auto &it:ans)
        res.push_back(it);
    return res;
}
