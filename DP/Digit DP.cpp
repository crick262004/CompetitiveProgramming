// Digit DP

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[20][11][2][2];

ll mem(const string& s, ll cur, ll last, ll leading_zero, ll tight) {
    if (cur == 0) {
        return 1;
    }

    if (dp[cur][last + 1][leading_zero][tight] != -1) {
        return dp[cur][last + 1][leading_zero][tight];
    }

    ll limit = (tight == 1) ? (s[s.size() - cur] - '0') : 9;
    ll count_numbers = 0;

    for (int d = 0; d <= limit; d++) {
        if (d == last && leading_zero == 0) {
            continue;
        }
        ll new_lead = (leading_zero == 1 && d == 0) ? 1 : 0;
        ll new_tight = (tight == 1 && d == limit) ? 1 : 0;
        count_numbers += mem(s, cur - 1, d, new_lead, new_tight);
    }

    return dp[cur][last + 1][leading_zero][tight] = count_numbers;
}

int main() {
    ll a, b;
    cin >> a >> b;

    ll count1 = 0, count2 = 0;
    memset(dp, -1, sizeof(dp));

    if (a > 0) {
        string s1 = to_string(a - 1);
        count1 = mem(s1, (ll)s1.size(), -1, 1, 1);
    }

    memset(dp, -1, sizeof(dp));
    string s2 = to_string(b);
    count2 = mem(s2, (ll)s2.size(), -1, 1, 1);

    cout << count2 - count1 << '\n';
    return 0;
}
