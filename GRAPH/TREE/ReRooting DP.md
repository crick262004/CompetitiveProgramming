# ReRooting dp Good Learning problem, on this topic: https://codeforces.com…

 <span style="font-size: 43.0;">
     # **ReRooting dp
Good Learning problem, on this topic:**

 </span> <span style="font-size: 28.0;">
     # **[https://codeforces.com/problemset/problem/1187/E](https://codeforces.com/problemset/problem/1187/E)**
 </span>
# **DP on Trees + Rerooting**
![0E88A480-4CBA-499F-AE74-59A814A1AACB](images/0E88A480-4CBA-499F-AE74-59A814A1AACB.png)
*// solving:*
*const* int N = 2e5 + 5; 
vi adjL[N];
vi val(N);
ll n, m, totalsum, ans;
vi sum(N);
void dfs(int node, int par){
    sum[node] = val[node];
    for(auto v : adjL[node]){
        if(v != par){
            dfs(v, node);
            sum[node] += sum[v];
        }
    }
}
void dfs2(int node, int par, int dist){
    ans += val[node] * dist;
    for(auto v : adjL[node]){
        if(v != par){
            dfs2(v, node, dist + 1);
        }
    }
}
void dfs3(int node, int par, int cur){
    *// check new anss*
    ans = max(ans, cur);
    for(auto v : adjL[node]){
        if(v != par){
        int newval = cur - sum[v] + (totalsum - sum[v]);
        dfs3(v, node, newval);}
    }
}
void solve(){
    cin >> n;
    ans = 0;
    totalsum = 0;
    val.assign(n+1, 0);
    sum.assign(n+1, 1);
    f(i,n+1){
        adjL[i].clear();
    }
    f(i,n){
        cin >> val[i+1];
        totalsum += val[i+1];
    }
    f(i,n-1){
        ll u, v; cin >> u >> v;
        adjL[u].pb(v);
        adjL[v].pb(u); *// ya not, if directed*
    }
    *// preprocessing required*
    dfs(1, -1);

    *// calculating dp[1]*
    dfs2(1, -1, 0);

    *// calculating dp[node] for all other nodes*
    dfs3(1, -1, ans);
    cans;
}
