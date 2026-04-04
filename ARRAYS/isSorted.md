# isSorted


bool isSorted(*vi* nums){
    *// non-decreasing*
    int n = nums.size();
    for(int i = 0; i<n-1; i++)
    {
        if(nums[i] > nums[i+1])
            return false;
    }
    return true;
}
