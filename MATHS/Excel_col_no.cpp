int titleToNumber(string A) {
    int n = A.length();
    int res = 0;
    int p = 1;
    for(int i=n-1;i>=0;i--)
    {
        int x = A[i]-'A'+1;
        res += p*x;
        p *= 26;
    }
    return res;
}

string convertToTitle(int A) {
    string res = "";
    while(A>0)
    {
        int rem = A%26;
        A = A/26;
        if(rem==0)
        {
            res = 'Z' + res;
            A--;
        }
        else
            res = char(rem - 1 + 'A') + res;
    }
    return res;
}