# DFS


 <span style="font-size: 20.0;">
     undirected graph

 </span>void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        *// traverse all its neighbours*
        for(auto it : adj[node]) {
            *// if the neighbour is not visited*
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }

 <span style="font-size: 20.0;">
     grid wala graph

 </span>void dfs(int i, int j, vector<vector<int>>& grid)
{
    grid[i][j] = 0;
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, +1};

    for(int k = 0; k<4; k++)
    {
        int ni = i + di[k], nj = j + dj[k];
        if(ni >=0 && ni < grid.size() && nj>=0 && nj < grid[0].size() 
        && grid[ni][nj] == 1)
            dfs(ni, nj, grid);
    }
}
