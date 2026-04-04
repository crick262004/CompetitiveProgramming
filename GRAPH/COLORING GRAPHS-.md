# COLORING GRAPHS:

# 
# M - coloring problem
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }

  }
  return false;
}

*//Function to determine if graph can be coloured with at most M colours such*
*//that no two adjacent vertices of graph are coloured with same colour.*
bool graphColoring(bool graph[101][101], int m, int N) {
  int color[N] = {0};
  if (solve(0, color, m, N, graph)) return true;
  return false;
}

# BIPARTITE GRAPHS:
class Solution {
private: 
    bool dfs(int node, int col, int color[], vector<int> adj[]) {
        color[node] = col; 
        
        *// traverse adjacent nodes*
        for(auto it : adj[node]) {
            *// if uncoloured*
            if(color[it] == -1) {
                if(dfs(it, !col, color, adj) == false) return false; 
            }
            *// if previously coloured and have the same colour*
            else if(color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i = 0;i<V;i++) color[i] = -1; 
	    
	    *// for connected components*
	    for(int i = 0;i<V;i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, adj) == false) 
	                return false; 
	        }
	    }
	    return true; 
	}
};
