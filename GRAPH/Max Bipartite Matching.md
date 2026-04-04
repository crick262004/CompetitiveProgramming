# Max Bipartite Matching

# 
![F382B81B-B1CD-4DE3-B708-5B2AEFB4CCE8](images/F382B81B-B1CD-4DE3-B708-5B2AEFB4CCE8.png)
![7EEA46A1-E060-45BE-85E8-8F433E6300CF](images/7EEA46A1-E060-45BE-85E8-8F433E6300CF.png)
![8799B79A-817D-416F-AA42-6955B604FBE6](images/8799B79A-817D-416F-AA42-6955B604FBE6.png)
*const* int N = 501;
int n, m, k; *// n is first group ka size, m is second group ka size (both of the groups of the bipartite graph)*
vi adjL[N]; *// just stores edges from first group nodes to second group nodes.*
vector<int> mt(N);  *// marking saturation of second group nodes by showing the group 1 node it is paired with. -1 means un-paired.*
vector<bool> used(N); *// represents group 1 nodes assigned to the augmenting path while search for an augmenting path.*

bool try_kuhn(int v) { *// function to try and find an augmenting path*
    if (used[v])
        return false;
    used[v] = true;
    for (int to : adjL[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m >> k;
    f(i,k){
        ll a, b; cin >> a >> b;
        a--; b--;
        adjL[a].pb(b);
    }

    mt.assign(m, -1); *// initally, all nodes are unsaturated*
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        try_kuhn(v);
    }

    vpi ans;
    for (int i = 0; i < m; ++i){
        if (mt[i] != -1){
            ans.pb({mt[i] + 1, i + 1});
        }
    }
    cout << ans.size() << endl;
    for(auto it : ans)
        cout << it << endl;
}

![AE2E29B1-1AB2-4B3A-825A-3956D0EB886C](images/AE2E29B1-1AB2-4B3A-825A-3956D0EB886C.png)

int main() {
    // ... reading the graph ...

    mt.assign(k, -1);
    vector<bool> used1(n, false);
    for (int v = 0; v < n; ++v) {
        for (int to : g[v]) {
            if (mt[to] == -1) {
                mt[to] = v;
                used1[v] = true;
                break;
            }
        }
    }
    for (int v = 0; v < n; ++v) {
        if (used1[v])
            continue;
        used.assign(n, false);
        try_kuhn(v);
    }

    for (int i = 0; i < k; ++i)
        if (mt[i] != -1)
            printf("%d %d\n", mt[i] + 1, i + 1);
}

![C6029DA5-59D3-4813-A3DC-82797AE6AB6E](images/C6029DA5-59D3-4813-A3DC-82797AE6AB6E.png)
![6870110D-6458-4463-B548-D41EE2D1A32B](images/6870110D-6458-4463-B548-D41EE2D1A32B.png)










 <span style="font-size: 33.0;">
     **Algo to do Maximum Bipartite matching :** 

 </span> <span style="font-size: 15.0;">
     [https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html](https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html)
 </span>
 <span style="font-size: 33.0;">
     **Example Problem : (Max Matching)**
 </span>
![51D5163F-A98B-4CC3-9F49-05956DF632D8](images/51D5163F-A98B-4CC3-9F49-05956DF632D8.png)

