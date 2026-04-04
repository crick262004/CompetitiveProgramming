# LL TEMPLATE:


class Node {
public:
    int data;
    Node* next;

    *// Constructor with both data and next node*
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    *// Constructor with only data (assuming next is initially null)*
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

*// Function to print the linked list*
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

*// Function to insert a new node at the head of the linked list*
Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}

*// Function to delete the tail node of a linked list and return the new head*
Node* deleteTail(Node* head) {
    *// If the list is empty or has only one node, return NULL*
    if (head == NULL || head->next == NULL)
        return NULL;
    *// Initialize a temporary pointer to traverse the list*
    Node* temp = head;
    *// Traverse to the second last node in the list*
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    *// Delete the last node*
    delete temp->next;
    *// Set the next of the second last node to nullptr, effectively removing the last node*
    temp->next = nullptr;
    *// Return the head of the modified list*
    return head;
}

*// Function to calculate the length of a linked list*
int lengthOfLinkedList(Node* head) {
    Node* temp = head;
    int cnt = 0;
    *// Traverse the linked list and count nodes*
    while (temp != NULL) {
        temp = temp->next;
        cnt++; *// increment cnt for every node traversed*
    }
    return cnt;
}

*// Function to check if a given element is present in the linked list*
int checkifPresent(Node* head, int desiredElement) {
    Node* temp = head;

    *// Traverse the linked list*
    while (temp != nullptr) {
        *// Check if the current node's data is equal to the desired element*
        if (temp->data == desiredElement)
            return 1;  *// Return 1 if the element is found*

        *// Move to the next node*
        temp = temp->next;
    }

    return 0;  *// Return 0 if the element is not found in the linked list*
}


*// Function to delete the Nth node*
*// from the end of the linked list*
Node* DeleteNthNodefromEnd(Node* head, int N) {
    *// Create two pointers, fastp and slowp*
    Node* fastp = head;
    Node* slowp = head;

    *// Move the fastp pointer N nodes ahead*
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    *// If fastp becomes NULL,*
    *// the Nth node from the end is the head*
    if (fastp == NULL)
        return head->next;

    *// Move both pointers until fastp reaches the end*
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    *// Delete the Nth node from the end*
    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}
