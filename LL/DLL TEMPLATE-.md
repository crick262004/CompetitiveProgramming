# DLL TEMPLATE:


class Node {
public:
    int data;       *// Data stored in the node*
    Node* next;     *// Pointer to the next node in the list (forward direction)*
    Node* back;     *// Pointer to the previous node in the list (backward direction)*

    *// Constructor for a Node with both data, a reference to the next node, and a reference to the previous node*
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1; *// Similar to a singly linked list, but now with a 'back' pointer.*
        back = back1; *// Addition of 'back' pointer for the doubly linked list.*
    }

    *// Constructor for a Node with data, and no references to the next and previous nodes (end of the list)*
    Node(int data1) {
        data = data1;
        next = nullptr; *// Similar to a singly linked list.*
        back = nullptr; *// Addition of 'back' pointer initialization.*
    }
};

Node* convertArr2DLL(vector<int> arr) {
    *// Create the head node with the first element of the array*
    Node* head = new Node(arr[0]);
    *// Initialize 'prev' to the head node*
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        *// Create a new node with data from the array and set its 'back' pointer to the previous node*
        Node* temp = new Node(arr[i], nullptr, prev);
        *// Update the 'next' pointer of the previous node to point to the new node*
        prev->next = temp; 
         *// Move 'prev' to the newly created node for the next iteration*
        prev = temp;       
    }
    *// Return the head of the doubly linked list*
    return head;  
}

*// Function to print the elements of the doubly linked list*
void print(Node* head) {
    while (head != nullptr) {
        *// Print the data in the tail node*
        cout << head->data << " ";  
         *// Move to the next node*
        head = head->next;         
    }
}

*// Function to insert a new node with value 'k' at the end of the doubly linked list*
Node* insertAtTail(Node* head, int k) {
    *// Create a new node with data 'k'*
    Node* newNode = new Node(k);

    *// If the doubly linked list is empty, set 'head' to the new node*
    if (head == nullptr) {
        return newNode;
    }

    *// Traverse to the end of the doubly linked list*
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    *// Connect the new node to the last node in the list*
    tail->next = newNode;
    newNode->back = tail;

    return head;
}

*// Function to delete the head of the doubly linked list*
*// The functionality of this has been explained in our previous*
*// article, please refer to it.* 
Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
      *// Return NULL if the list is empty or contains only one element*
        return nullptr; 
    }

   *// Store the current head as 'prev'*
    Node* prev = head;      
     *// Move 'head' to the next node*
    head = head->next;    

 *// Set 'back' pointer of the new head to nullptr*
    head->back = nullptr;   

 *// Set 'next' pointer of 'prev' to nullptr*
    prev->next = nullptr;  

   *// Return the new head*
    return head;          
}

*// Function to delete the tail of the doubly linked list*
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
     *// If the list is empty or has only one node, return null*
        return nullptr;  
    }
    
    Node* tail = head;
    while (tail->next != nullptr) {
     *// Traverse to the last node (tail)*
        tail = tail->next; 
    }
    
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    
    *// Free memory of the deleted node*
    delete tail;  
    
    return head;
}

*// Function to reverse a doubly linked list*
*// In-place link exchange method*
Node* reverseDLL(Node* head) {
    
    *// Check if the list is empty*
    *// or has only one node*
    if (head == NULL || head->next == NULL) {
        *// No change is needed;*
        *// return the current head*
        return head; 
    }
    
     *// Initialize a pointer to*
     *// the previous node*
    Node* prev = NULL;  
    
    *// Initialize a pointer to*
    *// the current node*
    Node* current = head;   

    *// Traverse the linked list*
    while (current != NULL) {
        *// Store a reference to*
        *// the previous node*
        prev = current->back; 
        
        *// Swap the previous and*
        *// next pointers*
        current->back = current->next; 
        
        *// This step reverses the links*
        current->next = prev;          
        
        *// Move to the next node*
        *// in the original list*
        current = current->back; 
    }
    
    *// The final node in the original list*
    *// becomes the new head after reversal*
    return prev->back;
}







