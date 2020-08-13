void deleteNode(ListNode* node) {
        if(node == NULL)
            return;
        while(node->next->next)
        { 
            node->val=node->next->val;
            node = node->next;            
        }
         node->val=node->next->val;
        node->next=NULL;
    }