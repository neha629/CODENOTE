int longestConsecutive(vector<int>& nums) {
    int n = nums.size(),res=0;
    set<int> s;
    for(int i=0;i<n;i++)
        s.insert(nums[i]);
    
    for(int i=0;i<n;i++)
    {
        if(s.find(nums[i]-1)==s.end())
        {
            int j = nums[i];
            j++;
            while(s.find(j)!=s.end())
                j++;
            res = max(res,j-nums[i]);
        }
    }
    return res;
}