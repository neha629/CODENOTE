// IDENTICAL TREE
int isSameTree(TreeNode* A, TreeNode* B) {
    if(A==NULL && B==NULL)
        return 1;
    if(A==NULL || B==NULL)
        return 0;
    if(A->val != B->val)
        return 0;
    return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
}

// SYMMETRIC TREE
int func(TreeNode* A, TreeNode* B)
{
    if(A==NULL && B==NULL)
        return 1;
    if(A==NULL || B==NULL)
        return 0;
    if(A->val!=B->val)
        return 0;
    return func(A->left,B->right) && func(A->right,B->left);
}

int isSymmetric(TreeNode* A) {
    return func(A,A);
}