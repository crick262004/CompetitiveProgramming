// String to Integer (atoi) : doesn’t stoi or stoll do this?
// https://leetcode.com/problems/string-to-integer-atoi/
// doesn’t stoi or stoll do this?

#include <string>
#include <climits>
using namespace std;

int myAtoi(string s) {
    int n = s.length();
    int i = 0;
    int ans = 0;
    bool neg = false;
    
    // Ignore leading whitespaces
    while (i < n && s[i] == ' ') {
        i++;
    }
    
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        neg = (s[i] == '-');
        i++;
    }
    
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        int dig = s[i] - '0';
        
        if (!neg) {
            // Check for positive overflow
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && dig > 7)) {
                return INT_MAX;
            }
        } else {
            // Check for negative overflow (compare absolute values)
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && dig > 8)) {
                return INT_MIN;
            }
        }
        
        ans = ans * 10 + dig;
        i++;
    }
    
    if (neg) {
        return -ans;
    } else {
        return ans;
    }
}
