RandomListNode* copyRandomList(RandomListNode* A) {
    RandomListNode *temp ,*curr=A;
    while(curr)
    {
        temp = curr->next;
        curr->next = new RandomListNode(curr->label);
        curr->next->next = temp;
        curr = temp;
    }
    curr = A;
    while(curr)
    {
        if(curr->next)
            curr->next->random = curr->random ? curr->random->next : NULL;
        
        curr = curr->next ?  curr->next->next : NULL;
    }
    curr = A;
    RandomListNode *head = A->next;
    temp = head;
    while(curr && temp)
    {
        curr->next = curr->next ? curr->next->next : NULL;
        temp->next = temp->next ? temp->next->next : NULL;
        curr = curr->next;
        temp = temp->next;
    }
    return head;
}