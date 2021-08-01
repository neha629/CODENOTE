ListNode* merge2Lists(ListNode *r1,ListNode *r2)
{
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    while(r1 && r2)
    {
        if(r1->val<=r2->val)
        {
            temp->next = r1;
            r1 = r1->next;
        }
        else
        {
            temp->next = r2;
            r2 = r2->next;
        }
        temp = temp->next;
    }
    if(r1)
        temp->next = r1;
    
    if(r2)
        temp->next = r2;
    
    return head->next;
}
ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    int n = lists.size();
    if(n==0)
        return NULL;
    ListNode *head = lists[0];
    
    for(int i=1;i<n;i++)
        head = merge2Lists(head,lists[i]);
        
    return head;
}


struct compare
{
    bool operator()(ListNode* r1, ListNode* r2)
    {
        return (r1->val>r2->val);
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    int k = lists.size();
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    priority_queue<ListNode*,vector<ListNode*>,compare> q;
    for(int i=0;i<k;i++)
        if(lists[i])
            q.push(lists[i]);
    if(q.empty())
        return NULL;
    while(!q.empty())
    {
        ListNode *curr = q.top();
        q.pop();
        
        if(curr->next)
            q.push(curr->next);
        
        temp->next = curr;
        temp = temp->next;
    }
    return head->next;
}