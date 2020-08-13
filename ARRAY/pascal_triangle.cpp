vector<vector<int> > solve(int A) {
    vector<vector<int>> res(A);
    if(A==0)
        return res;
    res[0].push_back(1);
    for(int i=1;i<A;i++)
    {
        res[i].push_back(1);
        for(int j=1;j<i;j++)
            res[i].push_back(res[i-1][j-1]+res[i-1][j]);
        res[i].push_back(1);
    }
    return res;
}
