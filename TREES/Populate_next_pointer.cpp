/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
TreeLinkNode* getNextNode(TreeLinkNode* node)
{
    TreeLinkNode* temp = node->next;
    while(temp)
    {
        if(temp->left)
            return temp->left;
        if(temp->right)
            return temp->right;
        temp = temp->next;
    }
    return NULL;
}
 
void func(TreeLinkNode* node)
{
    if(node==NULL)
        return;
    
    node->next = NULL;
    
    TreeLinkNode* temp;
    while(node)
    {
        temp = node;
        while(temp)
        {
            if(temp->left)
            {
                if(temp->right)
                    temp->left->next = temp->right;
                else
                    temp->left->next = getNextNode(temp);
            }
            if(temp->right)
                temp->right->next = getNextNode(temp);
            
            temp = temp->next;
        }
        if(node->left)
            node = node->left;
        else if(node->right)
            node = node->right;
        else
            node = getNextNode(node);
    }
}

void connect(TreeLinkNode* A) {
    func(A);
}
