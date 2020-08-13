string solve(string A) {

    //Remove whitespaces
    stringstream str(A);
    string word;
    A = "";
    
    while(str>>word)
    {
        A+=word;
        A+=" ";
    }
    A.pop_back();

    //Reverse
    int n = A.length(),i,j,s = 0;
    for(i=0;i<n;i++)
    {
        if(A[i]==' ')
        {
            j = i-1;
            while(s<j)
                swap(A[s++],A[j--]);
            s = i+1;
        }
    }
    j = n-1;
    while(s<j)
        swap(A[s++],A[j--]);
    i = 0, j = n-1;
    while(i<j)
        swap(A[i++],A[j--]);
    return A;
}