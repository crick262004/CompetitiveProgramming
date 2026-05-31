# LIS

## The Binary Search approach (optimised from $N^2$ to $N\log N$)
# Longest Strictly increasing:
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i<n; i++){
            int val = nums[i];
            int p =
            lower_bound(begin(temp), end(temp), val) - begin(temp);

            if(p == temp.size())
                temp.push_back(val);
            else{
                temp[p] = val;
            }
        }
        return temp.size();
    }
};
```
# Longest increasing & Equal:
```cpp
int lis(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    for(int i = 1; i<n; i++){
        int val = nums[i];
        int p =
        upper_bound(begin(temp), end(temp), val) - begin(temp);

        if(p == temp.size())
            temp.push_back(val);
        else{
            temp[p] = val;
        }
    }
    return temp.size();
}
```

```cpp
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++)
            ans = max(ans, dp[i]);
        return ans;
    }
```

```cpp
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i = 0; i<n; i++)
            hash[i] = i;

        vector<int> ans;
        int ansInd = 0;
        int maxi = 1;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(arr[j] < arr[i] && dp[j] >= dp[i])
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                ansInd = i;
            }
        }
        while(hash[ansInd] != ansInd)
        {
            ans.push_back(arr[ansInd]);
            ansInd = hash[ansInd];
        }
        ans.push_back(arr[ansInd]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
