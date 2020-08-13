ListNode* reverse(ListNode* A)
{
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
int lPalin(ListNode* A) {
    ListNode *s = A,*f = A;
    while(f->next && f->next->next)
    {
        s = s->next;
        f = f->next->next;
    }
    f = A;
    ListNode *t = reverse(s->next);
    while(f && t)
    {
        if(t->val!=f->val)
            return 0;
        t = t->next;
        f = f->next;
    }
    return 1;
}