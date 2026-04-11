#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
#define REP(i) for(int i = 0; i < 2; ++i)

struct Matrix {
    int a[2][2] = {{0,0},{0,0}};
    
    Matrix operator *(const Matrix& other) const {
        Matrix product;
        REP(i) REP(j) REP(k) {
            product.a[i][k] = (product.a[i][k] + (long long) a[i][j] * other.a[j][k]) % mod;
        }
        return product;
    }
};

// Seg Tree involving Matrix Multiplication

struct node {
    Matrix nm;
};

struct SegTree {
    int SZ;
    vector<node> t;
    SegTree(int size) : SZ(size), t(4*size){}
    
    node merge(node a, node b) {
        // IMPORTANT : THE ORDER IS IMPORTANT!!!!!
        // doing ans = a * b is wrong.
        // correct is to do ans = b * a
        node ans;
        ans.nm = b.nm;
        ans.nm = ans.nm * a.nm;
        return ans;
    }

    void build(int id, int l, int r, string& s) {   
        if(l == r){
            // leaf node
            t[id].nm.init(s[l]); // acc. to qn
            return;
        }
        int mid = (l + r)/2;
        build(2*id, l ,mid, s);
        build(2*id+1, mid + 1 ,r, s);
        t[id] = merge(t[2*id], t[2*id + 1]);
    }

    void update(int id, int l, int r, int pos, node val) {
        if((pos < l)|| (pos > r)){
            return; 
        } 
        if( l == r){
            t[id] = val; // acc. to qn
            return;
        }
        int mid = (l + r)/2;
        update(2*id, l ,mid, pos, val);
        update(2*id+1, mid + 1 ,r, pos , val);
        t[id] = merge(t[2*id], t[2*id + 1]);
    }

    node query(int id, int l, int r, int lq, int rq) {
        if((rq < l) || (lq > r)){
            return node();  // acc. to qn
        }   
        if((lq <= l) && (r <= rq)){
            return t[id];  // acc. to qn
        }
        int mid = (l + r)/2;
        return merge(query(2*id, l, mid, lq, rq), query(2*id + 1, mid + 1, r, lq, rq));
    }
};
