# BFS


 <span style="font-size: 20.0;">
     undirected graph
 </span>
*// Function to return Breadth First Traversal of given graph.*
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        *// push the initial starting node* 
        q.push(0); 
        vector<int> bfs; 
        *// iterate till the queue is empty* 
        while(!q.empty()) {
           *// get the topmost element in the queue* 
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            *// traverse for all its neighbours* 
            for(auto it : adj[node]) {
                *// if the neighbour has previously not been visited,* 
                *// store in Q and mark as visited* 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }

 <span style="font-size: 20.0;">
     grid wala graph

 </span>class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();

        int tot = 0;
        int cnt = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] != 0)
                {
                    tot++;
                    if(grid[i][j] == 2)
                    {
                        q.push({i,j});
                        cnt++;
                    }
                }
            }
        }
        int ans = 0;

        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};

        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++)
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr >=0 && nc >=0 && nr <m && nc < n && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        cnt++;
                    }
                }
            }
            if(!q.empty()) ans++;
        }
        return tot == cnt ? ans: -1;
    }
};

