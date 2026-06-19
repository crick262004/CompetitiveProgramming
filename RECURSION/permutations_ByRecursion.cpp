// THE BACK-TRACKING RECURSIVE STANDARD SOLUTION USING A FREQ ARRAY.
// (NEW TYPE OF RECURSION). 


// THE BACKTRACKING SOLUTION USING INDEX ONLY.
// WE USE THE STANDARD INDEX METHOD. BUT SMART THINKING ON HOW TO CREATE PERMUTATIONS.
// WE CHANGE THE NUMS ARRAY BY SWAPPING, CALL fn on INDEX + 1
// AND SWAP BACK DURING BACKTRACK.

class Solution {
public:
    void dfs(int index, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            dfs( index + 1, nums, ans);
            swap(nums[i], nums[index]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(0, nums, ans);
        return ans;
    }
};
