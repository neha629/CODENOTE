//ITERATIVE INORDER TRAVERSAL

vector<int> inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> s;
    TreeNode *root = A;
    
    while(true)
    {
        if(root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            if(s.empty())
                break;
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
    }
    return ans;
}

//ITERATIVE POSTORDER TRAVERSAL

vector<int> postorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> s;
    s.push(A);
    while(!s.empty())
    {
        TreeNode *curr = s.top();
        s.pop();
        ans.push_back(curr->val);
        if(curr->left)
            s.push(curr->left);
        if(curr->right)
            s.push(curr->right);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

//ITERATIVE PREORDER TRAVERSAL

vector<int> preorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> s;
    s.push(A);
    while(!s.empty())
    {
        TreeNode* curr = s.top();
        s.pop();
        ans.push_back(curr->val);
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
    return ans;
}