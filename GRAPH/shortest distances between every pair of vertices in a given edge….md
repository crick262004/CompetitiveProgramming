# shortest distances between every pair of vertices in a given edge…

 <span style="font-size: 21.0;">
     **shortest distances between every pair of vertices in a given edge-weighted directed graph.**


 </span>**Floyd Warshall Algorithm**
*const* int N = 550; 
*vvi* adjL(N, *vi*(N, 1e18));
ll n, m;
void solve(){
    ll q;
    cin >> n >> m >> q;
    f(i,m){
        ll u, v, w; cin >> u >> v >> w;
        adjL[u][v]= min(adjL[u][v], w);
        adjL[v][u]= min(adjL[v][u], w);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) 
                adjL[i][j] = 0;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adjL[i][j] = min(adjL[i][j],
                                    adjL[i][k] + adjL[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjL[i+1][j+1] == 1e18) {
                adjL[i+1][j+1] = -1;
            }
        }
    }
    while(q--){
        ll u, v; cin >> u >> v;
        cout << adjL[u][v] << endl;
    }
}
