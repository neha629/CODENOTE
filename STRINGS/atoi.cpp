int atoi(const string A) {
    int n = A.length();
    int x = 0,i = 0,f = 0;
    while(A[i]==' ')
        i++;
    if(A[i]=='-')
    {
       f = 1;
       i++;
    }
    if(A[i]=='+')
       i++;
    
    while(i<n)
    {
        int num = A[i] - '0';
        if(num<0 || num>9)
            break;
        if(x>=INT_MAX/10)
        {
            if(f)
                return INT_MIN;
            return INT_MAX;
        }
        x = x*10 + num;
        i++;
    }
    if(f)
        x = -x;
    return x;
}