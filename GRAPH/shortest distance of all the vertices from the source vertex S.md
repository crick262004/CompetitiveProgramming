# shortest distance of all the vertices from the source vertex S

 <span style="font-size: 25.0;">
     **weighted, directed and connected graph with negative weights. 

BF is used as a go-to algo to detect negative cycle in graphs.
Remove the dist[u] != 1e18 wala logic in that case.**


 </span> If the Graph contains a negative cycle then return an array consisting of only -1.

**Bellman Ford Algorithm**
*const* int N = 2510; 
*vpi* adjL[N];
ll n, m;
void solve(){
    cin >> n >> m;
    f(i,n+1){
        adjL[i].clear();
    }
    f(i,m){
        ll u, v, w; cin >> u >> v >>z w;
        adjL[u].pb({v, w});
    }
    vector<*pi*> dist(n+1, {1e18, -1});
    dist[1] = {0, -1};
    for (int i = 1; i<n; i++) {
        for(int u = 1; u<=n; u++){
            for(auto it : adjL[u]){
                int v = it.ff;
                int wt = it.ss;
                if (dist[u].ff != 1e18 && dist[u].ff + wt < dist[v].ff) {
                    dist[v] = {dist[u].ff + wt, u};
                }
            }
        }
    }
    for(int u = 1; u<=n; u++){
        for(auto it : adjL[u]){
            int v = it.ff;
            int wt = it.ss;
            if (dist[u].ff != 1e18 && dist[u].ff + wt < dist[v].ff) {
                *// negative cycle present*
            }
        }
    }
    return dist;
}





 <span style="font-size: 25.0;">
     **BF Algo(but for max distance path) that also handles false cycles (positive ( bcos of max distance logic) cycles that are present but not a threat to distance[destination] are ignored, (because the cycle isn’t connected to N) )**
 </span>
*vpi* adjL[N];
void solve(){

    ll n; 
    cin >> n;
    ll m; cin >> m;
    f(i,n+1)
        adjL[i].clear();
    f(i,m){
        ll u, v, w; cin >> u >> v >> w;
        adjL[u].pb({v, w});
    }
    *vi* ton(n+1, 0); // is node connected to <u>n / destination</u> node
    queue<int> q;
    *vpi* RadjL[n+1];
    f(i,n+1){
        for(auto it : adjL[i]){
            int v = it.ff;
            int w = it.ss;
            RadjL[v].pb({i, w});
        }
    }
    q.push(n);
    ton[n] = 1;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto it : RadjL[node]){
            if(ton[it.ff] == 0){
                ton[it.ff] = 1;
                q.push(it.ff);
            }
        }
    }

    vector<int> dist(n+1, -1e18);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        for(int u = 1; u<=n; u++){
            for(auto it : adjL[u]){
                int v = it.ff;
                int wt = it.ss;
                if (dist[u] > -1e18 && (dist[u] + wt) > dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
    for(int u = 1; u<=n; u++){
        for(auto it : adjL[u]){
            int v = it.ff;
            int wt = it.ss;
            if (dist[u] > -1e18 && (dist[u] + wt) > dist[v] && ton[v]) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << dist[n] << endl;
}


 <span style="font-size: 25.0;">
     **BF Algo for finding neg cycle and printing it. ( also having a parent node value for each node, stored in distance vector )**
 </span>
*const* int N = 5001; 
vpi adjL[N];
ll n, m;
void solve(){
    cin >> n >> m;
    f(i,n+1){
        adjL[i].clear();
    }
    f(i,m){
        ll u, v, w; cin >> u >> v >> w;
        adjL[u].pb({v, w});
    }
    vector<pi> dist(n+1, {1e18, -1});
    dist[1] = {0, -1};
    for (int i = 1; i<n; i++) {
        for(int u = 1; u<=n; u++){
            for(auto it : adjL[u]){
                int v = it.ff;
                int wt = it.ss;
                if (dist[u].ff + wt < dist[v].ff) {
                    dist[v] = {dist[u].ff + wt, u};
                }
            }
        }
    }
    for(int u = 1; u<=n; u++){
        for(auto it : adjL[u]){
            int v = it.ff;
            int wt = it.ss;
            if (dist[u].ff + wt < dist[v].ff) {
                *// cout << u << " " << v << endl;*
                cyes;
                vi nodes;
                nodes.pb(v);
                vi found(n+1, 0);
                int cur = u;
                found[v] = 1;
                while(found[cur] == 0){
                    nodes.pb(cur);
                    found[cur] = 1;
                    cur = dist[cur].ss;
                }
                if(cur != -1)
                    nodes.pb(cur);
                reverse(all(nodes));
                int f = nodes[0];
                cout << f << " ";
                for(int i = 1; i<nodes.size(); i++){
                    cout << nodes[i] << " ";
                    if(nodes[i] == f){
                        return;
                    }
                }
                return;
            }
        }
    }
    cno;
}

