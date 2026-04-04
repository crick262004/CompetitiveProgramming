# DP ON STOCKS


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> next(k*2,0), cur(k*2,0);

        for(int index = n-1; index>=0; index--)
        {
            for(int state = 2*k-1; state>=0; state--)
            {
                if(state == 2*k-1)
                {
                    cur[state] =  max( next[state] , 
                                prices[index]);
                }
                else if(state % 2 == 0) // buying time.
                {
                    cur[state] =  max(next[state] , 
                                next[state+1] 
                                - prices[index]);
                }
                else // sell time.
                {
                    cur[state] =  max( next[state] , 
                                next[state+1] + prices[index]);   
                }
                // if(state == 0)
                //     cur[state] =  max(next[state] , 
                //                 next[state+1] 
                //                 - prices[index]);
                // else if(state == 1)
                    // cur[state] =  max( next[state] , 
                    //             next[state+1] + prices[index]);   
                // else if(state == 2)
                //     cur[state] =  max(next[state] , 
                //                 next[state+1] 
                //                 - prices[index]);
                // else// state = 3
                //     cur[state] =  max( next[state] , 
                //                 prices[index]);
            }
            next = cur;
        }
        return cur[0];
    }
};
