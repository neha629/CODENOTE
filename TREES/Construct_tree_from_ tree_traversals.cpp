//CONSTRUCT TREE FROM POSTORDER AND INORDER
int postIndex;
TreeNode* buildTreeUtil(vector<int> &in, vector<int> &post,int s,int e,unordered_map<int,int> &mp)
{
    if(s>e)
        return NULL;
    int curr = post[postIndex--];
    TreeNode *temp = new TreeNode(curr);
    if(s==e)
        return temp;
    int inIndex = mp[curr];
    temp->right = buildTreeUtil(in,post,inIndex+1,e,mp);
    temp->left = buildTreeUtil(in,post,s,inIndex-1,mp);
    return temp;
}

TreeNode* buildTree(vector<int> &in, vector<int> &post) {
    int n = post.size();
    postIndex = n-1;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[in[i]] = i;
    TreeNode* root = buildTreeUtil(in,post,0,n-1,mp);
    return root;
}


//CONSTRUCT TREE FROM PREORDER AND INORDER
int preIndex = 0;
TreeNode* buildTreeUtil(vector<int> &pre, vector<int> &in,int s,int e,unordered_map<int,int> &mp)
{
    if(s>e)
        return NULL;
    int curr = pre[preIndex++];
    TreeNode *temp = new TreeNode(curr);
    if(s==e)
        return temp;
    int inIndex = mp[curr];
    temp->left = buildTreeUtil(pre,in,s,inIndex-1,mp);
    temp->right = buildTreeUtil(pre,in,inIndex+1,e,mp);
    return temp;
}

TreeNode* buildTree(vector<int> &pre, vector<int> &in) {
    int n = pre.size();
    preIndex = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[in[i]] = i;
    TreeNode* root = buildTreeUtil(pre,in,0,n-1,mp);
    return root;
}