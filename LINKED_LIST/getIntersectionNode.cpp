ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    ListNode *s = A,*f = B;
    if(s==NULL || f==NULL)
            return NULL;
    while(s != f)
    {
        s = s->next;
        f = f->next;
        if(s==NULL && f==NULL)
            return NULL;
        if(s == NULL)
            s = B;
        if(f == NULL)
            f = A;
    }
    return s;
}