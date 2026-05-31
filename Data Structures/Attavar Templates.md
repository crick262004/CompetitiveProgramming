# Attavar Templates

# 
 <span style="font-size: 43.0;">
     # **Seg Tree:** 

 </span> <span style="font-size: 43.0;">
     # **Internally, the seg tree is 1-based 
That is, the seg and lazy array**
 </span>
// *1D point update and range query where \texttt{cmb} is* ** any associative operation.*
template<typename *T*> struct SegTree { *// cmb(ID,b) = b*
    *T* ID; *// the default value*
    *T* (*cmb)(*T* a, *T* b); *// the merge logic*
    int n; *// (0-based indexing ) size of leave node vector*
    vector<*T*> seg; *// total seg tree in vector*

    SegTree(int _n, *T* id, *T* _cmb(*T*, *T*) ) { *// constructor*
        ID = id; 
        cmb = _cmb;
        for (n = 1; n < _n; ) n *= 2; *// round up to power of 2*
        seg.assign(2*n,ID);
    }

    void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); } *// merge function*

    void upd(int p, *T* val) { *// set val at position p, iterative*
        seg[p += n] = val; 
        for (p /= 2; p; p /= 2) pull(p); 
    }
    *T* query(int l, int r) { *// zero-indexed, inclusive*
        *T* ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) { *// weird way of grabbing out the range required.*
            if (l&1) ra = cmb(ra,seg[l++]);
            if (r&1) rb = cmb(seg[--r],rb);
        }
        return cmb(ra,rb);
    }
    */// int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range*
    *///     if (r < lo || val > seg[ind]) return -1;*
    *///     if (l == r) return l;*
    *///     int m = (l+r)/2;*
    *///     int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;*
    *///     return first_at_least(lo,val,2*ind+1,m+1,r);*
    */// }*
};
# usage : 
    SegTree<int> st1(n, 1e18, [](int a, int b){ *// pa - a*
        return min(a, b);
    });
    f(i,n){
        st1.upd(i, p[i]);
    }
st1.upd(k, x);
st1.query(0 ,k-1)

# usage with custome node struct:
struct *node*{
    int open = 0, closed = 0, val = 0;
};
template<typename *T*> struct SegTree { 
};
void solve(){

    *string* s; cin >> s;
    ll m; cin >> m;
    int n = s.length();

    SegTree< *node*> st(n, *node*(), [](*node* l, *node* r){
        *node* *final*;
        int joined = min(l.open, r.closed);
        final.val = l.val + r.val + 2*joined;
        final.open = l.open + r.open - joined;
        final.closed = l.closed + r.closed - joined;
        return *final*;
    });
    f(i,n){
        *node* temp;
        if(s[i] == '('){
            temp.open = 1;
        } else{
            temp.closed = 1;
        }
        st.upd(i, temp);
    }
    f(i,m){
        int l, r; cin >> l >> r;
        l--; r--;
        cout << st.query(l, r).val << endl;
    }

}

 <span style="font-size: 43.0;">
     # **Seg Tree Recursive:**
 </span>
template<typename T, int SZ> struct SegTree {
	vector<T> seg; T id;
	T (*cmb) (T, T);
	SegTree(T _id, T _cmb(T, T)):id(_id),seg(2*SZ,id),cmb(_cmb){}
	void build() {for (int i=SZ-1; i >= 0; i--) seg[i]=cmb(seg[2*i],seg[2*i+1]);}
	T query(int l, int r, int s=0, int e=SZ-1, int c=1) {
		if (l > e || r < s) return id;
		if (l <= s && r >= e) return seg[c];
		int mid = (s + e) / 2;
		return cmb(query(l,r, s, mid, 2*c),
			query(l, r, mid + 1, e, 2*c+1));
	}
	void update(int i, T x, int s=0, int e=SZ-1, int c=1) {
		if (s > i || e < i) return;
		if (s == e) {seg[c] = x; return;}
		int mid = (s + e) / 2;
		update(i, x, s, mid, 2*c);
		update(i, x, mid + 1, e, 2*c+1);
		seg[c] = cmb(seg[2*c], seg[2*c+1]);
	}
};

 <span style="font-size: 43.0;">
     # **Lazy Seg Tree: Kinda recursive**
 </span>
 ** Description: 1D range increment and sum query.*
    ** https://codeforces.com/blog/entry/82400*
#pragma once

template<class *T*, class *U*, int SZ> struct LazySeg { *// SZ must be power of 2*
    *const* *T* ID1;
    vector<*T*> seg;
    vector<*U*> lazy;
    *T* (*cmb)(*T* a, *T* b);
    
    void (*push)(int,int,int,vector<*T*>*&*,vector<*U*>*&*) = 
        [](int ind,int L,int R,vector<*T*>*&*seg,vector<*U*>*&*lazy) {
        */// modify values for current node*
        seg[ind] += (R-L+1)*lazy[ind]; *// dependent on operation*
        if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
        lazy[ind] = 0; */// prop to children*
    }; *// recalc values for current node*

    LazySeg(*T* id1, *U* id2, *T* _cmb(*T*, *T*), void _push(int,int,int,vector<*T*>&,vector<*U*>&)):
        ID1(id1),cmb(_cmb),push(_push),seg(2*SZ,id1),lazy(2*SZ,id2){}
    
    void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}

    void build() { for(int i=SZ-1;i>=1;i--) pull(i); }

    void upd(int lo,int hi,*U* inc,int ind=1,int L=0, int R=SZ-1) {
        push(ind,L,R,seg,lazy); 
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] += inc; 
            push(ind,L,R,seg,lazy); 
            return; 
        }
        int M = (L+R)/2; 
        upd(lo,hi,inc,2*ind,L,M); 
        upd(lo,hi,inc,2*ind+1,M+1,R); 
        pull(ind);
    }

    *T* query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
        push(ind,L,R,seg,lazy); if (lo > R || L > hi) return ID1;
        if (lo <= L && R <= hi) return seg[ind];
        int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
            query(lo,hi,2*ind+1,M+1,R));
    }
};

    LazySeg< ll, ll, (1ll<<20)> lst( LONG_MIN, 0ll, 
        [](ll a, ll b){
            return max(a, b);
        }, 
        [](int ind,int L,int R,vector<ll>*&*seg,vector<ll>*&*lazy) {
            seg[ind] += lazy[ind];
            if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
            lazy[ind] = 0;
        }
    );

    f(i,n){
        psum += a[i];
        lst.seg[i + (1<<20)] = psum;
    }
    lst.build();
