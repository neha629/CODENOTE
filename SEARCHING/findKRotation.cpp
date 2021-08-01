int findKRotation(int arr[], int n) 
{
    int s=0,e=n-1,mid=0;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]<arr[(mid+1)%n] && arr[mid]<arr[(mid-1+n)%n])
            return mid;
        else if(arr[mid]>arr[n-1])
            s = mid+1;
        else
            e = mid-1;
    }
}