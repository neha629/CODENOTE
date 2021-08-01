int matSearch (vector <vector <int>> &arr, int n, int m, int x)
{
    int i=0,j=m-1;
    while(i<n && j>=0)
    {
        if(arr[i][j]==x)
            return 1;
        else if(arr[i][j]>x)
            j--;
        else
            i++;
    }
    return 0;
}