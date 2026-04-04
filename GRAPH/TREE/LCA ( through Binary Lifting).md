# LCA ( through Binary Lifting)

*// solving:*
*const* int N = 2e5 + 5;
*vi* adjL[N];
*vi* par(N, -1);
*vi* depth(N, -1);
int lg[N+1];
ll n, m, q;
**void dfs(int node, int p, int d){
    depth[node] = d;
    par[node] = p;
    for(auto v : adjL[node]){
        if(v != p){
            dfs(v, node, d + 1);
        }
    }
}
ll getLCA(ll a, ll b ,** ***vvi&*** **jumpind){
    if(depth[a] < depth[b])
        swap(a, b);**
    ***// a is the higher node always***

    **ll d = depth[a] - depth[b];**

    ***// binary lifting to same level***
    **for(int jump = lg[N]; jump >= 0; jump--){
        if(d >= (1<<jump)){
            a = jumpind[jump][a];
            d -= (1<<jump);
        }
    }
    if(a == b)
        return a;
    
    for(int jump = lg[N]; jump >= 0; jump--){
        if(jumpind[jump][a] != jumpind[jump][b]){
            a = jumpind[jump][a];
            b = jumpind[jump][b];
        }
    }
    return jumpind[0][a];
}**
void solve(){
    *// 1-based indexing* 

    cin >> n >> q;

    *// cleaning*
    f(i,n+1){
        adjL[i].clear();
    }
    par.assign(n+1, -1);
    depth.assign(n+1, -1);

    *// input 2 ways*
    *// f(i,n-1){*
    *//     ll u, v; cin >> u >> v;*
    *//     adjL[u].pb(v);*
    *//     adjL[v].pb(u);*
    *// }*
    f(i,n-1){
        cin >> par[i+2];
        adjL[par[i+2]].pb(i+2);
    }

    *// preprocessing dfs ( calculate parents , depth)*
    dfs(1, -1, 0); *// 1 is considered root*

    *// baaki preprocessing*
    int root = 1;
    lg[1] = 0;
    for (int i = 2; i <= N; i++)
        lg[i] = lg[i/2] + 1;
    int K = lg[N];
    *vvi* jumpind(K+1, *vi*(N, -1));

    ***// populating the jumps array***
    **for(int i = N-1;i>0; i--){
        jumpind[0][i] = par[i];
    }
    for(int jump = 1; jump<=K; jump++){
        for(int i = 1; i<N; i++){
            if(jumpind[jump-1][i] == -1){
                jumpind[jump][i] = -1;
            }
            else
                jumpind[jump][i] = jumpind[jump-1][jumpind[jump-1][i]];
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << getLCA(a, b, jumpind) << endl;
    }**
}

 <span style="font-size: 33.0;">
     
**If qn involves thinking about the path bw 2 nodes in a tree, its built on LCA. Root the Tree at a node, find the LCA of node a and node b. Now we know the path from a to b.**
 </span>