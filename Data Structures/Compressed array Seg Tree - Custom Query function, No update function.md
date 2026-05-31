# Compressed array Seg Tree: Custom Query function, No update function. Each node stores compressed subarray of range it corresponds to

different kind of seg tree problem. Custom Query function, No update function.
Build the seg tree where each node stores a vector representation of the range it covers. This can work if no update functions and if we build the query function such that it doesn’t need to do the actual merging, and calulculates the answer just by looking at the O(logn) nodes for its range, and doing some fast caluclation per node(O(logN) or O(1) ). 
With appropiate name of file


```cpp
struct Node {
    // acc to qn
};

struct SegTree {
    int SZ;
    vector<Node *> t;

    SegTree(int size) : SZ(size), t(4 * size) {}

    Node *merge(Node *l, Node *r) {
        // acc to qn
    }

    void build(int id, int l, int r, vector<int> &a) {
        if (l == r) {
            // leaf node, acc to qn
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, a);
        build(2 * id + 1, mid + 1, r, a);
        t[id] = merge(t[2 * id], t[2 * id + 1]);
    }

    void query(int id, int l, int r, int lq, int rq, int &res, int &x) {
        if (rq < l || lq > r) {
            return; // acc. to qn
        }
        if (lq <= l && r <= rq) { // acc. to qn
            // this will be different than usual seg tree, has to be O(log(N) or better)
            return;
        }
        int mid = (l + r) / 2;
        query(2 * id, l, mid, lq, rq, res, x);
        query(2 * id + 1, mid + 1, r, lq, rq, res, x);
    }
};

void solve() {
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vi a(n);
    cin >> a;
    SegTree st(n);
    st.build(1, 0, n - 1, a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int res = 0;
        int x = 0;
        st.query(1, 0, n - 1, l, r, res, x);
        cout << res << endl;
    }
}
```
