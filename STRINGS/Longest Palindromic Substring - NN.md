# Longest Palindromic Substring : NN

 <span style="font-size: 18.0;">
     **[Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)**
 </span> <span style="font-size: 18.0;">
      **: NN**

 </span>
 <span style="font-size: 18.0;">
     string longestPalindrome(string s) {
    // /*
    // 2 loops
    // 1 for odd
    // 1 for even
    // have a global result variable
    // */
    // int n = s.length();
    // string res_str = s.substr(0,1);

    // for (int i = 0; i< n - 1; i++)
    // {
    //     string odd = fn(i, i,s, n);
    //     string even = fn(i, i + 1, s , n);
    //     if(odd.length() > res_str.length())
    //         res_str = odd;
    //     if(even.length() > res_str.length())
    //         res_str = even;
    // }
    // return res_str;


    // now the DP APPROACH.
    // dp[i][j] is palindromic substring possible from i to j.
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool> (n, false));
    int l = 0;
    int r = 0;
    for(int i = 0; i<n-1; i++)
        dp[i][i] = true;
    for(int len = 2; len <= n; len++)
    {
        for(int i = 0; i<= n - len; i++)
        {
            int j = i + len - 1;
            if(s[i] == s[j] && ( dp[i+1][j-1] || j == i + 1) )
            {
                l = i; 
                r = j;
                dp[i][j] = true;
            }
        }
    }
    return s.substr(l, r-l+1);
}
// string fn(int left, int right, string s, int n){
// int l = left;
// int r = right;
// while(r < n && l >=0 && s[l] == s[r])
// {
//     r++;
//     l--;
// }
// return s.substr(l + 1, r - l - 1);
// };

 </span>
