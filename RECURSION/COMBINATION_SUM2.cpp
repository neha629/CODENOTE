vector<vector<int> > res;
vector<int> curr;

void func(int i,int sum,vector<int> &A)
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
        func(i+1,sum-A[i],A);
        i++;
        curr.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    res.clear();
    curr.clear();
    sort(A.begin(),A.end());
    func(0,B,A);
    res.erase(unique(res.begin(), res.end()), res.end()); 
    return res;
}
