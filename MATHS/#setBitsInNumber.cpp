int hammingWeight(uint32_t n) 
{
    int c=0;
    // METHOD 1
    // for(int i=0;i<32;i++)
    // {
    //     if((1<<i) & n)
    //         c++;
    // }

    // METHOD 2
    while(n>0)
    {
        n = n & (n-1);
        c++;
    }
    return c;   
}