int func(TreeNode* root,int sum,unordered_set<int> &s)
{
    if(root==NULL)
        return 0;
    
    if(s.find(sum-root->val)!=s.end())
        return 1;
    else
        s.insert(root->val);
    
    return func(root->left,sum,s) || func(root->right,sum,s);
}
 
int t2Sum(TreeNode* A, int B) {
    unordered_set<int> s;
    return func(A,B,s);
}