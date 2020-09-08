void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL)
        return;
    
    while(root)
    {
        if(root->key == key)
        {
            if(root->right)
            {
                suc = root->right;
                while(suc->left)
                    suc = suc->left;
            }
            if(root->left)
            {
                pre = root->left;
                while(pre->right)
                    pre = pre->right;
            }
            return;
        }
        else if(root->key < key)
        {
            pre = root;
            root = root->right;
        }
        else
        {
            suc = root;
            root = root->left;
        }
    }
}