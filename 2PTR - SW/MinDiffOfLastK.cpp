#include <vector>
#include <set>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> minAbsDifferenceInSlidingWindow(const vector<int> &stream, int K)
{
    vector<int> result;
    deque<int> window_queue;
    multiset<int> window_elements;
    multiset<int> diffs;

    for (int val : stream)
    {
        // 1. Maintain FIFO order in queue
        window_queue.push_back(val);

        // 2. Insert into sorted multiset and update diffs
        auto it = window_elements.insert(val);
        
        auto pred = (it != window_elements.begin()) ? prev(it) : window_elements.end();
        auto succ = next(it);

        // If val sits between pred and succ, erase stale adjacent difference
        if (pred != window_elements.end() && succ != window_elements.end()) {
            diffs.erase(diffs.find(*succ - *pred));
        }
        // Insert new adjacent differences
        if (pred != window_elements.end()) {
            diffs.insert(*it - *pred);
        }
        if (succ != window_elements.end()) {
            diffs.insert(*succ - *it);
        }

        // 3. Remove oldest element if window exceeds K
        if (window_queue.size() > K) {
            int rval = window_queue.front();
            window_queue.pop_front();

            auto rit = window_elements.find(rval);
            auto rpred = (rit != window_elements.begin()) ? prev(rit) : window_elements.end();
            auto rsucc = next(rit);

            // Remove differences involving rval
            if (rpred != window_elements.end()) {
                diffs.erase(diffs.find(*rit - *rpred));
            }
            if (rsucc != window_elements.end()) {
                diffs.erase(diffs.find(*rsucc - *rit));
            }
            // Bridge predecessor and successor if both exist
            if (rpred != window_elements.end() && rsucc != window_elements.end()) {
                diffs.insert(*rsucc - *rpred);
            }

            window_elements.erase(rit);
        }

        // 4. Record answer when at least 2 elements are in window
        if (window_elements.size() >= 2) {
            result.push_back(*diffs.begin());
        }
    }

    return result;
}
