# Fenwick Tree / BIT


struct *BIT* {
    int n; vector<int> ft;
    BIT(int n=0): n(n), ft(n+1,0) {}
    void reset(int _n){ n=_n; ft.assign(n+1,0); }
    *inline* void add(int i, int v){ for(; i<=n; i+=i&-i) ft[i]+=v; }
    *inline* int sumPrefix(int i){ int s=0; for(; i>0; i-=i&-i) s+=ft[i]; return s; }
    *inline* int rangeSum(int l, int r){ if(r<l) return 0; return sumPrefix(r)-sumPrefix(l-1); }
};



struct *FenwickTree* {
    *// calculate sums*
    *// zero-based indexing*
    vector<int> bit;  *// binary indexed tree*
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> *const* *&*a) : *FenwickTree*(a.size()) {
        for (*size_t* i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};





struct *FenwickTreeMin* {
    */// calculate min*
    vector<int> bit;
    int n;
    *const* int INF = (int)1e9;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(vector<int> a) : *FenwickTreeMin*(a.size()) {
        for (*size_t* i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmin(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};








struct *FenwickTreeOneBasedIndexing* {
    *// 1-based indexing*
    vector<int> bit;  *// binary indexed tree*
    int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a)
        : *FenwickTreeOneBasedIndexing*(a.size()) {
        for (*size_t* i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};
