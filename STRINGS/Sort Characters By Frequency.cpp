// Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/
// core concept is Bucket / counting sort, when we know the range of values, and it is <1e6

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> freqMap;
    for (char c : s) {
        freqMap[c]++;
    }

    vector<vector<char>> buckets(s.size() + 1);

    for (const auto& entry : freqMap) {
        char c = entry.first;
        int freq = entry.second;
        buckets[freq].push_back(c);
    }

    string res;
    for (int i = buckets.size() - 1; i > 0; i--) {
        for (char c : buckets[i]) {
            res.append(i, c);
        }
    }

    return res;
}
