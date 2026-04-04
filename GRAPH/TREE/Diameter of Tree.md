# Diameter of Tree

 <span style="font-size: 40.0;">
     **dfs style:**

 </span>    int root = 1;
    auto dfs = `[&](auto self, int u, int par)` -> pair<int, int>{
        pair <int, int> ans = {1, u};
        p[u] = par;
        seen[u] = true;
        
        for (int v : adjL[u]){
            if (v != par){
                auto pi = self(self, v, u);
                pi.first += 1;
                ans = max(ans, pi);
            }
        }
        return ans;
    };
    auto [d1, j] = dfs(dfs, root, -1);
    seen.assign(n+1, false);
    auto [d2, k] = dfs(dfs, j, -1);
    *// path from k, taking parents upto j, gives diameter path (and len of dia is stored in d2)*
    int node = k;
    while(1){
        *// doing something*

        if(node == j)
            break;
        else
            node = p[node];
    }


 <span style="font-size: 40.0;">
     **BFS:**
 </span>
*vi* diameter(int n){
    *// 1-based indexing, n is total no. of nodes*
    *// returns {node1, node2, diameter length}*
    *vi* vis(n+1 ,0);
    ll edgeNode1 = -1;
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty())
    {
        int u = q.front();
        edgeNode1 = u;
        q.pop();
        for(ll v : adjL[u]){
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    f(i,n+1)
        vis[i] = false;
    ll dia = -1;
    q.push(edgeNode1);
    vis[edgeNode1] = true;
    ll edgeNode2 = -1;
    while(!q.empty())
    {
        ll k = q.size();
        f(i, k){
            int u = q.front();
            edgeNode2 = u;
            q.pop();
            for(ll v : adjL[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        dia += 1;
    }
    return {edgeNode1, edgeNode2, dia};
}