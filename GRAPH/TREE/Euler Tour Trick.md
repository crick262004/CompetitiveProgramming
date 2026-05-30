# Euler Tour Trick

 <span style="font-size: 42.0;">
     # **Each subtree = Contiguous range of array
Tree Flattening** 

 </span>*vector<int> intime, outtime, euler;
int timer = 0;

void dfs(int u, int p, const vector<vector<int>>& adj) {
    intime[u] = timer;
    euler[timer] = u; // store node in euler array
    timer++;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, adj);
        }
    }
    outtime[u] = timer - 1;
}

void build_euler(int n, int root, const vector<vector<int>>& adj) {
    intime.assign(n, -1);
    outtime.assign(n, -1);
    euler.assign(n, -1);
    timer = 0;
    dfs(root, -1, adj);
}*

![29236886-8400-49EC-8952-97A0FCA772AD](images/29236886-8400-49EC-8952-97A0FCA772AD.png)
# ![BC7870D4-42E2-4D28-BB52-286FD217E922](images/BC7870D4-42E2-4D28-BB52-286FD217E922.png)

![FAA67EB1-A4E8-44BC-8EDB-3D82FE3396E9](images/FAA67EB1-A4E8-44BC-8EDB-3D82FE3396E9.png)
