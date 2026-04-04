# SORT 3 values using 3 pointers : Keep


    void sortColors(vector<int>& nums) {
        int high = nums.size() -1;
        int low = 0, mid = 0;

        while(mid <= high)
        {
            int val = nums[mid];
            if(val == 2)
                swap(nums[mid], nums[high--]);
            else if(val == 0)
                swap(nums[mid++], nums[low++]);
            else
                mid++;
        }
    }
