int first_occurrence(int arr[],int n,int k)
{
    int s=0,e=n-1,mid=0,res=-1;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]==k)
        {
            res = mid;
            e = mid-1;
        }
        else if(arr[mid]>k)
            e = mid-1;
        else
            s = mid+1;
    }
    return res;
}

int last_occurrence(int arr[],int n,int k)
{
    int s=0,e=n-1,mid=0,res=-1;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]==k)
        {
            res = mid;
            s = mid+1;
        }
        else if(arr[mid]>k)
            e = mid-1;
        else
            s = mid+1;
    }
    return res;
}

int count(int arr[], int n, int x) 
{
    int l = first_occurrence(arr,n,x);
    int r = last_occurrence(arr,n,x);
    if(l==-1)
        return 0;
    else
        return r-l+1;
}

int count(int arr[], int n, int x) 
{
    int* l = lower_bound(arr,arr+n,x);
    if(l==arr+n || *l!=x)
        return 0;
    int* r = upper_bound(arr,arr+n,x);
    return r-l;
}