ListNode* solve(ListNode* A) {
    ListNode *s=A,*f=A;
    
    while(s && f && f->next)
    {
        s = s->next;
        f = f->next->next;
        if(s==f)
            break;
    }
    
    if(s != f)
        return NULL;
    
    f = A;
    while(s->next!=f->next)
    {
        s = s->next;
        f = f->next;
    }
    s->next = NULL;
    return A;
}