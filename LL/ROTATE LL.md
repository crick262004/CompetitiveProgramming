# ROTATE LL


ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    
    ListNode* temp = head;

    int len = 1;
    while(temp->next)
    {
        temp = temp->next;
        len++;
    }
    temp->next = head;

    k = k % len;
    if(k == 0)
        return head;

    int end = len - k;
    while(end--)
        temp = temp->next;

    head = temp->next;
    temp->next = NULL;
    return head;
}