// k most frequent elements

vector<int> topKFrequent(vector<int>& nums, int k) {
    // CRAZY SMART APPROACH OF BUCKETS ON FREQUENCE, TO BRING THE TIME COMPLEXITY TO O(N)

    int n = nums.size();
    vector<vector<int>> buckets(n+1);
    unordered_map<int, int> freq;
    for( int i = 0; i<n; i++)
    {
        int val = nums[i];
        freq[val] ++;
    }

    // heap solution.
    priority_queue<pair<int,int>> heap;
    for(auto it : freq)
    {
        heap.push({it.second, it.first});
    }
    vector<int> ans;
    for(int i = 0; i<k; i++)
    {
        ans.push_back(heap.top().second);
        heap.pop();
    }
    return ans;

    // for(auto x : freq)
    // {
    //     buckets[x.second].push_back(x.first);
    // }

    // vector<int> ans;
    // for(int i = n; i>=0; i--)
    // {
    //     for(int j = 0; j<buckets[i].size(); j++)
    //     {
    //         ans.push_back(buckets[i][j]);
    //         if(ans.size()>=k)
    //             return ans;
    //     }
    // }
    // return ans;
}
