# Binary Lifting  (If parents array isn’t available, we can either first…

 <span style="font-size: 31.0;">
     # **Binary Lifting 
(If parents array isn’t available, we can either first calc. it, or just go in dfs order)**

 </span> <span style="font-size: 31.0;">
     **1.**

 </span>class TreeAncestor {
public:
    static const int m = 6e4;
    int lg[m+1];
    int K;
    vector<vector<int>> jumpind;
    TreeAncestor(int n, vector<int>& parent) {
        lg[1] = 0;
        for (int i = 2; i <= m; i++)
            lg[i] = lg[i/2] + 1;
        K = lg[m];
        jumpind.assign(K+1, vector<int>(m, -1));
        for(int i = 0;i<n; i++){
            jumpind[0][i] = parent[i];
        }
        for(int jump = 1; jump<=K; jump++){
            for(int i = 0; i<n; i++){
                if(jumpind[jump-1][i] == -1){
                    jumpind[jump][i] = -1;
                }
                else
                    jumpind[jump][i] = jumpind[jump-1][jumpind[jump-1][i]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int d = k;
        int ind = node;
        for(int jump = K; jump >= 0; jump--){
            if(d >= (1ll<<jump)){
                ind = jumpind[jump][ind];
                d -= (1ll<<jump);
                if(ind == -1)
                    break;
            }   
        }
        return ind;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
 <span style="font-size: 31.0;">
     
**2.**

 </span>*const* int N = 2e5 + 5; 
*vi* adjL[N];
*vi* par(N);
ll n, q;
void solve(){
    int K = 31;
    cin >> n >> q;
    par.assign(n+1, 0);
    f(i,n+1){
        adjL[i].clear();
    }
    f(i,n){
        cin >> par[i+1];
    }
    *vvi* jumpind(K+1, *vi*(n+1, -1));
    for(int i = n;i>=1; i--){
        jumpind[0][i] = par[i];
    }
    for(int jump = 1; jump<=K; jump++){
        for(int i = 1; i<=n; i++){
            jumpind[jump][i] = jumpind[jump-1][jumpind[jump-1][i]];
        }
    }
    while(q--){
        ll x, d; cin >> x >> d;
        int ind = x;
        for(int jump = 31; jump >= 0; jump--){
            if(d >= (1ll<<jump)){
                ind = jumpind[jump][ind];
                d -= (1ll<<jump);
            }   
        }
        cout << ind << endl;
    }
} <span style="font-size: 31.0;">
     

**3.**

 </span>int lg[m+1];
    lg[1] = 0;
    for (int i = 2; i <= m; i++)
        lg[i] = lg[i/2] + 1;
    int K = lg[m];

    *vvi* jumpind(K+1, *vi*(m, m));
    for(int i = m-1;i>=0; i--){
        jumpind[0][i] = last_ind[next_val[a[i]]];
        last_ind[a[i]] = i;
    }
    for(int jump = 1; jump<=K; jump++){
        for(int i = 0; i<m; i++){
            if(jumpind[jump-1][i] == m){
                jumpind[jump][i] = m;
            }
            else
                jumpind[jump][i] = jumpind[jump-1][jumpind[jump-1][i]];
        }
    }

       while(d){
            int j = log2(d);
            d -= (1<<j);
            ind = jumpind[j][ind];
            if(ind >= m){
                flag = true;
                break;
            }
        }
OR 
        for(int jump = 31; jump >= 0; jump--){
            if(d >= (1ll<<jump)){
                ind = jumpind[jump][ind];
                d -= (1ll<<jump);
            }   
        }

