# Max Prod Subarray


    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxp = nums[0], minp = nums[0], result = nums[0];

        for( int i =1 ; i<n; i++)
        {
            int temp = max({nums[i], nums[i] * maxp, nums[i] * minp});
            minp = min({nums[i], nums[i] * maxp, nums[i] * minp});
            maxp = temp;

            result = max(maxp, result);
        }
        return result;
    }
