# Longest RBS / Longest Valid Paranthesis Substring : Keep I don’t know…

# Longest RBS / Longest Valid Paranthesis Substring : Keep
I don’t know this method, my own method is using 2 passes, first with a stack, other pass to populate dp array. ( from CodeNCode )

// C++ program to find length of the
// longest valid substring using DP
#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the
// longest valid parentheses substring
int maxLength(string s) {

    int n = s.length();
    vector<int> dp(n, 0);
    int maxLen = 0;

    // Traverse the string
    for (int i = 1; i < n; i++) {

        // If we encounter a closing parenthesis
        if (s[i] == ')') {

            // Check if the previous character is an
            // opening parenthesis '('
            if (s[i - 1] == '(') {
                if (i >= 2) {
                    dp[i] = dp[i - 2] + 2;
                }
                else {
                    dp[i] = 2;
                }
            }

            // Check if the previous character is a
            // closing parenthesis ')' and the matching opening
            // parenthesis exists before the valid substring
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                if (i - dp[i - 1] >= 2) {
                    dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                }
                else {
                    dp[i] = dp[i - 1] + 2;
                }
            }

            // Update the maximum length
            maxLen = max(maxLen, dp[i]);
        }
    }

    return maxLen;
}

int main() {
  
    string s = ")()())";
    cout << maxLength(s) << endl;

    return 0;
}