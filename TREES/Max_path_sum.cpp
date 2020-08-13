int func(TreeNode* root,int &res)
{
    if(root==NULL)
        return 0;
    int ls = func(root->left,res);
    int rs = func(root->right,res);
    int res_single = max(max(ls,rs)+root->val,root->val);
    int res_top = max(ls+rs+root->val,res_single);
    res = max(res,res_top);
    return res_single;
}
int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    func(root,res);
    return res;
}