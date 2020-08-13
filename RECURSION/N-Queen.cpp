vector<int> col,diag1,diag2;
vector<vector<string> > res;
 
bool isSafe(int x,int y,int n)
{
    if(col[x] || diag1[x+y] || diag2[x-y+n-1])
        return false;
    return true;
}
 
void func(int y,int n,vector<string> &curr)
{
    if(y>=n)
    {
        res.push_back(curr);
        return;
    }
    for(int x=0;x<n;x++)
    {
        if(isSafe(x,y,n))
        {
            col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
            curr[x][y] = 'Q';
            func(y+1,n,curr);
            curr[x][y] = '.';
            col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
        }
    }
}
 
vector<vector<string> > solveNQueens(int A) {
    res.clear();
    col.assign(A,0);
    diag1.assign(2*A,0);
    diag2.assign(2*A,0);
    vector<string> curr(A,string(A,'.'));
    func(0,A,curr);
    return res;
}