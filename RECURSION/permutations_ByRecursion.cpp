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


// THE NEETCODE ITERATIVE SOLUTION.
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        // initializing the very first permutations list, 
        // make sure to give it a empty permutation. Or else base case never hits.
        // remember, an empty permutation is different from no permutation.
        vector<vector<int>> ans = {{}};


        // for each new value, we create a new set of permuations
        // using the permutations made from previous values.
        for(int x : nums)
        {
            // the new set of permutations.
            vector<vector<int>> temp;

            // go through each of the old permutations. 
            // We will make new permutations from each old one.
            for(vector<int> permutation : ans)
            {
                // from each old permutation, we make a few new ones.
                // same thing as above.
                for(int i = 0; i<=permutation.size() ; i++)
                {
                    vector<int> newpermutation(permutation);

                    newpermutation.insert(newpermutation.begin() + i, x);

                    temp.push_back(newpermutation);
                }
            }
            ans = temp;
        }
        return ans;
    }
};


// other approach:
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        do{
            vector<int> tmp(nums);
            ans.push_back(tmp);
        } while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};

