vector<int> inorderTraversal(TreeNode* root) 
{
    vector<int> ans;
    TreeNode *curr,*pre;
    curr = root;
    while(curr)
    {
        if(curr->left==NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while(pre->right!=NULL && pre->right!=curr)
                pre = pre->right;
            if(pre->right==NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                ans.push_back(curr->val);
                    curr = curr->right;
            }
        }
    }
    return ans;
}