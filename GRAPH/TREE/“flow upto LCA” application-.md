# “flow upto LCA” application:



*vi* adjL[N];
*vi* depth(N);
int maxExponent = log2(N) + 1;
*vvi* binaryParent(N, *vi* (maxExponent + 1, -1));
*vvi* flow(N, *vi*(maxExponent + 1, 1e18));
map<*pi*, int> weights;

void dfs(int cur, int par, int d){
    *// vis[cur] = 1;*
    depth[cur] = d;
    binaryParent[cur][0] = par;
    if(par != -1)
        flow[cur][0] = weights[{cur, par}];
    for(int v : adjL[cur]){
        if(v != par){
            dfs(v, cur, d + 1);
        }
    }
}

ll flowUptoLCA(ll a, ll b){
    ll ans = 1e18;
    if(depth[a] < depth[b])
        swap(a, b);
    *// a is the higher node always*

    ll d = depth[a] - depth[b];
    *// binary lifting to same level*
    while(d>0){
        ll jump = log2(d);
        ans = min(ans, flow[a][jump]);
        a = binaryParent[a][jump];
        d = d - (1<<jump);
    }

    if(a == b)
        return ans;

    for(int e = maxExponent; e>= 0; e--){
        if(binaryParent[a][e] == -1 || binaryParent[a][e] == binaryParent[b][e])
            continue;
        ans = min({ans, flow[a][e], flow[b][e]});
        a = binaryParent[a][e];
        b = binaryParent[b][e];
    }
    return min({ans, flow[a][0], flow[b][0]});
}

void solve(){
    ll n; ll m;
    cin >> n; cin >> m;
    f(i, m){
        ll u, v;
        cin >> u >> v;
        adjL[u].pb(v);
        adjL[v].pb(u);
        ll w; cin >> w;
        weights[{u,v}] = w; 
        weights[{v,u}] = w;
    }
 
    *// dfs to set parents and depth.*
    dfs(1, -1, 0); 

    *// creating the binaryParents matrix and flowUptoBinaryParent matrix*
    for(int jumpExponent = 1; jumpExponent<=maxExponent; jumpExponent++){
        for(int node = 1; node<=n; node++){
            if(binaryParent[node][jumpExponent-1] != -1){
                flow[node][jumpExponent] = 
                min(flow[node][jumpExponent-1], 
                    flow[binaryParent[node][jumpExponent-1]][jumpExponent-1]);
                binaryParent[node][jumpExponent] = binaryParent[binaryParent[node][jumpExponent-1]][jumpExponent-1];
            }
        }
    }

    *// queries, applying the flow upto LCA part:*
    ll q;
    cin >> q;
    f(i, q){
        ll a, b;
        cin >> a >> b;
        cout << flowUptoLCA(a,b) << endl;
    }
}