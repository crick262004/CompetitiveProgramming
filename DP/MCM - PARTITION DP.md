# MCM / PARTITION DP

THE 2 MAJOR POINTS:
CONSIDER THE CURRENT VALUE AS THE LAST POP.
THIS WAY, WE CAN BREAK THE SUBPROBLEM INTO THOSE 2 HALVES.(BECAUSE THE MIDDLE VALUE IS ASSUMED TO BE POPPED LAST, WE ENSURE THAT THERE WILL BE NO DEPENDENCIES BETWEEN THE 2 HALVES(AND THUS ARE INDEPENDENT)).

CREATE APPROPRIATE BUFFERS ON LEFT AND RIGHT SO THAT THE POP LAST LOGIC WORKS.


# MCM:
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int len = 2; len<n; len++){
            for(int i = 0; i<n; i++){
                int j = i + len;
                if( j >= n)
                    break;
                int mini = 1e9;
                for(int k = i+1; k<= (j-1); k++){
                    mini = min(mini, 
                    dp[i][k] + dp[k][j] + (arr[i] * arr[k] * arr[j]));
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][n-1];
    }
};


class Solution {
  public:
    // int util(vector<int> &arr, int l , int r,
    // vector<vector<int>>& dp){
    //     if(dp[l][r] != -1)
    //         return dp[l][r];
    //     if(r <= l + 1)
    //         return 0;
    //     int sum = INT_MAX;
    //     for(int i = l + 1; i<=r-1; i++)
    //     {
    //         int temp = arr[l] * arr[i] * arr[r];
    //         temp += util(arr, l , i, dp) + util(arr, i, r, dp);
            
    //         sum = min(sum, temp);
    //     }
    //     return dp[l][r] = sum;
    // }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // return util(arr , 0 , arr.size() - 1, dp);
        // for(int gap = 2; gap<= n -1; gap++)
        // {
        //     for(int l = 0; l <= n -1 - gap; l++)
        //     {
        //         int r = l + gap;
        //         int sum = INT_MAX;
        //         for(int i = l +1; i<= r-1; i++)
        //         {
        //             int temp = arr[l] * arr[i] * arr[r];
        //             temp += dp[l][i] + dp[i][r];
            
        //             sum = min(sum, temp);
        //         }
        //         dp[l][r] = sum;
        //     }
        // }
        // return dp[0][n-1];
        
        
        for(int i = n-1; i>= 0; i--)
        {
            for(int j = i + 2; j<n; j++)
            {
                int sum = INT_MAX;
                for(int k = i +1; k<= j-1; k++)
                {
                    int temp = arr[i] * arr[k] * arr[j];
                    temp += dp[i][k] + dp[k][j];
            
                    sum = min(sum, temp);
                }
                dp[i][j] = sum;
            }
        }
        return dp[0][n-1];
    }
};


# BALLOONS / PARTITION

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> a;
        a.push_back(1);
        int n = nums.size();
        for(int i = 0; i<n; i++)
            a.push_back(nums[i]);
        a.push_back(1);
        n = n + 2;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int len = 2; len<n; len++){
            for(int i = 0; i<n-1; i++){
                int j = i + len;
                if( j >= n)
                    break;
                int maxi = 0;
                for(int k = i+1; k<j; k++){
                    maxi = max(maxi, 
                    dp[i][k] + dp[k][j] + a[i] * a[k]* a[j]);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[0][n-1];
    }
};



class Solution {
public:
    // int util(vector<int>& nums, int l, int r, vector<vector<int>>& dp){
    //     if(r < l)
    //         return 0;
    //     if(dp[l][r] != -1)
    //         return dp[l][r];
    //     int sum = 0;
    //     for(int i = l; i<=r; i++){
    //         int temp = nums[l-1] * nums[i] * nums[r+1];
    //         temp += util(nums, l, i-1, dp) + util(nums, i+1, r, dp);
    //         sum = max(sum, temp);
    //     }
    //     return dp[l][r] = sum;
    // }
    int maxCoins(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(1);
        int n = nums.size();
        for(int i = 0; i<n; i++){
            temp.push_back(nums[i]);
        }
        temp.push_back(1);

        int size = temp.size(); // n + 2
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return util(temp, 1, n, dp);

        vector<vector<int>> dp(size, vector<int> (size, 0));
        // for(int gap = 2; gap<= size -1; gap++)
        // {
        //     for(int l = 0; l <= size -1 - gap; l++)
        //     {
        //         int r = l + gap;
        //         int sum = 0;
        //         for(int i = l +1; i<= r-1; i++)
        //         {
        //             int t = temp[l] * temp[i] * temp[r];
        //             t += dp[l][i] + dp[i][r];
            
        //             sum = max(sum, t);
        //         }
        //         dp[l][r] = sum;
        //     }
        // }
        // return dp[0][size-1];

        for(int i = size-3; i>= 0; i--)
        {
            for(int j = i + 2; j<size; j++)
            {
                int sum = 0;
                for(int k = i + 1; k<= j-1; k++)
                {
                    int t = temp[i] * temp[k] * temp[j];
                    t += dp[i][k] + dp[k][j];
            
                    sum = max(sum, t);
                }
                dp[i][j] = sum;
            }
        }
        return dp[0][size-1];
    }
};

# 
# FRONT PARTITION : 
# when the dp state can be just 1 parameter: 
# when we can create partitions from 1 end, while knowing that the partitions are independent. 
# 2D LR DP is required when partitions are interdependent.

int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        for(int i = 0; i<n; i++){
            int ans = INT_MIN;
            int j = i;
            int len = 1;
            int maxi = INT_MIN;
            while(len <= k && j >= 0){
                maxi = max(maxi, arr[j]);
                if( j == 0){
                    ans = max(ans, maxi * len);
                }
                else
                    ans = max(ans, maxi * len + dp[j-1]);
                j--;
                len++;
            }
            dp[i] = ans;
        }
        return dp[n-1];
    }

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> ispalindrome(n, vector<bool>(n, true));
        for(int i = n-1; i>=0; i--){
            for(int j = i + 1; j<n; j++){
                if(s[i] != s[j]){
                    ispalindrome[i][j] = false;
                }
                else{
                    ispalindrome[i][j] = ispalindrome[i+1][j-1];
                }
            }
        }
        vector<int> dp(n+1, 0);
        for(int i = n-1; i>=0; i--){
            int ans = INT_MAX;
            string str = "";
            for(int j = i; j<n;j++){
                if(ispalindrome[i][j]){
                    ans = min(ans, 1 + dp[j+1]);
                }
            }
            dp[i] = ans;
        }
        return dp[0]-1;
    }
};