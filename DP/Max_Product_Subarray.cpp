int maxProduct(const vector<int> &A) {
    int n = A.size();
    int minval = A[0];
    int maxval = A[0];
    int maxpro = A[0];
    
    for(int i=1;i<n;i++)
    {
        if(A[i]<0)
            swap(minval,maxval);
        
        minval = min(A[i],A[i]*minval);
        maxval = max(A[i],A[i]*maxval);
        
        maxpro = max(maxpro,maxval);
    }
    return maxpro;
}
