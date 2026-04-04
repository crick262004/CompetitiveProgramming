# MAXIMUM FREQ IN EVERY K LENGTH SUBARRAY


    map<int, int> freq;
    multiset<int, greater<int>> msf;
    for (int r = 0; r < k; r++)
    {
        auto it = msf.find(freq[a[r]]);
        if (it != msf.end()) {
            msf.erase(it);
        }
        freq[a[r]]++;
        msf.insert(freq[a[r]]);
    }
    ans[0] = *msf.begin();
    for (int r = k; r < n; r++)
    {
        
        auto it = msf.find(freq[a[l]]);
        if (it != msf.end()) {
            msf.erase(it);
        }
        freq[a[l]]--;
        msf.insert(freq[a[l]]);
        l++;
        auto it1 = msf.find(freq[a[r]]);
        if (it1 != msf.end()) {
            msf.erase(it1);
        }
        freq[a[r]]++;
        msf.insert(freq[a[r]]);
        ans[l] = *msf.begin();
    }