//METHOD - 1
Node* merge(Node* A, Node* B) {
    Node *temp = new Node(0);
    Node *head = temp;
    while(A && B)
    {
        if(A->data<=B->data)
        {
            temp->bottom = A;
            A = A->bottom; 
        }
        else
        {
            temp->bottom = B;
            B = B->bottom;
        }
        temp = temp->bottom;
    }
    if(A)
        temp->bottom = A;
    if(B)
        temp->bottom = B;
    return head->bottom;
}
Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL)
        return root;
    
    return merge(root,flatten(root->next));
}

//METHOD - 2
struct compare { 
    bool operator()(Node* a, Node* b) 
    { 
        return a->data > b->data; 
    } 
};
Node *flatten(Node *root)
{
    Node *curr = root,*head = NULL;    
    priority_queue<Node*,vector<Node*>,compare> pq;
    
    while(curr)
    {
        pq.push(curr);
        curr = curr->next;
    }
    
    while(!pq.empty())
    {
        Node *temp = pq.top();
        pq.pop();
        
        if(temp->bottom!=NULL)
            pq.push(temp->bottom);
        
        if(head==NULL)
        {
            head = temp;
            curr = temp;
        }
        else
        {
            curr->bottom = temp;
            curr = curr->bottom;
        }
    }
    
    return head;
}