# Min XOR Problem: https://codeforces.com/contest/2045/problem/J

# Min XOR Problem:
# **[https://codeforces.com/contest/2045/problem/J](https://codeforces.com/contest/2045/problem/J)**


struct *Node* {
    *Node** child[2]; *// child[0] for bit 0, child[1] for bit 1*
    int count;      *// How many numbers passed through this node*

    Node() {
        child[0] = child[1] = nullptr;
        count = 0;
    }
};
*// Returns count of numbers in Trie such that (number ^ val) <= limit*
long long query(*Node** root, int val, int limit) {
    long long ans = 0;
    *Node** curr = root;
    
    *// Iterate from Most Significant Bit (e.g., 29) down to 0*
    for (int i = 29; i >= 0; i--) {
        if (curr == nullptr) break;

        int b = (val >> i) & 1;      *// Current bit of X_i*
        int k_bit = (limit >> i) & 1;*// Current bit of K (limit)*

        if (k_bit == 1) {
            *// Case 1: Limit is 1.*
            *// If we make XOR = 0 (by going to child[b]),* 
            *// the result is strictly smaller than limit. Take all.*
            if (curr->child[b] != nullptr) {
                ans += curr->child[b]->count;
            }
            
            *// Then, try to match the 1 (by going to child[1-b])*
            *// to see if we can satisfy the equality path.*
            curr = curr->child[1 - b];
        } else {
            *// Case 0: Limit is 0.*
            *// We MUST make XOR = 0. We cannot allow XOR = 1.*
            *// So we must go to child[b].*
            curr = curr->child[b];
        }
    }
    
    *// If we successfully traversed all bits matching K exactly,*
    *// add the count of the number that matches K exactly.*
    if (curr != nullptr) {
        ans += curr->count;
    }
    
    return ans;
}

void insert(*Node** root, int val) {
    *Node** curr = root;
    *// Iterate from Most Significant Bit (29) down to 0*
    for (int i = 29; i >= 0; i--) {
        *// Extract the current bit (0 or 1)*
        int b = (val >> i) & 1;
        
        *// If the path doesn't exist, create a new node*
        if (curr->child[b] == nullptr) {
            curr->child[b] = new *Node*();
        }
        
        *// Move to the child node*
        curr = curr->child[b];
        
        *// Increment the count for this node.*
        *// This indicates one more number shares this prefix.*
        curr->count++; 
    }
}
