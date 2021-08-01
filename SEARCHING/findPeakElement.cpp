int findPeakElement(vector<int>& arr) 
{
    int n = arr.size();
    if(n==1)
        return arr[0];
    int s=0,e=n-1,mid=0;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(mid>0 && mid<n-1)
        {
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
                return arr[mid];
            else if(arr[mid]<arr[mid+1])
                s = mid+1;
            else
                e = mid-1;
        }
        if(mid==0)
        {
            if(arr[0]>arr[1])
                return arr[0];
            else
                return arr[1];
        }
        if(mid==n-1)
        {
            if(arr[n-1]>arr[n-2])
                return arr[n-1];
            else
                return arr[n-2];
        }
    }
}