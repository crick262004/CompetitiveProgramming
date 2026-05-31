# DP ON STRINGS

## LCS: Space Optimised Tabulation
```cpp
// Function to find the length of the Longest Common Subsequence (LCS)
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Current and previous rows of the DP table.
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1]) {
                cur[ind2] = 1 + prev[ind2 - 1];
            } else {
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }
        }
        prev = cur;
    }

    return prev[m];
}
```

## LCS: Tabulation
```cpp
// Function to find the length of the Longest Common Subsequence (LCS)
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1]) {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            } else {
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }

    return dp[n][m];
}
```

## LCS: Memoization
```cpp
int lcsUtil(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {
    if (ind1 < 0 || ind2 < 0) {
        return 0;
    }
    if (dp[ind1][ind2] != -1) {
        return dp[ind1][ind2];
    }

    if (s1[ind1] == s2[ind2]) {
        return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
    }
    return dp[ind1][ind2] = max(
        lcsUtil(s1, s2, ind1, ind2 - 1, dp),
        lcsUtil(s1, s2, ind1 - 1, ind2, dp)
    );
}

int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return lcsUtil(s1, s2, n - 1, m - 1, dp);
}
```

## Producing LCS-Like Strings
![CD8DAC3C-4DDB-42AA-915C-90061D7883D1](images/CD8DAC3C-4DDB-42AA-915C-90061D7883D1.png)

```cpp
class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = n;
        int j = m;
        string rev;

        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                rev += s[i - 1];
                i--;
                j--;
            } else if (dp[i][j - 1] > dp[i - 1][j]) {
                rev += t[j - 1];
                j--;
            } else {
                rev += s[i - 1];
                i--;
            }
        }

        while (i > 0) {
            rev += s[i - 1];
            i--;
        }
        while (j > 0) {
            rev += t[j - 1];
            j--;
        }

        reverse(rev.begin(), rev.end());
        return rev;
    }
};
```

## Palindrome DP Diagonal Traversal
![B08C6EFE-B620-4B6A-97F6-EE967E272AF1](images/B08C6EFE-B620-4B6A-97F6-EE967E272AF1.png)
![A9465855-8304-41AD-B6FC-E77C678ACF3C](images/A9465855-8304-41AD-B6FC-E77C678ACF3C.png)
