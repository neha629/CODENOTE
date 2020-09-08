void setZeroes(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    bool row = false,col = false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==0)
            {
                if(i==0)
                    row = true;
                if(j==0)
                    col = true;
                
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(!A[i][0] || !A[0][j])
                A[i][j] = 0;
        }
    }
    if(row)
        for(int i=0;i<m;i++)
            A[0][i] = 0;
    
    if(col)
        for(int i=0;i<n;i++)
            A[i][0] = 0;
    
}
