// Encodes a tree to a single string.
string serialize(TreeNode* root) 
{
    string str = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL)
                str+="#,";
        else
        {
            str+=(to_string(temp->val)+",");
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return str;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) 
{
    TreeNode* root = NULL;
    queue<TreeNode**> q;
    q.push(&root);
    int i=0;
    while(i<data.size())
    {
        TreeNode **p = q.front();
        q.pop();
        if(data[i]=='#')
            i+=2;
        else
        {
            string temp="";
            while(data[i]!=',')
            {
                temp+=data[i];
                i++;
            }
            stringstream g(temp); 
            int val = 0; 
            g >> val; 
            i++;
            *p = new TreeNode(val);
            q.push(&((*p)->left));
            q.push(&((*p)->right));
        }
    }
    return root;
}