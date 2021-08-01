TreeNode* func(vector<int>& nums,int start,int end)
{
    if(start>end)
        return NULL;
    int mid = (start+end)/2;
    TreeNode* tmp = new TreeNode(nums[mid]);
    tmp->left = func(nums,start,mid-1);
    tmp->right = func(nums,mid+1,end);
    return tmp;
}
TreeNode* sortedArrayToBST(vector<int>& nums) 
{
    int n = nums.size();
    return func(nums,0,n-1);
}