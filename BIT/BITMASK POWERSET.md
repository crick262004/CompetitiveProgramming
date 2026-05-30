
# BITMASK POWERSET

```cpp
vector<vector<int>> subsets(const vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    for (int mask = 0; mask <= (1 << n) - 1; ++mask) {
        vector<int> sub;
        for (int i = 0; i < n; ++i) {
            if (((1 << i) & mask) != 0)
                sub.push_back(nums[i]);
        }
        ans.push_back(sub);
    }
    return ans;
}
```

