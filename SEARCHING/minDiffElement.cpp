int minDiffElement(int arr[],int n,int key)
{
    int s=0,e=n-1,mid=0;
	while(s<=e)
	{
		mid = (s+e)/2;
		if(arr[mid] == key)
			return 0;
		if(arr[mid]<key)
			s = mid+1;
		else
			e = mid-1;
	}
	return min(abs(arr[s]-key),abs(arr[e]-key));
}