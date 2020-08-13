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