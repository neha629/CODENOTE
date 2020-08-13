bool func(Node *root,int *h)
{
    int lh = 0,rh = 0;
    if(root==NULL)
    {
        *h = 0;
        return true;
    }
    bool l = func(root->left, &lh);
    bool r = func(root->right, &rh);
    
    *h = max(lh,rh) + 1;
    
    if(abs(lh-rh)>=2)
        return false;
    else
        return l && r;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    int h = 0;
    return func(root,&h);
}
