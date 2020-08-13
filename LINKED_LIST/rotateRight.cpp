ListNode* rotateRight(ListNode* A, int B) {
    ListNode *s = A , *temp;
    int n = 0;
    while(s)
    {
        n++;
        s =s->next;
    }
    
    B = B%n;
    s = A;
    
    while(B-- && s)
       s = s->next; 
    
    temp = A;
    
    while(s->next)
    {
        temp = temp->next;
        s = s->next;
    }
        
    s->next = A;
    A = temp->next;
    temp->next = NULL;
    return A;
}