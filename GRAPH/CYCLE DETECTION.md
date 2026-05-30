# CYCLE DETECTION


# DIRECTED 
# DFS: THE PATH + VIS ALGORITHM. 
# CAN’T JUST CONSIDER VISITED WHEN DIRECTED GRAPH.

*const* int N = 2e5 + 5; 
*vi* adjL[N];
*vi* vis(N,0);
*vi* path(N,0);
ll n, m;
*vi* ans;
bool dfs(int node, *vi&* cur) {
    *// cout << node << endl;*
    vis[node] = 1; 
    path[node] = 1;
    cur.pb(node);
    for(auto adjacentNode: adjL[node]) {
        if(!vis[adjacentNode]) {
            if(dfs(adjacentNode, cur) == true) {
                path[node] = 0;
                cur.pop_back();
                return true; 
            }
        }
        *// visited node but not a parent node*
        else if(path[adjacentNode]){
            bool st = false;
            for(int i = 0; i<cur.size(); i++){
                if(st || cur[i] == adjacentNode){
                    st = true;
                    ans.pb(cur[i]);
                }
            }
            ans.pb(adjacentNode);
            path[node] = 0;
            cur.pop_back();
            return true; 
        }
    }
    cur.pop_back();
    path[node] = 0;
    return false; 
}

void solve(){
    cin >> n >> m;
    vis.assign(n+1, 0);
    path.assign(n+1, 0);
    ans.clear();
    f(i,m){
        ll u, v; cin >> u >> v;
        adjL[u].pb(v);
    }
    *vi* cur = {};
    for(int i = 1;i<=n;i++) {
        if(!vis[i]) {
            if(dfs(i, cur) == true){
                cout << ans.size() << endl;
                cans;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

# DIRECTED BFS:
USE TOPO SORT, JUST CHECK IF (TOPO.SIZE() == N)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for(int i= 0; i<n;i++)
            if(indegree[i] == 0)
                q.push(i);
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto adjnode : adj[node])
            {
                indegree[adjnode]--;
                if(indegree[adjnode] == 0)
                    q.push(adjnode);
            }
        }
        if(ans.size() == n)
            return true;
        return false;
    }
};



# UNDIRECTED BFS:
class Solution {
  private: 
  bool detect(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      *// store <source node, parent node>*
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      *// traverse until queue is not empty*
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          *// go to all adjacent nodes*
          for(auto adjacentNode: adj[node]) {
              *// if adjacent node is unvisited*
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              *// if adjacent node is visited and is not it's own parent node*
              else if(parent != adjacentNode) {
                  *// yes it is a cycle*
                  return true; 
              }
          }
      }
      *// there's no cycle*
      return false; 
  }
  public:
    *// Function to detect cycle in an undirected graph.*
    bool isCycle(int V, vector<int> adj[]) {
        *// initialise them as unvisited* 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
};

# UNDIRECTED DFS: VISIT + PARENT NODE

*vi* ans;
bool dfs(int node, int parent, *vi&* cur) {
    vis[node] = 1;
    cur.pb(node);
    *// visit adjacent nodes*
    for(auto adjacentNode: adjL[node]) {
        *// unvisited adjacent node*
        if(!vis[adjacentNode]) {
            if(dfs(adjacentNode, node, cur) == true) 
                return true; 
        }
        *// visited node but not a parent node*
        else if(adjacentNode != parent){
            bool st = false;
            for(int i = 0; i<cur.size(); i++){
                if(st || cur[i] == adjacentNode){
                    st = true;
                    ans.pb(cur[i]);
                }
            }
            ans.pb(adjacentNode);
            return true; 
        }
    }
    cur.pop_back();
    return false; 
}
void solve(){
    cin >> n >> m;

    f(i,m){
        ll u, v; cin >> u >> v;
        adjL[u].pb(v);
        adjL[v].pb(u); *// ya not, if directed*
    }
    *vi* cur = {};
    for(int i = 1;i<=n;i++) {
        if(!vis[i]) {
            if(dfs(i, -1, cur) == true){
                cout << ans.size() << endl;
                cans;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

