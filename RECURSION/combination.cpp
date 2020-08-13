vector<vector<int> > res;
void func(int A,int B,int s,vector<int> &curr)
{
    if(B==0)
    {
        res.push_back(curr);
        return;
    }
    for(int i=s;i<=A;i++)
    {
        curr.push_back(i);
        func(A,B-1,i+1,curr);
        curr.pop_back();
    }
}
vector<vector<int> > combine(int A, int B) {
    res.clear();
    vector<int> curr;
    func(A,B,1,curr);
    return res;
}
