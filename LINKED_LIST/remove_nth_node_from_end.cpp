ListNode* removeNthFromEnd(ListNode* A, int B) {
    ListNode *s = A,*f = A;
    while(B-- && f)
        f = f->next;
        
    if(f==NULL)
        return A->next;
    
    while(f->next)
    {
        s = s->next;
        f = f->next;
    }
    s->next=s->next->next;
    return A;
}