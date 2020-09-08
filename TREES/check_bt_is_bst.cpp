int func(TreeNode* root,int minr,int maxr)
{
    if(root==NULL)
        return 1;
    if(root->val<=minr || root->val>=maxr)
        return 0;
    return func(root->left,minr,root->val) && func(root->right,root->val,maxr);
}

int isValidBST(TreeNode* A) {
    return func(A,INT_MIN,INT_MAX);
}