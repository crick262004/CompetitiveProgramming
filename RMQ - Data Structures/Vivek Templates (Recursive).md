# Vivek Templates (Recursive)

 <span style="font-size: 31.0;">
     **Need to make Struct of the lazy one too.**


 </span> <span style="font-size: 35.0;">
     # **Lazy set, Node Sum Segment Tree**

 </span>
*vi* a(N, 0);
struct *node*{
    int lazy;
    int val;
    node(){
        lazy = 0; *// acc to qn*
        val = 0; *// acc to qn*
    }
};
struct *LazySegTree*{
    int SZ;
    vector<*node*> t;
    LazySegTree(int size) : SZ(size), t(4*size){}

    *node* merge(*node* a, *node* b){
        *node* ans;
        ans.val = a.val + b.val; *// acc to qn*
        return ans;
    }

    void push(int id, int l, int r){ *// acc to qn*
        if(t[id].lazy != 0){
            t[id].val = (r - l + 1)*t[id].lazy; *// apply*
            if(l != r){ *// propagate the lazy*
                t[id<<1].lazy = t[id].lazy;
                t[id<<1|1].lazy = t[id].lazy;
            }
            t[id].lazy = 0;
        }
    }

    void build(int id, int l, int r){
        if(l == r){
            t[id].val = a[l]; *// acc to qn*
            t[id].lazy = 0; *// acc to qn*
            return;
        }
        int mid = (l+r)/2;
        build(2*id,l,mid);
        build(2*id+1, mid+1, r);
        t[id] = merge(t[2*id], t[2*id+1]);
    }

    void update(int id, int l, int r, int lq, int rq, int val){
        push(id, l, r);
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            t[id].lazy = val; *// acc to qn*
            push(id, l, r);
            return;
        }
        int mid = (l + r)/2;
        update(2*id, l, mid, lq, rq, val);
        update(2*id + 1, mid + 1, r,lq, rq, val);
        t[id] = merge(t[2*id], t[2*id + 1]);
    }

    *node* query(int id, int l, int r, int lq, int rq){
        push(id, l, r);
        if(lq > r || l > rq){
            return *node*(); 
        }
        if(lq <= l && r <= rq){
            return t[id]; *// acc to qn*
        }
        int mid = (l + r)/2;
        return merge(query(2*id, l, mid , lq, rq),query(2*id + 1, mid + 1, r, lq, rq));
    }
};
void solve(){

    ll n, q;
    cin >> n >> q;
    f(i,n){
        cin >> a[i];
    }
 
    *LazySegTree* st(n);
    st.build(1, 0, n-1);
    while(q--){
        int c; cin >> c;
        if(c == 1){
            int k, u; cin >> k >> u;
            k--;
            st.update(1, 0, n-1, k, k, u);
        } else{
            int l, r; cin >> l >> r;
            l--; r--;
            cout << st.query(1, 0, n-1, l, r).val << endl;
        }
    }
}


 <span style="font-size: 35.0;">
     # **Sum Segment Tree**
 </span>
*vi* a(N);
struct *node*{
    int val = 0; *// acc. to qn*
    node(){
        val = 0;  *// acc. to qn*
    }
};
struct *SegTree*{
    int SZ;
    vector<*node*> t;
    SegTree(int size) : SZ(size), t(4*size){}
    *node* merge(*node* a, *node* b){
        *node* ans;
        ans.val = a.val + b.val; *// acc. to qn*
        return ans;
    }
    void build(int id, int l, int r){   
        if(l == r){
            *// leaf node*
            t[id].val = a[l]; *// acc. to qn*
            return;
        }
        int mid = (l + r)/2;
        build(2*id, l ,mid);
        build(2*id+1, mid + 1 ,r);
        t[id] = merge(t[2*id], t[(2*id) + 1]);
    }

    void update(int id, int l, int r, int pos, node val){
        if((pos < l)|| (pos > r)){
            return; 
        } 
        if( l == r){
            t[id] = val; *// acc. to qn*
            return;
        }
        int mid = (l + r)/2;
        update(2*id, l ,mid, pos, val);
        update(2*id+1, mid + 1 ,r, pos , val);
        t[id] = merge(t[2*id], t[(2*id) + 1]);
    }

    *node* query(int id, int l, int r, int lq, int rq){
        if((rq < l) || (lq > r)){
            return *node*();  *// acc. to qn*
        }   
        if((lq <= l) && (r <= rq)){
            return t[id];  *// acc. to qn*
        }
        int mid = (l + r)/2;
        return merge(query(2*id, l, mid, lq, rq) , query((2*id) + 1, mid + 1, r, lq, rq));
    }
};


void solve(){

    ll n; 
    cin >> n;
    ll q; cin >> q;
    f(i,n)
        cin >> a[i];
    build(1, 0, n-1); 
    while(q--){
        int op; cin >> op;
        if(op == 1){
            ll k, u; cin >> k >> u;
            k--;
            update(1, 0, n-1,k,u);
        }
        else{
            int l, r; cin >> l >> r;
            l--; r--;
            *node* ans = query(1, 0, n-1, l, r);
            cout << ans.val << endl;
        }
    }
}

int main(){
    build(1, 0, n-1); *// 0-based indexing, basically should cover entire range of array cos it is the range of the array root node is responsible for. For 1-based indexing : (1, 1, n)*
    update(1, 0, n-1, , );
    *node* ans = query(1, 0, n-1, , );
}


 <span style="font-size: 35.0;">
     # **Lazy (sum + set), Node Sum Segment Tree**
 </span>
*const* int N = 2e5 + 5;
#define int long long

struct *node*{
    int lazy_add;
    int lazy_set;
    int sum;
    node(){
        lazy_add = 0;
        lazy_set = 0;
        sum = 0; 
    }
};
vector<int> a(N);
*node* t[4*N];
*node* merge(*node* a, *node* b){
    *node* ans;
    ans.sum = a.sum + b.sum;
    return ans;
}
void push_down(int cur, int child){
    if(t[cur].lazy_set != 0){
        t[child].lazy_set = t[cur].lazy_set;
        t[child].lazy_add = 0;
    } else{
        if(t[child].lazy_set != 0){
            t[child].lazy_set += t[cur].lazy_add;
        } else{
            t[child].lazy_add += t[cur].lazy_add;
        }
    }
}

void push(int id, int l, int r){
    if(t[id].lazy_add==0 && t[id].lazy_set==0)return;
    if(l!=r){
        push_down(id,(id<<1));
        push_down(id,(id<<1|1));
    }
    if(t[id].lazy_add!=0){
        t[id].sum += (r-l+1)*t[id].lazy_add;
        t[id].lazy_add=0;
    }
    else if(t[id].lazy_set != 0){
        t[id].sum = (r-l+1)*t[id]. lazy_set;
        t[id].lazy_set=0;
    }
}
*// void push(int id, int l, int r){*
*//     if(t[id].lazy != 0){*
*//         t[id].sum += (r - l + 1)*t[id].lazy;*
*//         if(l != r){*
*//             t[id<<1].lazy += t[id].lazy;*
*//             t[id<<1|1].lazy += t[id].lazy;*
*//         }*
*//         t[id].lazy = 0;*
*//     }*
*// }*

void build(int id, int l, int r){
    if(l == r){
        t[id].sum = a[l];
        t[id].lazy_add = 0;
        t[id].lazy_set = 0;
        return;
    } 
    int mid = (l+r)/2;
    build(2*id,l,mid);
    build(2*id+1, mid+1, r);
    t[id] = merge(t[2*id], t[2*id+1]);
}

void update(int id, int l, int r, int lq, int rq, int val, int updatetype){
    push(id, l, r);
    if(lq > r || rq < l) return;
    if(lq <= l && r <= rq){
        if(updatetype == 1){
            t[id].lazy_add += val;
        } else {
            t[id].lazy_set = val;
        }
        push(id, l, r);
        return;
    }
    int mid = (l + r)/2;
    update(2*id, l, mid, lq, rq, val, updatetype);
    update(2*id + 1, mid + 1, r,lq, rq, val, updatetype);
    t[id] = merge(t[2*id], t[2*id + 1]);
}

*node* query(int id, int l, int r, int lq, int rq){
    push(id, l, r);
    if(lq > r || l > rq){
        return *node*();
    }
    if(lq <= l && r <= rq){
        return t[id];
    }
    int mid = (l + r)/2;
    return merge(query(2*id, l, mid , lq, rq),query(2*id + 1, mid + 1, r, lq, rq));
}

 <span style="font-size: 35.0;">
     # **Min Segment Tree**
 </span>
*vi* a(N);
struct *node*{
    int val = 1e18; *// acc. to qn*
    node(){
        val = 1e18;  *// acc. to qn*
    }
};
*node* t[4*N];
*node* merge(*node* a, *node* b){
    *node* ans;
    ans.val = min(a.val , b.val); *// acc. to qn*
    return ans;
}
void build(int id, int l, int r){   
    if(l == r){
        *// leaf node*
        t[id].val = a[l]; *// acc. to qn*
        return;
    }
    int mid = (l + r)/2;
    build(2*id, l ,mid);
    build(2*id+1, mid + 1 ,r);
    t[id] = merge(t[2*id], t[(2*id) + 1]);
}

void update(int id, int l, int r, int pos, int val){
    if((pos < l)|| (pos > r)){
        return; 
    } 
    if( l == r){
        t[id].val = val; *// acc. to qn*
        return;
    }
    int mid = (l + r)/2;
    update(2*id, l ,mid, pos, val);
    update(2*id+1, mid + 1 ,r, pos , val);
    t[id] = merge(t[2*id], t[(2*id) + 1]);
}

*node* query(int id, int l, int r, int lq, int rq){
    if((rq < l) || (lq > r)){
        return *node*();  *// acc. to qn*
    }   
    if((lq <= l) && (r <= rq)){
        return t[id];  *// acc. to qn*
    }
    int mid = (l + r)/2;
    return merge(query(2*id, l, mid, lq, rq) , query((2*id) + 1, mid + 1, r, lq, rq));
}
void solve(){

    ll n; 
    cin >> n;
    ll q; cin >> q;
    f(i,n)
        cin >> a[i];
    build(1, 0, n-1); 
    while(q--){
        int op; cin >> op;
        if(op == 1){
            ll k, u; cin >> k >> u;
            k--;
            update(1, 0, n-1,k,u);
        }
        else{
            int l, r; cin >> l >> r;
            l--; r--;
            *node* ans = query(1, 0, n-1, l, r);
            cout << ans.val << endl;
        }
    }
}

 <span style="font-size: 35.0;">
     # **Max Segment Tree**
 </span>
struct *node*{
    int val = -1e18; *// acc. to qn*
    node(){
        val = -1e18;  *// acc. to qn*
    }
};
*node* t[4*N];
*node* merge(*node* a, *node* b){
    *node* ans;
    ans.val = max(a.val , b.val); *// acc. to qn*
    return ans;
}
void build(int id, int l, int r){   
    if(l == r){
        *// leaf node*
        t[id].val = 0; *// acc. to qn*
        return;
    }
    int mid = (l + r)/2;
    build(2*id, l ,mid);
    build(2*id+1, mid + 1 ,r);
    t[id] = merge(t[2*id], t[(2*id) + 1]);
}

void update(int id, int l, int r, int pos, int val){
    if((pos < l)|| (pos > r)){
        return; 
    } 
    if(l == r){
        t[id].val = max(t[id].val, val); *// acc. to qn*
        return;
    }
    int mid = (l + r)/2;
    update(2*id, l ,mid, pos, val);
    update(2*id+1, mid + 1 ,r, pos , val);
    t[id] = merge(t[2*id], t[(2*id) + 1]);
}

*node* query(int id, int l, int r, int lq, int rq){
    if((rq < l) || (lq > r)){
        return *node*();  *// acc. to qn*
    }   
    if((lq <= l) && (r <= rq)){
        return t[id];  *// acc. to qn*
    }
    int mid = (l + r)/2;
    return merge(query(2*id, l, mid, lq, rq) , query((2*id) + 1, mid + 1, r, lq, rq));
}

# BS THRU SEG-TREE IDEA

*vi* a(N);
struct *node*{
    int val = LONG_MIN; *// acc. to qn*
    node(){
        val = LONG_MIN;  *// acc. to qn*
    }
};
*node* t[4*N];
*node* merge(*node* a, *node* b){
    *node* ans;
    ans.val = max(a.val , b.val); *// acc. to qn*
    return ans;
}
void build(int id, int l, int r){   
    if(l == r){
        *// leaf node*
        t[id].val = a[l]; *// acc. to qn*
        return;
    }
    int mid = (l + r)/2;
    build(2*id, l ,mid);
    build(2*id+1, mid + 1 ,r);
    t[id] = merge(t[2*id], t[(2*id) + 1]);
}

void update(int id, int l, int r, int pos, int val){
    if((pos < l)|| (pos > r)){
        return; 
    } 
    if( l == r){
        t[id].val -= val; *// acc. to qn*
        return;
    }
    int mid = (l + r)/2;
    update(2*id, l ,mid, pos, val);
    update(2*id+1, mid + 1 ,r, pos , val);
    t[id] = merge(t[2*id], t[(2*id) + 1]);
}

int query(int id, int l, int r, int req){
    *// THIS IS WHERE WE GONNA DO THE BS*
    if(req > t[id].val){
        return -1;
    }
    if( l == r){
        return l;
    }
    int mid = (l + r)/2;
    if(t[2*id].val >= req){
        return query(2*id, l, mid, req);
    } else{
        return query(2*id + 1, mid + 1, r, req);
    }
}
void solve(){

    ll n; 
    cin >> n;
    ll q; cin >> q;
    f(i,n)
        cin >> a[i];
    build(1, 0, n-1); 
    while(q--){
        int r; cin >> r;
        *// USE QUERY TO FIND CORRECT INDEX*
        int id = query(1, 0, n-1, r);
        if(id == -1){
            cout << 0 << " ";
        }
        else{
            *// USE UPDATE TO CHANGE VALUE*
            update(1, 0, n-1, id, r);
            cout << id + 1 << " ";
        }
    }
}
