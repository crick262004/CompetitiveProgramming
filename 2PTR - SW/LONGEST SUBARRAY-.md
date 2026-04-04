# LONGEST SUBARRAY:

 <span style="font-size: 17.0;">
     # 

 </span>
 <span style="font-size: 26.0;">
     **Find length of the longest subarray / substring containing atmost two/k distinct integers / characters** 


 </span> <span style="font-size: 16.0;">
     int longestSubarrayKDistinct(vector<int> &nums, int k){
    int l = 0, ans = 0, n = nums.size();
    map<int,int> f;
    for(int r = 0; r < n; r++)
    {
        // f[nums[r]]++;
        // while(f.size() > k)
        // {
        //     f[nums[l]]--;
        //     if(f[nums[l]] == 0)
        //         f.erase(nums[l]);
        //     l++;
        // }
        // ans = max(ans, r - l +1);

        // NOW, HOW STRIVER DOES IT:
        f[nums[r]]++;
        if(f.size() > k)
        {
            f[nums[l]]--;
            if(f[nums[l]] == 0)
                f.erase(nums[l]);
            l++;
        }
        if(f.size() <= k)
            ans = max(ans, r-l+1);
    }
    return ans;
}
 </span>



 <span style="font-size: 28.0;">
     # **[Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)**
 </span>
 <span style="font-size: 21.0;">
     SPECIAL CASE OF ABOVE, WHERE K = 1.

 </span> <span style="font-size: 34.0;">
     SIMPLE SW:
 </span>
int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) *// outer loop for traversing the string*
  {
    if (set.find(str[r]) != set.end()) *//if duplicate element is found*
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}

 <span style="font-size: 26.0;">
     OPTIMISED:

 </span>int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }


