TreeNode* func(TreeNode* root,int &k)
{
    if(root==NULL)
        return NULL;
    
    TreeNode* left = func(root->left,k);
    if(left!=NULL)
        return left;
    
    k--;
    if(k==0)
        return root;
    
    return func(root->right,k);
}

int kthsmallest(TreeNode* A, int B) {
    return func(A,B)->val;
}