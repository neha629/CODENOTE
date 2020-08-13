//ROTATE MATRIX BY 90 DEGREE CLOCKWISE
void rotate(vector<vector<int> > &A) {
    int n = A.size();
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            int temp = A[i][j];
            A[i][j] = A[n-1-j][i];
            A[n-1-j][i] = A[n-1-i][n-1-j];
            A[n-1-i][n-1-j] = A[j][n-1-i];
            A[j][n-1-i] = temp;
        }
    }
}

void rotate(vector<vector<int> > &A) {
    int n = A.size();
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            swap(A[i][j],A[j][i]);
            
    for(int i=0;i<n;i++)
        for(int j=0;j<n/2;j++)
            swap(A[i][j],A[i][n-1-j]);
            
}
