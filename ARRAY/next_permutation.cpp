int bsearch(vector<int> &A,int l,int r,int key)
{
    int index = -1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(A[mid]>key)
        {
            l = mid+1;
            if(index==-1 || A[index]>=A[mid])
                index = mid;
        }
        else
            r = mid-1;
    }
    return index;
}

vector<int> nextPermutation(vector<int> &A) {
    int n = A.size();
    int i = n-2;
    while(i>=0 && A[i]>=A[i+1])
        i--;
    if(i>=0)
    {
        int index = bsearch(A,i+1,n-1,A[i]);
        swap(A[i],A[index]);
    }
    reverse(A.begin()+i+1,A.end());
    return A;
}
