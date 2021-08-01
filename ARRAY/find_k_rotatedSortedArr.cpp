int findKRotation(int arr[], int n) {
	    // code here
	    int s=0,e=n-1,mid;
	    while(s<=e)
	    {
	        mid = (s+e)/2;
	        if(arr[mid]<arr[(mid+1)%n] && arr[mid]<arr[(mid-1+n)%n])
	            break;
	        else if(arr[mid]<arr[n-1])
	            e = mid-1;
	        else
	            s = mid+1;
	    }
	    return mid;
	}