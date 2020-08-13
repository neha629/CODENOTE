vector<vector<int> > res;
bool func(int i,int j,vector<vector<int> > &A)
{
    if(i<0 || i>=A.size() || j<0 || j>=A.size())
        return false;
        
    if(i==(A.size()-1) && j==(A.size()-1) && A[i][j]==1)
    {
        res[i][j]=1;
        return true;
    }
    
    if(A[i][j]==1)
    {
        res[i][j] = 1;
        if(func(i+1,j,A))
            return true;
        if(func(i,j+1,A))
            return true;
        res[i][j] = 0;
        return false;
    }
    return false;
}
vector<vector<int> > solve(vector<vector<int> > &A) {
    res.clear();
    res.resize(A.size(),vector<int>(A.size(),0));
    func(0,0,A);
    return res;
}
