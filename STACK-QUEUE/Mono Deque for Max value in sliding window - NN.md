# Mono Deque for Max value in sliding window : NN


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        // optimal. O(N)
        // MONOTONICALLY DECREASING DEQUE.
        // the deque is basically : a monotonically decreasing stack from the back and we also use pop_front when an element is too old(it was from more than k indexes ago).
        deque < int > dq; // just store indexes.
        for(int i = 0; i<n; i++)
        {
            if( !dq.empty() && dq.front() == i - k )
                dq.pop_front();
            while(!dq.empty() && nums[i] >= nums[dq.back()]  )
                dq.pop_back();
            
            dq.push_back(i);
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
