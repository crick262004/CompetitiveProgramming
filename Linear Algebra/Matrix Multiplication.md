# Matrix Multiplication


 <span style="font-size: 16.0;">
     #include <bits/stdc++.h>
using namespace std;

 </span> <span style="font-size: 16.0;">
     *const*
 </span> <span style="font-size: 16.0;">
      int mod = 1e9 + 7;
#define REP(i) for(int i = 0; i < 2; ++i)

 </span> <span style="font-size: 16.0;">
     **struct** 
 </span> <span style="font-size: 16.0;">
     ***Matrix***
 </span> <span style="font-size: 16.0;">
      **{
    int a[2][2] = {{0,0},{0,0}};**
    
 </span> <span style="font-size: 16.0;">
     ***Matrix***
 </span> <span style="font-size: 16.0;">
      **operator *(**
 </span> <span style="font-size: 16.0;">
     ***const***
 </span>  <span style="font-size: 16.0;">
     ***Matrix&***
 </span> <span style="font-size: 16.0;">
      **other)** 
 </span> <span style="font-size: 16.0;">
     ***const***
 </span> <span style="font-size: 16.0;">
      **{**
        
 </span> <span style="font-size: 16.0;">
     ***Matrix***
 </span> <span style="font-size: 16.0;">
      **product;
        REP(i) REP(j) REP(k) {
            product.a[i][k] = (product.a[i][k] + (long long) a[i][j] * other.a[j][k]) % mod;
        }
        return product;
    }
};**
 </span>



 <span style="font-size: 35.0;">
     # **Seg Tree involving Matrix Multiplication**

 </span>struct *node*{
    *Matrix* nm;
};
struct *SegTree*{
    int SZ;
    vector<*node*> t;
    SegTree(int size) : SZ(size), t(4*size){}
     <span style="font-size: 18.0;">
     ***node***
 </span> <span style="font-size: 18.0;">
      **merge(**
 </span> <span style="font-size: 18.0;">
     ***node***
 </span> <span style="font-size: 18.0;">
      **a,** 
 </span> <span style="font-size: 18.0;">
     ***node***
 </span> <span style="font-size: 18.0;">
      **b){**


 </span> <span style="font-size: 18.0;">
             ***// IMPORTANT : THE ORDER IS IMPORTANT!!!!!***
 </span>
 <span style="font-size: 18.0;">
             ***// doing ans = a * b is wrong.***
 </span>
 <span style="font-size: 18.0;">
             ***// correct is to do ans = b * a***
 </span>
         <span style="font-size: 18.0;">
     ***node***
 </span> <span style="font-size: 18.0;">
      **ans;
        ans.nm = b.nm;
        ans.nm = ans.nm * a.nm;
        return ans;
    }**
 </span>
    void build(int id, int l, int r, *string&* s){   
        if(l == r){
            *// leaf node*
            t[id].nm.init(s[l]); *// acc. to qn*
            return;
        }
        int mid = (l + r)/2;
        build(2*id, l ,mid, s);
        build(2*id+1, mid + 1 ,r, s);
        t[id] = merge(t[2*id], t[(2*id) + 1]);
    }

    void update(int id, int l, int r, int pos, *node* val){
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

