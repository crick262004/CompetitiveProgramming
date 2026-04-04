# REVERSE LL


*// Function to reverse a linked list*
*// using the 3-pointer approach*
Node* reverseLinkedList(Node *head)
{
   *// Initialize'temp' at*
   *// head of linked list*
   Node* temp = head;  
   
   *// Initialize pointer 'prev' to NULL,*
   *// representing the previous node*
   Node* prev = NULL;  
   
   *// Traverse the list, continue till*
   *// 'temp' reaches the end (NULL)*
   while(temp != NULL){  
       *// Store the next node in*
       *// 'front' to preserve the reference*
       Node* front = temp->next;  
       
       *// Reverse the direction of the*
       *// current node's 'next' pointer*
       *// to point to 'prev'*
       temp->next = prev;  
       
        *// Move 'prev' to the current*
        *// node for the next iteration*
       prev = temp;  
       
        *// Move 'temp' to the 'front' node*
        *// advancing the traversal*
       temp = front; 
   }
   
   *// Return the new head of*
   *// the reversed linked list*
   return prev;  
}

 <span style="font-size: 24.0;">
     **[Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)**
 </span>

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k == 1 || head == NULL || head->next == NULL)
        return head;
    
    ListNode* dummy = new ListNode(-1, head);
    ListNode* t1 = dummy;
    ListNode* t2 = dummy;
    int cnt = 0;


    while(t2 != NULL)
    {
        if(cnt == k)
        {
            // the reversing part.
            ListNode* first = t1 ->next;
            ListNode* prev = t1->next;
            ListNode* temp = prev->next;
            ListNode* nxt = temp->next;

            for(int i = 2; i<=k; i++)
            {
                nxt = temp->next;
                temp->next = prev;
                prev = temp;
                temp = nxt;
            }

            t1->next = prev;
            first->next = nxt;
            t1 = first;
            t2 = first;
            cnt = 0;
        }
        t2 = t2->next;
        cnt++;
    }
    return dummy->next;
}
