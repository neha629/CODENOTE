int findFloor(vector<long long> arr, long long n, long long x)
{
    long long s=0,e=n-1,mid=0,res=-1;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]<=x)
        {
            res = mid;
            s = mid+1;
        }
        else
            e = mid-1;
    }
    return res;
}

int findCeil(int arr[],int n,int x)
{
    int s=0,e=n-1,mid=0,res=-1;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]>=x)
        {
            res = mid;
            e = mid-1;
        }
        else
            s = mid+1;
    }
    return res;
}