# POWERSET / ALL SUBSETS : KEEP

 <span style="font-size: 22.0;">
     **TAKE / NOT-TAKE PATTERN**

 </span>
# PRINT ALL SUBSETS
void util(vector<int>& nums, vector<vector<int>>& ans, int index, int n, vector<int> &cur)
{
    // BASE CASE
    if(index == n){
        ans.push_back(cur);
        return;
    }

    // TAKE CASE
    cur.push_back(nums[index]);
    util(nums, ans, index + 1, n, cur);
    cur.pop_back();
    
    // NOT-TAKE CASE
    util(nums, ans, index + 1, n, cur);

    return;
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    vector<int> cur;
    util(nums, ans, 0, n, cur);
    return ans;
}



# SUM OF ALL SUBSETS
void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      *//element is picked*
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      *//element is not picked*
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
  }
