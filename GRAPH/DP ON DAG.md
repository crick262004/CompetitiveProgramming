# DP ON DAG

 <span style="font-size: 44.0;">
     # **( just do normal top-down recursion, and memoize it )**
 </span>

*const* int N = 2e5 + 5; 
*vi* adjL[N];
*vi* dp(N);
*vi* nt(N);
ll n, m;
void dfs(int node){
    if(node == n){
        dp[node] = 1;
    }
    else{
        int cnt = 0;
        for(auto v : adjL[node]){
            if(dp[v] == -1){
                dfs(v);
            }
            cnt += dp[v];
            cnt %= mod;
        }
        dp[node] = cnt;
    }
}
void solve(){
    cin >> n >> m;
    dp.assign(n+1, -1);
    f(i,n+1){
        adjL[i].clear();
    }
    f(i,m){
        ll u, v; cin >> u >> v;
        adjL[u].pb(v);
    }
    dfs(1);
    cout << dp[1] << endl;
}

# Different problem:

*const* int N = 2e5 + 5; 
*vi* adjL[N];
*vi* dp(N);
*vi* nt(N);
ll n, m;
void dfs(int node){
    *// cout << node << endl;*
    if(node == n){
        dp[node] = 1;
        nt[node] = -1;
    }
    else{
        int maxi = -3;
        int nxt = -1;
        for(auto v : adjL[node]){
            if(dp[v] == -1){
                dfs(v);
            }
            if(maxi < dp[v] && dp[v] != -2){
                maxi = dp[v];
                nt[node] = v;
            }
        }
        dp[node] = 1 + maxi;
    }
}
void solve(){
    cin >> n >> m;
    dp.assign(n+1, -1);
    nt.assign(n+1, -1);
    f(i,n+1){
        adjL[i].clear();
    }
    f(i,m){
        ll u, v; cin >> u >> v;
        adjL[u].pb(v);
    }
    dfs(1);
    if(dp[1] <= 1){
        cout << "IMPOSSIBLE" << endl;
    } else{
        cout << dp[1] << endl;
        int node = 1;
        while(node != -1){
            cout << node << " ";
            node = nt[node];
        } cout << endl;
    }
}
