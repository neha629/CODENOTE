ListNode* reverseList(ListNode* A) {
    ListNode *curr = A,*temp = NULL,*next = NULL;
    while(curr)
    {
        next = curr->next;
        curr->next = temp;
        temp = curr;
        curr = next;
    }
    return temp;
}

node* reverse(node *head)
{
	if(head==NULL || head->next==NULL)
		return head;
	node *rest = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}