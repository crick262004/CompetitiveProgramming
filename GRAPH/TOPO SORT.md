# TOPO SORT


QUESTION ASKING : 
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex **u** comes before **v** in the ordering.

You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you **must** take course bi first if you want to take course ai. Return *the ordering of courses you should take to finish all courses*. 



# BFS KIND, CAN ALSO DETECT IF NOT DAG
*const* int N = 2e5 + 5; 
*vi* adjL[N];
ll n, m;
void solve(){
    cin >> n >> m;
    f(i,n+1){
        adjL[i].clear();
    }
    f(i,m){
        ll u, v; cin >> u >> v;
        adjL[u].pb(v);
    }

 <span style="font-size: 19.0;">
         **int indegree[n+1] = {0};
    for (int i = 1; i <= n; i++) {
        for (auto it : adjL[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);**

 </span> <span style="font-size: 19.0;">
             ***// node is in your topo sort***
 </span>
 <span style="font-size: 19.0;">
             ***// so please remove it from the indegree***
 </span> <span style="font-size: 19.0;">
     

        **for (auto it : adjL[node] ){
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }**
 </span>
    if(topo.size() == n){
        cout << topo << endl;
    } else{
        cout <<"IMPOSSIBLE" << endl;
    }
}



# DFS KIND, GIVEN GRAPH IS DAG 
 <span style="font-family: .AppleSystemUIFont; font-size: 15.0;">
     # (CAN BE CHECKED USING THE PATH-VIS ALGORITHM FOR CYCLE DETECTION OF DIRECTED GRAPH USING DFS)
 </span>
class Solution {
private:
	void dfs(int node, int vis[], stack<int> &st,
	         vector<int> adj[]) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) dfs(it, vis, st, adj);
		}
		st.push(node);
	}
public:
	*//Function to return list containing vertices in Topological order.*
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int vis[V] = {0};
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}

		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};

