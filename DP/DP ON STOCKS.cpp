// DP ON STOCKS

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> next(k * 2, 0), cur(k * 2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int state = 2 * k - 1; state >= 0; state--) {
                if (state == 2 * k - 1) {
                    cur[state] = max(next[state], prices[index]);
                } else if (state % 2 == 0) {
                    // Buy state.
                    cur[state] = max(next[state], next[state + 1] - prices[index]);
                } else {
                    // Sell state.
                    cur[state] = max(next[state], next[state + 1] + prices[index]);
                }
            }
            next = cur;
        }
        return cur[0];
    }
};
