int uniquePaths(int m, int n) {
    int path = 1;
    for(int i=n;i<=(m+n-2);i++)
    {
        path*=i;
        path/=(i-n+1);
    }
    return path;
}