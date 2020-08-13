void merge(int a[],int b[],int n,int m)
{
    for(int i=m-1;i>=0;i--)
    {
        int last =a[n-1],j;
        for(j=n-2;j>=0 && b[i]<a[j];j--)
            a[j+1] = a[j];
        
        if(j!=n-2 || last>b[i])
        {
            a[j+1] = b[i];
            b[i] = last;
        }
    }
}