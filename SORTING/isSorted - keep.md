# isSorted : keep

 <span style="font-size: 20.0;">
     
bool isSorted(
 </span> <span style="font-size: 20.0;">
     *vi*
 </span> <span style="font-size: 20.0;">
      nums){

 </span> <span style="font-size: 20.0;">
         *// non-decreasing*
 </span> <span style="font-size: 20.0;">
     
    int n = nums.size();
    for(int i = 0; i<n-1; i++)
    {
        if(nums[i] > nums[i+1])
            return false;
    }
    return true;
}

 </span>