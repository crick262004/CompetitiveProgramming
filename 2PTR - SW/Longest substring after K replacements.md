# Longest substring after K replacements

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return *the length of the longest substring containing the same letter you can get after performing the above operations*.

int characterReplacement(string s, int k) {
    // very optimised solution. So go through videos to understand the steps.

    int n = s.length();
    vector<int> freq(256,0);

    int l = 0, ans = 0;
    int maxcnt = 0;
    for(int r = 0; r < n; r++)
    {
        freq[s[r]] ++;

        if(freq[s[r]] > maxcnt)
            maxcnt = freq[s[r]];
        
        if((r-l+1) - maxcnt > k)
        {
            freq[s[l]]--;
            // there is no point in decreasing the value of maxcnt, 
            // we will only get new answers when maxcnt is at a max
            l++;
        }

        // the size (r-l+1) has to be <= k + maxcnt, hence, we will need
        // maxcnt to be maximum in order to get a new answer
        if((r-l+1) - maxcnt <= k)
            ans = max(ans, r-l+1);
    }
    return ans;
}
