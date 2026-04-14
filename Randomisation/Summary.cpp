// Simple summary:

#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r)
{
    return rng() % (r - l + 1) + l;
}

void do_shuffle()
{
    // shuffle(container.begin(), container.end(), rng);
}
