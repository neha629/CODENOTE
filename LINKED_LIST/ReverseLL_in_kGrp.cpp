ListNode* reverseList(ListNode* head, int B) {
    ListNode *curr = head,*prev = NULL,*next = NULL;
    int cnt = 0;
    while(curr && cnt<B)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    if(next!=NULL)
        head->next = reverseList(next,B);
    return prev;
}
