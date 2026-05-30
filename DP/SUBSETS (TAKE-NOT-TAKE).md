# SUBSETS (TAKE/NOT-TAKE)


 <span style="font-size: 32.0;">
     # **SUBSETS SUM = TARGET**

 </span> <span style="font-size: 27.0;">
     **(take / not-take recursion problems ka DP template) 
(BASICALLY, ANY PROBLEM ON SUBSETS / SUBSEQUENCES)
Also has the Knapsack problems since those are also Take/Not-take.**

 </span>![B950F11C-1E92-4D8B-AD0A-2D5C0F7F23D4](images/B950F11C-1E92-4D8B-AD0A-2D5C0F7F23D4.png)

 <span style="font-size: 27.0;">
     **PROPER TABULATION:**
 </span>
![E23D42E3-1C8B-4495-8904-875E61B89F3D](images/E23D42E3-1C8B-4495-8904-875E61B89F3D.png)
 <span style="font-size: 27.0;">
     
**TABULATION SPACE OPTIMISED:**
 </span>
![A9FA3AF5-A868-45DA-91D8-D16514EB5935](images/A9FA3AF5-A868-45DA-91D8-D16514EB5935.png)

 <span style="font-size: 27.0;">
     **COUNTING VARIATION:**
 </span>
![5FC0BFF8-23A9-47F9-82FA-89C83B24730C](images/5FC0BFF8-23A9-47F9-82FA-89C83B24730C.png)
class Solution {
  public:
    int perfectSum(vector<int>& nums, int target) {
        // code here
        int n = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < n; i++)
        {
            vector<int> temp(dp); // not take case handled
            for(int t = nums[i]; t<=target; t++)
            {
                temp[t] += dp[t-nums[i]];
            }
            dp = temp;
        }
        return dp[target];
    }
};



 <span style="font-size: 32.0;">
     # **UNDERLYING RECURSION**

 </span>*// Function to check if there is a subset of 'arr' with a sum equal to 'target'*
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    *// If the target sum is 0, we have found a subset*
    **if (target == 0)
        return true;**

    *// If we have reached the first element in 'arr'*
    if (ind == 0)
        return arr[0] == target;

    *// If the result for this subproblem has already been computed, return it*
    if (dp[ind][target] != -1)
        return dp[ind][target];

    *// Try not taking the current element into the subset*
    **bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);**

    *// Try taking the current element into the subset if it doesn't exceed the target*
    **bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);**

    *// Store the result in the dp array to avoid recomputation*
    **return dp[ind][target] = notTaken || taken;**
}

*// Function to check if there is a subset of 'arr' with a sum equal to 'k'*
bool subsetSumToK(int n, int k, vector<int>& arr) {
    *// Initialize a 2D DP array for memoization*
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    *// Call the recursive subsetSumUtil function*
    return subsetSumUtil(n - 1, k, arr, dp);
}

 <span style="font-size: 32.0;">
     # **EXAMPLE OF INF SUPPLY:**
 </span>
![66B56FCB-BC22-4BA6-92DB-2403CFC1604C](images/66B56FCB-BC22-4BA6-92DB-2403CFC1604C.png)
class Solution {
public:
    // int util(int amount, int index, vector<int>& coins,vector<vector<int>>& dp )
    // {
    //     if(index == coins.size() -1 )
    //         return (dp[index][amount] = int(amount % coins[index] == 0) );
    //     if(amount < 0 )
    //         return 0;
    //     if(amount == 0)
    //         return 1;
    //     if(dp[index][amount] != -1)
    //         return dp[index][amount];
    //     return dp[index][amount] = util(amount - coins[index], index, coins, dp) + util(amount, index + 1, coins, dp);
    // }
    int change(int amount, vector<int>& coins) {
        // standard solution. same as find number of subsequences with sum = k.
        // but the difference is that this problem is based on take/not-take with infinite supply. 
        //slight change in recursion :take case mei we dont increment the index
        // change in bottom-up : when we come to a new index(hence a new value) , we take it as many times as possible(for each multiple we make the dp true / add to dp counter). So, we just need to let dp[i][t] look at dp[i][t - nums[i]] instead of making sure it looks at dp[i-1][t - nums[i]]. and if space optimised : no need for a temp vector. Let dp[t] look at dp[t-nums[i]]

        **int n = coins.size();
        vector<double> dp(amount + 1, 0);
        for(int t = 0; t<= amount; t++)
            dp[t] = (t % coins[0] == 0);
        for(int i = 1; i<n; i++){
            for(int t = coins[i]; t<= amount; t++){
                dp[t] = dp[t] + dp[t - coins[i]];
            }
        }
        return dp[amount];**

        // vector<long> prev(amount +1, 0), cur(amount +1, 0);
        // for(int i = 0; i<amount +1; i++){
        //     prev[i] = (i % coins[0] == 0);
        // }

        // for( int i = 1; i<n; i++)
        // {
        //     for(int a = 0; a <= amount ; a++)
        //     {
        //         long long nottake = prev[a];
        //         long long take = 0;
        //         if(a >= coins[i])
        //             take = cur[a - coins[i]];
        //         cur[a] = take + nottake;
        //     }
        //     prev = cur;
        // }
        // return prev[amount];
    }
};

 <span style="font-size: 32.0;">
     # **UNBOUNDED KNAPSACK(ANOTHER EXAMPLE OF INF SUPPLY)**
 </span>
![E7EE5CDC-2436-4A26-9DEA-9017FF13B6B3](images/E7EE5CDC-2436-4A26-9DEA-9017FF13B6B3.png)
 <span style="font-size: 32.0;">
     # 

 </span> <span style="font-size: 32.0;">
     # **BOUNDED KNAPSACK:**

 </span>int knapSack(int capacity, vector<int> *&*val, vector<int> *&*wt) {
    vector<int> dp(capacity + 1, 0);
    int n = wt.size();
    for(int t = wt[0]; t<= capacity; t++)
        dp[t] = val[0];
    for(int i = 1; i<n; i++){
        for(int t = capacity; t>= wt[i]; t--){
            dp[t] = max(dp[t], dp[t - wt[i]] + val[i]);
        }
    }
    return dp[capacity];
}
![E08A7262-B76E-402D-99D8-C87B55FA6886](images/E08A7262-B76E-402D-99D8-C87B55FA6886.png)




 <span style="font-size: 32.0;">
     # **Subset Sum, retrieving a valid subset:**
 </span>
    *vi* first(70000+1, -1);
    bitset<70000+1> dp;
    dp[0] = 1;
    f(i,n){
        int val = temp[i].ff;
        bitset<70000+1> ndp;
        ndp = dp | (dp<<val);
        bitset<70000+1> mask = ndp ^ dp;
        for(int j = mask._Find_first(); j<mask.size(); j= mask._Find_next(j)){
            first[j] = i;
        }
        dp = ndp;
    }

