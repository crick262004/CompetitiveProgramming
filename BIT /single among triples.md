# single among triples


 <span style="font-size: 18.0;">
     int singleNumber(vector<int>& nums) {
    // O(32*N) : isse achha hai ki sort hi kar lo.

    // int ans = 0;
    // int n = nums.size();

    // for(int i = 0 ;i<32; i++){
    //     int cnt = 0;

    //     for(int j= 0; j<n; j++)
    //         cnt += ( (nums[j] >> i) & 1);

    //     cnt %= 3;

    //     ans = ans | (cnt<<i);
    // }
    
    // return ans;

    // sorting solution:

    // Optimal solution:
    // striver se samjha.
    // crack-head solution:
    int ones = 0, twos = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        ones = (nums[i] ^ ones) & (~twos);
        twos = (nums[i] ^ twos) & (~ones);
    }
    return ones;
}

 </span>