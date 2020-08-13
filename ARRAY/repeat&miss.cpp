vector<int> repeatedNumber(const vector<int> &A) {
    int xori=0,x=0,y=0;
    for(int i=0;i<A.size();i++)
    {
        xori=xori^A[i]^(i+1);
    }
    int set_bit = xori & ~(xori-1);
    for(int i=0;i<A.size();i++)
    {
        if(A[i] & set_bit)
            x = x ^ A[i];
        else
            y = y ^ A[i];
        
        if((i+1) & set_bit)
            x = x ^ (i+1);
        else
            y = y ^ (i+1);
        
    }
    for(auto it:A)
    {
        if(it == x)
            return vector<int>{x,y};
        if(it == y)
            return vector<int>{y,x};
    }
}

