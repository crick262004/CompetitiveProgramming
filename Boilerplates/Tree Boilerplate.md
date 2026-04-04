# Tree Boilerplate


#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define f(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)((x).size()))
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define cans cout << ans << endl
#define minpq priority_queue <int, vector<int>, greater<int>>
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define sumof(v) (ll)accumulate(v.begin(), v.end(), 0ll)

#define int long long
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int, int>> vpi;

template <typename T, typename Y> istream *&*operator>>(istream *&*is, pair<T, Y> *&*p){is >> p.first >> p.second; return is;}
template <typename T, typename Y> ostream *&*operator<<(ostream *&*os, pair<T, Y> p)
{os << p.first << ' ' << p.second << ' ';return os;}
template <typename T> istream *&*operator>>(istream *&*is, vector<T> *&*v)
{for(auto &i : v){is >> i;} return is;}
template <typename T> ostream *&*operator<<(ostream *&*os, vector<T> v)
{for (auto &i : v){os << i << ' ';}return os;}

*// solving:*
*const* int mod = 1e9+7;
*const* int N = 2e5 + 5;

vi adjL[N];
vi par(N);
vi children[N];
vi vis(N,0);
vi val(N);
ll n;

void solve(){
    cin >> n;
    vis.assign(n+1, 0);
    val.assign(n+1, 0);
    par.assign(n+1, 0);
    f(i,n+1){
        adjL[i].clear();
        children[i].clear();
    }
    f(i,n){
        cin >> val[i+1];
    }
    f(i,n-1){
        ll u, v; cin >> u >> v;
        adjL[u].pb(v);
        adjL[v].pb(u); *// ya not, if directed*
    }
    f(i,n-1){
        ll p; cin >> p;
        par[i+2] = p;
        children[p].pb(i+2);
    }
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    *// freopen("in",  "r", stdin);*
    *// freopen("out", "w", stdout);*
    *// cout << "mod" << endl;*
    *// cout << "interactive, endl and flush" << endl;*
    *// cout << "debugging (reduced N)" << endl;*
    cout << setprecision(12) << fixed;

    *// pre-computation:*

    int t = 1;
    cin >> t;
    for(int i = 1; i<=t; i++){ 
        *// cout << "Case #" << i << endl;*
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
}
