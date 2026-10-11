// Maintains a set of non-overlapping [left, right) intervals using a sorted map.
// Operations: addRange, queryRange, removeRange
// Complexity: O(k log n) per operation where k = number of overlapping intervals affected
// Use cases: interval merging, booking/calendar problems, coordinate range tracking
//
// Internal representation: map<int,int> where each entry {l, r} represents interval [l, r)

struct RangeMap {
    map<int,int> mp;

    // Adds [left, right), merging with any overlapping/adjacent intervals
    void addRange(int left, int right) {
        auto it = mp.upper_bound(left);
        if (it != mp.begin() && prev(it)->second >= left)
            it = prev(it);
        while (it != mp.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            it = mp.erase(it);
        }
        mp[left] = right;
    }

    // Returns true if every point in [left, right) is currently tracked
    bool queryRange(int left, int right) {
        auto it = mp.upper_bound(left);
        if (it == mp.begin()) return false;
        auto loe = prev(it);
        return loe->second >= right;
    }

    // Removes [left, right), splitting intervals as needed
    void removeRange(int left, int right) {
        auto it = mp.upper_bound(left);
        if (it != mp.begin() && prev(it)->second > left)
            it = prev(it);
        vector<pair<int,int>> to_add;
        while (it != mp.end() && it->first < right) {
            int l = it->first, r = it->second;
            if (l < left) to_add.push_back({l, left});
            if (r > right) to_add.push_back({right, r});
            it = mp.erase(it);
        }
        for (auto& [l, r] : to_add)
            mp[l] = r;
    }
};
