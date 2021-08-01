vector <int> max_of_subarrays(int *arr, int n, int k)
{
  deque<int> q;
  vector<int> ans;
  int i;
  for(i=0;i<k;i++)
  {
    while(!q.empty() && arr[q.back()]<arr[i])
    {
        q.pop_back();
    }
        q.push_back(i);
  }
                
  for(;i<n;i++)
  {
    if(!q.empty())
      ans.push_back(arr[q.front()]);
    while(!q.empty() && q.front()<(i-k+1))
    {
      q.pop_front();
    }
    while(!q.empty() && arr[q.back()]<arr[i])
    {
      q.pop_back();
    }
    q.push_back(i);
  }
  if(!q.empty())
    ans.push_back(arr[q.front()]);
  return ans;
}