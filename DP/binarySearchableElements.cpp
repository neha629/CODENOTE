// https://community.topcoder.com/stat?c=problem_statement&pm=5869&rd=8078
// Given an unsorted array of n distinct integers, return the number of elements that are binary searchable.
// An element is said to be binary searchable if, regardless of how the pivot is chosen the algorithm returns true.
int binarySearchable(int arr[],int n)
{
    int lmax[n],rmin[n],cnt=0;
    lmax[0] = 0;
    rmin[n-1] = INT_MAX;
    
    for(int i=1;i<n;i++)
        lmax[i] = max(arr[i-1],lmax[i-1]);
    
    for(int i=n-2;i>=0;i--)
        rmin[i] = min(arr[i+1],rmin[i+1]);
        
    for(int i=0;i<n;i++)
    {
        if(arr[i]>lmax[i] && arr[i]<rmin[i])
            cnt++;
    }
    
    return cnt;
}