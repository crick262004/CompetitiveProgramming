# Subarray w Sum/Xor K

# 
# **Longest Subarray with given Sum K(Positives)**
**2 pointer approach**
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
# 

# **Longest Subarray with sum K | [Postives and Negatives]**
**prefix sum approach:**

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); *// size of the array.*

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        *//calculate the prefix sum till index i:*
        sum += a[i];

        *// if the sum = k, update the maxLen:*
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        *// calculate the sum of remaining part i.e. x-k:*
        int rem = sum - k;

        *//Calculate the length and update maxLen:*
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        *//Finally, update the map checking the conditions:*
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}


 <span style="font-size: 28.0;">
     **Count Subarrays w sum/XOR K**
 </span>

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); *// size of the given array.*
    map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; *// Setting 0 in the map.*
    for (int i = 0; i < n; i++) {
        *// add current element to prefix Sum:*
        preSum += arr[i];

        *// Calculate x-k:*
        int remove = preSum - k;

        *// Add the number of subarrays to be removed:*
        cnt += mpp[remove];

        *// Update the count of prefix sum*
        *// in the map.*
        mpp[preSum] += 1;
    }
    return cnt;
}

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); *//size of the given array.*
    int xr = 0;
    map<int, int> mpp; *//declaring the map.*
    mpp[xr]++; *//setting the value of 0.*
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        *// prefix XOR till index i:*
        xr = xr ^ a[i];

        *//By formula: x = xr^k:*
        int x = xr ^ k;

        *// add the occurrence of xr^k*
        *// to the count:*
        cnt += mpp[x];

        *// Insert the prefix xor till index i*
        *// into the map:*
        mpp[xr]++;
    }
    return cnt;
}

