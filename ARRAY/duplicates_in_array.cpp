vector<int> duplicates(int a[], int n) {
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        a[(a[i]-1)%n] = a[(a[i]-1)%n] + n; 
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>2*n)
            ans.push_back(i+1);
    }
    if(ans.empty())
        ans.push_back(-1);
    return ans;
}

int repeatedNumber(const vector<int> &A) {
    int f = A[0], s = A[0];
    while(true)
    {
        f = A[A[f]];
        s = A[s];
        if(s==f)
            break;
    }
    f = A[0];
    while(s!=f)
    {
        f = A[f];
        s = A[s];
    }
    return s;
}