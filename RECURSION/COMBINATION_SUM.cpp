vector<vector<int> > res;
vector<int> curr;

void func(int sum,int i,vector<int> &A)
{
    if(sum<0)
        return;
    
    if(sum==0)
    {
        res.push_back(curr);
        return;
    }
    
    while(i<A.size() && sum-A[i]>=0)
    {
        curr.push_back(A[i]);
        func(sum-A[i],i,A);
        i++;
        curr.pop_back();
    }
}
vector<vector<int> > combinationSum(vector<int> &A, int B) {
    res.clear();
    curr.clear();
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(), A.end()), A.end()); 
    func(B,0,A);
    return res;
}
