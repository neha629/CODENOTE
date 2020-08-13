int solve(vector<vector<int> > &A) {
    map<int,int> presum;
    for(int i=0;i<A.size();i++)
    {
        presum[A[i][0]]++;
        presum[A[i][1]]--;
    }
    int res = 0,curr = 0;
    for(auto it:presum)
    {
        curr += it.second;
        res = max(res,curr);
    }
    return res;
}
int solve(vector<vector<int> > &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    int rooms=0;
    priority_queue<int> pq;
    for(int i=0; i<n; ++i){
        while(!pq.empty()&& -pq.top()<A[i][1])
            pq.pop();
        pq.push(-A[i][1]);
        rooms=max(rooms,(int)pq.size());
    }
    return rooms;
}