long long merge(int arr[],int s,int mid,int e)
{
    int temp[e-s+1],i = s,j = mid+1,k = 0;
    long long inv_cnt = 0;
    
    while(i<=mid && j<=e)
    {
        if(arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_cnt += (mid-i+1);
        }
    }
    
    while(i<=mid)
        temp[k++] = arr[i++]; 
    
    while(j<=e)
        temp[k++] = arr[j++]; 
    
    for(int x=0;x<k;x++)
        arr[s++] = temp[x];
    
    return inv_cnt;
}
long long mergeSort(int arr[],int s,int e)
{
    long long inv_cnt = 0;
    if(s<e)
    {
        int mid = (s+e)/2;
        inv_cnt += mergeSort(arr,s,mid);
        inv_cnt += mergeSort(arr,mid+1,e);
        inv_cnt += merge(arr,s,mid,e);
    }
    return inv_cnt;
}