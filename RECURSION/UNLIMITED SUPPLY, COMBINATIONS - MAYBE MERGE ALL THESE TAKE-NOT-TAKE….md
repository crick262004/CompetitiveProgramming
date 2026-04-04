# UNLIMITED SUPPLY, COMBINATIONS : MAYBE MERGE ALL THESE TAKE/NOT-TAKE…

# UNLIMITED SUPPLY, COMBINATIONS : MAYBE MERGE ALL THESE TAKE/NOT-TAKE RECURSION PATTERNS INTO 1 FILE.
TAKE / NOT-TAKE PATTERN.

void util(vector<vector<int>>& ans, vector<int>& candidates, int index ,int n,  int target, vector<int>& cur)
{
    if(target == 0)
    {
        ans.push_back(cur);
        return;
    }
    if(index == n)
        return;
    // TAKE CASE(DONT INCR INDEX BECAUSE UNLIMITED SUPPLY OF EACH NUMBER)
    if(target >= candidates[index])
    {
        cur.push_back(candidates[index]);
        util(ans, candidates,index, n, target - candidates[index], cur);
        cur.pop_back();            
    }
    // NOT TAKE CASE
    util(ans, candidates, index+1 , n, target , cur);
    return;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    int n = candidates.size();
    vector<int> cur;
    util(ans, candidates, 0, n, target, cur);
    return ans;
}
