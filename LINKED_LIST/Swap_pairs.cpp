node* swap_pair(node *head)
{
	if(head==NULL || head->next==NULL)
        return head;
	node *curr,*nxt,*prev=NULL;
	curr = head;
	nxt = head->next;
	head = nxt;
	while(curr && curr->next)
	{
		curr->next = nxt->next;
		nxt->next = curr;
		if(prev)
			prev->next = nxt;
		prev = curr;
		curr = curr->next;
		if(curr)
			nxt = curr->next;
	}
	return head;
}