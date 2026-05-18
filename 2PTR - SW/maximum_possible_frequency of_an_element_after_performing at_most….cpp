// maximum possible frequency of an element after performing at most…

// maximum possible frequency

// of an element after performing

// at most
   
// k
   
// increments

// .

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
