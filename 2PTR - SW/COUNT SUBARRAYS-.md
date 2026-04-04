# COUNT SUBARRAYS:

Given an integer array nums and an integer k, return *the number of* ***good subarrays*** *of* nums.
A **good array** is an array where the number of different integers in that array is exactly k.
* For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A **subarray** is a **contiguous** part of an array.

class Solution {
public:
    int util(vector<int>& nums, int k)
    {
        if(k < 0)
            return 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        int l = 0;
        int ans = 0;
        for(int r = 0; r<n; r++)
        {
            mp[nums[r]]++;
            while(mp.size() > k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // since asked, "exactly k distincts"
        // use the less than equal to k method.
        return util(nums, k) - util(nums, k-1);
    }
};





 <span style="font-size: 29.0;">
     **[ Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)**
 </span>

class Solution {
public:
    int numberOfSubstrings(string s) {
        // my sliding window solution:

        // int l = 0;
        // int n = s.length();
        // int ans = 0;
        // map<char, int> mp;
        // for(int r= 0; r<n; r++)
        // {
        //     mp[s[r]]++;
        //     while(mp.size() == 3)
        //     {
        //         ans += n-r; // this is the new feature.
        //         if(mp[s[l]] == 1)
        //             mp.erase(s[l]);
        //         else
        //             mp[s[l]]--;
        //         l++;
        //     }
        // }
        // return ans;

        // striver's slightly better solution:
        int ans = 0;
        vector<int> mp(3, -1); // stores the last time we saw this element, 
        // the greater the index, the better, because that means that the no. of substrings that we could include when adding to answer will be maximum (because it is used to find the smallest window ending at i/r that is valid)
        int n= s.length();

        for(int i = 0; i<n; i++)
        {
            mp[s[i]- 'a'] = i;

            // instead of calc no. of valid substrings that start from l to the end, 
            // we have used the optimisation of looking at the no. of valid substrings that end at i (or r).
            ans += min({mp[0],mp[1], mp[2]}) + 1;
        }
        return ans;
    }
};
