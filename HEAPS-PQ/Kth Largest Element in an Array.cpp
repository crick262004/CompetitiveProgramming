// Kth Largest Element in an Array

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> 
    minheap;
public:
    int k1;
    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        for( int i = 0; i<nums.size(); i++)
        {
            minheap.push(nums[i]);
            if(i>=k)
                minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size() > k1)
            minheap.pop();
        return minheap.top();
    }
};

class Solution {
public:
    int partition(vector<int>& arr, int left, int right)
    {
        int pivot = arr[left];
        int l = left +1;
        int r = right;
        while(l<=r)
        {
            if(arr[l] < pivot && arr[r] > pivot)
            {
                swap(arr[l], arr[r]);
                l++;
                r--;
            }
            if(arr[l] >= pivot)
                l++;
            if(arr[r] <= pivot)
                r--;
        }
        swap(arr[left], arr[r]);
        return r;
    }
    int findKthLargest(vector<int>& arr, int k) {
    // Quick Select algorithm:
    // the partioning logic is the same, only difference is we don't sort the array, but just find the N-kth index / or kth index, if we keep greater elements before partition.

    int left = 0, right = arr.size() -1, kth;
    while(1)
    {
        int idx = partition(arr, left, right);
        if(idx == k-1)
        {
            kth = arr[idx];
            break;
        }
        else if(idx < k-1)
            left = idx +1;
        else
            right = idx -1;
    }

    return kth;
    }
};

        // sorting would be O(nlogn) whereas, the heap is O(klogn)

        // create a min_heap to store k largest elements
        // if ele is less than min, continue
        // if more, add to heap and push out new min value
        // OR push out min value and add this value to heap
        // return the min of the heap at the end

        // k = k % nums.size();

//         priority_queue <int, vector<int>, greater<int>> minHeap;

//         for(int i = 0; i < k; i++)
//             minHeap.push(nums[i]);

//         for( int i = k; i < nums.size(); i++)
//         {
//             if(nums[i] > minHeap.top())
//             {
//                 minHeap.pop();
//                 minHeap.push(nums[i]);
//             }
//         }
//         return minHeap.top();
//     }
// };
