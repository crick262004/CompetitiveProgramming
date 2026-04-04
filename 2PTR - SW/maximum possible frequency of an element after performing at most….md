# maximum possible frequency of an element after performing at most…

 <span style="font-size: 27.0;">
     # ***maximum possible frequency***
 </span> <span style="font-size: 27.0;">
      *of an element after performing* 
 </span> <span style="font-size: 27.0;">
     ***at most***
 </span>  <span style="font-size: 27.0;">
     **k**
 </span>  <span style="font-size: 27.0;">
     ***increments***
 </span> <span style="font-size: 27.0;">
     **.**

 </span>
int maxFrequency(vector<int>& nums, int k) {
        // 2 pointer sliding window

        sort(nums.begin(), nums.end());        
        int l = 0;
        int r = 0;

        int windowlen = 0;
        long windowsum = 0;
        while(r<nums.size())
        {
            windowsum += nums[r];
            while( (long)nums[r]*(r-l+1) > windowsum + k )
            {
                windowsum -= nums[l++];
            }
            windowlen = max(windowlen, r-l+1);
            r++;
        }
        return windowlen;
    }
