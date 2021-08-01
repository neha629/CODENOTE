int minIndex(int arr[], int n) 
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

int bs(int arr[],int s,int e,int key)
{
	while(s<=e)
	{
		int mid = (s+e)/2;
		if(arr[mid] == key)
			return mid;
		if(arr[mid]<key)
			s = mid+1;
		else
			e = mid-1;
	}
	return -1;
}

int searchRotatedArray(int arr[],int n,int k)
{
    int minin = minIndex(arr,n);
    if(minin==0)
        return bs(arr,0,n-1,k);
    else if(arr[minin]==k)
        return minin;
    else if(arr[0]>k)
        return bs(arr,minin+1,n-1,k);
    else
        return bs(arr,0,minin-1,k);
}