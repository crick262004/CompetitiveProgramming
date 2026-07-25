#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <cassert>

class BuddyAllocator
{
private:
    size_t total_size;
    size_t min_block_size;
    int max_order;

    // free_lists[order] stores the starting offsets of free blocks at that order level
    std::vector<std::set<size_t>> free_lists;

    // Keeps track of currently allocated blocks: offset -> order
    std::map<size_t, int> allocated_blocks;

    // Helper: Calculate the order required for a given allocation size
    int get_order(size_t size) const
    {
        if (size <= min_block_size)
            return 0;
        return std::ceil(std::log2(static_cast<double>(size) / min_block_size));
    }

    // Helper: Get the exact block size for a given order
    size_t get_block_size(int order) const
    {
        return min_block_size * (1ULL << order);
    }

public:
    BuddyAllocator(size_t total_sz, size_t min_blk_sz)
        : total_size(total_sz), min_block_size(min_blk_sz)
    {

        // Enforce powers of 2 constraints
        assert((total_size & (total_size - 1)) == 0 && "Total size must be a power of 2");
        assert((min_block_size & (min_block_size - 1)) == 0 && "Min block size must be a power of 2");
        assert(total_size >= min_block_size);

        max_order = std::log2(total_size / min_block_size);
        free_lists.resize(max_order + 1);

        // Initially, the entire memory is one single free block at max_order
        free_lists[max_order].insert(0);
    }

    /**
     * Allocates a block of memory of at least the requested size.
     * * @param size The requested size in bytes.
     * @return The starting offset of the allocated block, or -1 (as size_t) if allocation fails.
     */
    size_t allocate(size_t size)
    {
        if (size == 0 || size > total_size)
            return -1;

        int target_order = get_order(size);
        for (int i = target_order; i <= max_order; i++)
        {
            if (free_lists[i].size())
            {
                int starting = *free_lists[i].begin();
                while (i > target_order)
                {
                    auto it = free_lists[i].find(starting);
                    free_lists[i].erase(it);
                    i--;
                    free_lists[i].insert(starting);
                    free_lists[i].insert(starting + get_block_size(i));
                }
                auto it = free_lists[i].find(starting);
                free_lists[i].erase(it);
                allocated_blocks[starting] = i;
                return starting;
            }
        }
        // ---------------------------------------------------------------------
        // 
        // 1. Find the smallest order 'i' (where i >= target_order) that contains a free block.
        // 2. If no block is found up to max_order, return -1 (Out of Memory).
        // 3. Remove the chosen block offset from free_lists[i].
        // 4. Split the block down if i > target_order:
        //    - For each intermediate level down to target_order, split the block in half.
        //    - The right half becomes the buddy; insert its offset into free_lists at that level.
        //    - Keep the left half to continue splitting or to finally allocate.
        // 5. Track the final allocation: record its order in the `allocated_blocks` map.
        // 6. Return the starting offset of the allocated block.
        // ---------------------------------------------------------------------

        return -1; // Placeholder
    }

    /**
     * Deallocates a previously allocated block at the given offset.
     * * @param offset The starting offset of the block to free.
     */
    void deallocate(size_t offset)
    {
        if (allocated_blocks.find(offset) != allocated_blocks.end())
        {
            int order = allocated_blocks[offset];
            allocated_blocks.erase(offset);
            for (; order < max_order; order++)
            {
                // current block is free
                size_t buddy_offset = offset ^ get_block_size(order);
                if (free_lists[order].find(buddy_offset) != free_lists[order].end())
                {
                    free_lists[order].erase(buddy_offset);
                    offset = std::min(offset, buddy_offset);
                }
                else
                {
                    break;
                }
            }
            free_lists[order].insert(offset);
        }
        // -----------------------------------------------------------------
        // 1. Check if the offset exists in `allocated_blocks`. If not, it's an invalid free; return.
        // 2. Retrieve and remove the block's order from `allocated_blocks`.
        // 3. Attempt to coalesce (merge) with its buddy up the chain:
        //    - Loop while current order < max_order:
        //        a. Calculate buddy offset: buddy_offset = offset ^ current_block_size
        //        b. Look for buddy_offset in free_lists[current_order].
        //        c. If found, buddy is free! Remove it from free_lists[current_order].
        //           Then, update `offset` to be the min(offset, buddy_offset) to represent the merged block.
        //           Increment current_order.
        //        d. If not found, the buddy is busy. Break out of the loop.
        // 4. Insert the final merged block offset back into free_lists[current_order].
        // ---------------------------------------------------------------------
    }

    // Utility function to print out the internal state of the allocator
    void print_state() const
    {
        std::cout << "\n================ ALLOCATOR STATE ================\n";
        for (int i = max_order; i >= 0; --i)
        {
            std::cout << "Order " << i << " (Size " << get_block_size(i) << "B): ";
            for (size_t offset : free_lists[i])
            {
                std::cout << "[" << offset << "] ";
            }
            std::cout << "\n";
        }
        std::cout << "Allocated Blocks (Offset -> Order): ";
        for (const auto &[offset, order] : allocated_blocks)
        {
            std::cout << "{" << offset << " : Order " << order << "} ";
        }
        std::cout << "\n=================================================\n";
    }
};

int main()
{
    // Total Size: 128 Bytes, Minimum Block Size: 16 Bytes
    // Supported orders: 0 (16B), 1 (32B), 2 (64B), 3 (128B)
    BuddyAllocator pm(128, 16);
    pm.print_state();

    std::cout << "\n--- Requesting 30 bytes (Should allocate 32 bytes, Order 1) ---";
    size_t addr1 = pm.allocate(30);
    std::cout << "\nAllocated at offset: " << addr1 << "\n";
    pm.print_state();

    std::cout << "\n--- Requesting 15 bytes (Should allocate 16 bytes, Order 0) ---";
    size_t addr2 = pm.allocate(15);
    std::cout << "\nAllocated at offset: " << addr2 << "\n";
    pm.print_state();

    std::cout << "\n-------------- Freeing first block --------------";
    pm.deallocate(addr1);
    pm.print_state();

    std::cout << "\n-------------- Freeing second block -------------";
    pm.deallocate(addr2);
    pm.print_state(); // Should return back to 1 pristine 128B block if coalescing works!

    return 0;
}
