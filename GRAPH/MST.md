# MST

Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. 


 <span style="font-size: 19.0;">
     **PRIMS**
 </span>
if they want the MST too, we will have to store triplets in the pq( now we also need to strore the source node for each edge) and also create a vector of triplets called MST jahan while adding dist to sum, we also add the triplet to MST vector.
class Solution
{
public:
	*//Function to find sum of weights of edges of the Minimum Spanning Tree.*
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		*// {wt, node}*
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			*// add it to the mst*
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}
};


 <span style="font-size: 19.0;">
     **KRUSKAL**

 </span>*const* int N = 2e5 + 5; 
*vpi* adjL[N];
ll n, m;
class *DisjointSet* {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
void solve(){
    cin >> n >> m;
    f(i,n+1){
        adjL[i].clear();
    }
    f(i,m){
        ll u, v, w; cin >> u >> v >> w;
        adjL[u].pb({v, w});
        adjL[v].pb({u, w}); *// ya not, if directed*
    }
    <span style="font-size: 18.0;">
      **vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i <= n; i++) {
        for (auto it : adjL[i]) {
            int adjNode = it.first;
            int wt = it.second;
            int node = i;

            edges.push_back({wt, {node, adjNode}});
        }
    }**
    
 </span> <span style="font-size: 18.0;">
     ***DisjointSet***
 </span> <span style="font-size: 18.0;">
      **ds(n+1);
    sort(edges.begin(), edges.end());
    int mstWt = 0;
    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUPar(u) != ds.findUPar(v)) {
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }**
 </span>
    set<int> cc;
    for(int i = 1; i<=n; i++){
        cc.insert(ds.findUPar(i));
    }
    if(cc.size() == 1){
        cout << mstWt << "\n";
    } else{
        cout << "IMPOSSIBLE" << "\n";
    }
}
