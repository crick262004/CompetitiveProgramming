# MIDDLE ELEMENT

# HARE-TORTOISE

*// Function to find the middle*
*// node of a linked list*
Node *findMiddle(Node *head) {
    
     *// Initialize the slow pointer to the head.*
    Node *slow = head; 
    
     *// Initialize the fast pointer to the head.*
    Node *fast = head; 

    *// Traverse the linked list using the*
    *// Tortoise and Hare algorithm.*
    while (fast != NULL && fast->next != NULL) {
        *// Move slow one step.*
        slow = slow->next; 
         *// Move fast two steps.*
        fast = fast->next->next; 
    }
    
    
     *// Return the slow pointer,*
     *// which is now at the middle node.*
    return slow; 
}
