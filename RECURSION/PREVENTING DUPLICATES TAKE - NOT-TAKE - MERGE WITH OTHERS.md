# PREVENTING DUPLICATES TAKE / NOT-TAKE : MERGE WITH OTHERS

# I DID IT USING THE ALTERNATIVE IMPLEMENTATION (AND DIDN’T DO THE T/N-T WAY)

 <span style="font-size: 20.0;">
     Given an integer array nums that may contain duplicates, return 
 </span> <span style="font-size: 20.0;">
     *all possible*
 </span>  <span style="font-size: 20.0;">
     *subsets (the power set)*
 </span> <span style="font-size: 20.0;">
     .The solution set 
 </span> <span style="font-size: 20.0;">
     **must not**
 </span> <span style="font-size: 20.0;">
      contain duplicate subsets. Return the solution in 
 </span> <span style="font-size: 20.0;">
     **any order**
 </span> <span style="font-size: 20.0;">
     .

 </span>
 <span style="font-size: 20.0;">
     void util(int index, vector<vector<int>>& ans,vector<int>& cur,  vector<int>& nums, int n)
{
    ans.push_back(cur);
    for(int i = index ; i<n; i++)
    {
        if(i > index && nums[i] == nums[i-1])
            continue;
        cur.push_back(nums[i]);
        util(i+1, ans, cur, nums, n);
        cur.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    vector<int> cur;
    sort(nums.begin(), nums.end());
    util(0, ans, cur, nums, n);
    return ans;
}
 </span>


# NON-UNLIMITED(SO NORMAL)
# NON DUPLICATE COMBINATIONS —— BASICALLY THE SAME THING AS ABOVE, BUT FOR SUBSET SUM CHECKING

EACH VALUE HAS FREQ[i] FREQ, AND WE CAN CHOOSE 0, 1, … FREQ[i] NUMBER OF COPIES OF THAT ITEM FOR OUR COMBINATION.

 <span style="font-size: 20.0;">
     void util(int index, vector<int> & candidates, vector<vector<int>>& ans,vector<int>& cur, int target, int n )
{
    if(target == 0)
    {
        ans.push_back(cur);
        return;
    }
    for( int i  = index; i<n; i++)
    {
        if(i != index && candidates[i] == candidates[i-1])
            continue;
        if(candidates[i] > target)
            break;
        cur.push_back(candidates[i]);
        util(i + 1, candidates, ans, cur, target - candidates[i], n);
        cur.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> cur;
    int n = candidates.size();
    util(0, candidates, ans, cur, target, n);
    return ans;
}

 </span>