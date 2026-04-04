# Longest Subarray with given Sum/XOR K(Positives only)


 <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     # int getLongestSubarray(vector<int>& a, long long k) {

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #     int n = a.size(); 
 </span> <span style="font-size: 16.0;text-align: left;">
     *// size of the array.*
 </span>
 <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     # 

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #     int left = 0, right = 0; 
 </span> <span style="font-size: 16.0;text-align: left;">
     *// 2 pointers*
 </span>
 <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #     long long sum = a[0];

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #     int maxLen = 0;

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #     while (right < n) {

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #         
 </span> <span style="font-size: 16.0;text-align: left;">
     *// if sum > k, reduce the subarray from left*
 </span>
 <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #         
 </span> <span style="font-size: 16.0;text-align: left;">
     *// until sum becomes less or equal to k:*
 </span>
 <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #         while (left <= right && sum > k) {

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #             sum -= a[left];

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #             left++;

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #         }

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     # 

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #         
 </span> <span style="font-size: 16.0;text-align: left;">
     *// if sum = k, update the maxLen i.e. answer:*
 </span>
 <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #         if (sum == k) {

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #             maxLen = max(maxLen, right - left + 1);

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #         }

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     # 

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #         
 </span> <span style="font-size: 16.0;text-align: left;">
     *// Move forward thw right pointer:*
 </span>
 <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #         right++;

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #         if (right < n) sum += a[right];

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #     }

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     # 

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     #     return maxLen;

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 16.0;text-align: left;">
     # }
 </span>