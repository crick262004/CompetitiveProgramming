// when we know the values are bounded to a N < 1e7 (or whatever lets us maintain two linear vectors of size N) 
// and want O(1) over insert, erase, find and CLEAR
// and O(current_size) for iterate

#include <iostream>
#include <vector>

/*
idea is, desnse vector contains actual values
sparse set contains indexes to the values. So like for value x, we check sparse[x] to find the index in the dense vector, where x must be populated.
Also could call it
sparse = index vector
dense = values vector

*/

class SparseSet {
private:
    std::vector<int> dense;
    std::vector<int> sparse;
    int capacity;
    int current_size;

public:
    // Constructor: Resizes vectors to capacity N
    SparseSet(int N) : capacity(N), current_size(0) {
        dense.resize(N);
        sparse.resize(N);
    }

    // Check if x is in the set
    bool contains(int x) const {
        return sparse[x] >= 0 && sparse[x] < current_size && dense[sparse[x]] == x;
    }

    // Insert x into the set
    void insert(int x) {
        if(!contains(x)){
            dense[current_size] = x;
            sparse[x] = current_size;
            current_size++;
        }
    }

    // Remove x from the set
    void remove(int x) {
        if(contains(x)){
            int ind = sparse[x];
            std::swap(dense[current_size-1], dense[ind]); // this changes the vector itself, also deals fine if ind == current_size-1
            int lastval = dense[ind];
            sparse[lastval] = ind;
            current_size--;
        }
    }

    // Clear the set
    void clear() {
        current_size = 0;
    }

    // Iterate/Print: Already implemented for your testing
    void print() const {
        std::cout << "Set elements: ";
        for (int i = 0; i < current_size; ++i) {
            std::cout << dense[i] << " ";
        }
        std::cout << "\n";
    }
};

// Driver Code
int main() {
    SparseSet set(10);

    std::cout << "--- Testing Insertion ---\n";
    set.insert(3);
    set.insert(7);
    set.insert(1);
    set.insert(3); // Duplicate check
    set.print();   // Expected output: 3 7 1 (or similar order)

    std::cout << "\n--- Testing Lookup ---\n";
    std::cout << "Contains 7? " << (set.contains(7) ? "Yes" : "No") << " (Expected: Yes)\n";
    std::cout << "Contains 5? " << (set.contains(5) ? "Yes" : "No") << " (Expected: No)\n";

    std::cout << "\n--- Testing Removal ---\n";
    set.remove(7);
    set.print();   // Expected output: 3 1 (7 should be replaced by 1)
    std::cout << "Contains 7? " << (set.contains(7) ? "Yes" : "No") << " (Expected: No)\n";

    std::cout << "\n--- Testing Clear ---\n";
    set.clear();
    set.print();   // Expected output: Set elements: (Empty)
    std::cout << "Contains 3? " << (set.contains(3) ? "Yes" : "No") << " (Expected: No)\n";

    std::cout << "\n--- Testing Re-insertion ---\n";
    set.insert(5);
    set.print();   // Expected output: 5

    return 0;
}
