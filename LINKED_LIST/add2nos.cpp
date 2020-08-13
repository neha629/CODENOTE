ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *head = NULL, *temp;
    int carry = 0,base = 0;
    while(A || B)
    {
        base = (A?A->val:0)+(B?B->val:0)+carry;
        carry = (base>=10) ? 1 : 0;
        base = base%10;
        if(head ==NULL)
        {
            head = new ListNode(base);
            temp = head;
        }
        else
        {
            temp->next = new ListNode(base);
            temp = temp->next;
        }
        if(A)
            A = A->next;
        if(B)
            B = B->next;
    }
    if(carry)
    {
        temp->next = new ListNode(carry);
    }
    return head;
}