/*
# Dominator : (Easy)

**I usually replace my input function with a generator, and use a lambda function for the brute.
All in the same file ( So just make a copy of original solution, and make the edits )**
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    // Problem is sum of subarrays 
    
    // int n; cin >> n;
    int n = 1 + RNG() % 5;
    
    vector <int> a(n + 1);
    
    for (int i = 1; i <= n; i++){
        // cin >> a[i];
        a[i] = 1 + RNG() % 5;
    }
    
    auto brute = [&](){
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int sum = 0;
            for (int j = i; j <= n; j++){
                sum += a[j];
                ans += sum;
            }
        }
        return ans;
    };  
    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans += a[i] * (i) * (n + 1 - i);
    }
    
    int brute_ans = brute();
    
    if (brute_ans != ans){
        cout << n << "\n";
        for (int i = 1; i <= n; i++){
            cout << a[i] << " \n"[i == n];
        }
        cout << brute_ans << " " << ans << "\n";
        exit(0);
    }
    
    // cout << ans << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}

// https://codeforces.com/contest/2006/submission/278921664
