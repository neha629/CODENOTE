int searchNearlySorted(int arr[],int n,int key)
{
    int s=0,e=n-1,mid=0;
	while(s<=e)
	{
		mid = (s+e)/2;
		if(arr[mid]==key)
			return mid;
		if(mid>0 && arr[mid-1]==key)
		    return mid-1;
		if(mid<n-1 && arr[mid+1]==key)
		    return mid+1;
		if(arr[mid]<key)
			s = mid+2;
		else
			e = mid-2;
	}
	return -1;
}