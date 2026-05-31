# Vivek Templates (Recursive)

## 1. Lazy set, node-sum segment tree

```cpp
vi a(N, 0);

struct node {
    int lazy;
    int val;
    node() {
        lazy = 0;
        val = 0;
    }
};

struct LazySegTree {
    int SZ;
    vector<node> t;

    LazySegTree(int size) : SZ(size), t(4 * size) {}

    node merge(node a, node b) {
        node ans;
        ans.val = a.val + b.val;
        return ans;
    }

    void push(int id, int l, int r) {
        if (t[id].lazy != 0) {
            t[id].val = (r - l + 1) * t[id].lazy;
            if (l != r) {
                t[id << 1].lazy = t[id].lazy;
                t[(id << 1) | 1].lazy = t[id].lazy;
            }
            t[id].lazy = 0;
        }
    }

    void build(int id, int l, int r) {
        if (l == r) {
            t[id].val = a[l];
            t[id].lazy = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        t[id] = merge(t[2 * id], t[2 * id + 1]);
    }

    void update(int id, int l, int r, int lq, int rq, int val) {
        push(id, l, r);
        if (lq > r || rq < l) return;
        if (lq <= l && r <= rq) {
            t[id].lazy = val;
            push(id, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * id, l, mid, lq, rq, val);
        update(2 * id + 1, mid + 1, r, lq, rq, val);
        t[id] = merge(t[2 * id], t[2 * id + 1]);
    }

    node query(int id, int l, int r, int lq, int rq) {
        push(id, l, r);
        if (lq > r || l > rq) return node();
        if (lq <= l && r <= rq) return t[id];
        int mid = (l + r) / 2;
        return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    f(i, n) cin >> a[i];

    LazySegTree st(n);
    st.build(1, 0, n - 1);

    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            st.update(1, 0, n - 1, k, k, u);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << st.query(1, 0, n - 1, l, r).val << endl;
        }
    }
}
```

## 2. Sum segment tree

```cpp
vi a(N);

struct node {
    int val = 0;
    node() {
        val = 0;
    }
};

struct SegTree {
    int SZ;
    vector<node> t;

    SegTree(int size) : SZ(size), t(4 * size) {}

    node merge(node a, node b) {
        node ans;
        ans.val = a.val + b.val;
        return ans;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            t[id].val = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        t[id] = merge(t[2 * id], t[2 * id + 1]);
    }

    void update(int id, int l, int r, int pos, node val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            t[id] = val;
            return;
        }
        int mid = (l + r) / 2;
        update(2 * id, l, mid, pos, val);
        update(2 * id + 1, mid + 1, r, pos, val);
        t[id] = merge(t[2 * id], t[2 * id + 1]);
    }

    node query(int id, int l, int r, int lq, int rq) {
        if (rq < l || lq > r) return node();
        if (lq <= l && r <= rq) return t[id];
        int mid = (l + r) / 2;
        return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
    }
};

void solve() {
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    f(i, n) cin >> a[i];

    SegTree st(n);
    st.build(1, 0, n - 1);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            ll k, u;
            cin >> k >> u;
            k--;
            update(1, 0, n - 1, k, {u});
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            node ans = query(1, 0, n - 1, l, r);
            cout << ans.val << endl;
        }
    }
}
```

## 3. Lazy sum + set segment tree

```cpp
const int N = 2e5 + 5;
#define int long long

struct node {
    int lazy_add;
    int lazy_set;
    int sum;
    node() {
        lazy_add = 0;
        lazy_set = 0;
        sum = 0;
    }
};

vector<int> a(N);
node t[4 * N];

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

void push_down(int cur, int child) {
    if (t[cur].lazy_set != 0) {
        t[child].lazy_set = t[cur].lazy_set;
        t[child].lazy_add = 0;
    } else {
        if (t[child].lazy_set != 0) {
            t[child].lazy_set += t[cur].lazy_add;
        } else {
            t[child].lazy_add += t[cur].lazy_add;
        }
    }
}

void push(int id, int l, int r) {
    if (t[id].lazy_add == 0 && t[id].lazy_set == 0) return;
    if (l != r) {
        push_down(id, id << 1);
        push_down(id, (id << 1) | 1);
    }
    if (t[id].lazy_add != 0) {
        t[id].sum += (r - l + 1) * t[id].lazy_add;
        t[id].lazy_add = 0;
    } else if (t[id].lazy_set != 0) {
        t[id].sum = (r - l + 1) * t[id].lazy_set;
        t[id].lazy_set = 0;
    }
}

void build(int id, int l, int r) {
    if (l == r) {
        t[id].sum = a[l];
        t[id].lazy_add = 0;
        t[id].lazy_set = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int lq, int rq, int val, int updatetype) {
    push(id, l, r);
    if (lq > r || rq < l) return;
    if (lq <= l && r <= rq) {
        if (updatetype == 1) {
            t[id].lazy_add += val;
        } else {
            t[id].lazy_set = val;
        }
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, lq, rq, val, updatetype);
    update(2 * id + 1, mid + 1, r, lq, rq, val, updatetype);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if (lq > r || l > rq) return node();
    if (lq <= l && r <= rq) return t[id];
    int mid = (l + r) / 2;
    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
}
```

## 4. Min segment tree

```cpp
vi a(N);

struct node {
    int val = 1e18;
    node() {
        val = 1e18;
    }
};

node t[4 * N];

node merge(node a, node b) {
    node ans;
    ans.val = min(a.val, b.val);
    return ans;
}

void build(int id, int l, int r) {
    if (l == r) {
        t[id].val = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        t[id].val = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(int id, int l, int r, int lq, int rq) {
    if (rq < l || lq > r) return node();
    if (lq <= l && r <= rq) return t[id];
    int mid = (l + r) / 2;
    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
}
```

## 5. Max segment tree

```cpp
struct node {
    int val = -1e18;
    node() {
        val = -1e18;
    }
};

node t[4 * N];

node merge(node a, node b) {
    node ans;
    ans.val = max(a.val, b.val);
    return ans;
}

void build(int id, int l, int r) {
    if (l == r) {
        t[id].val = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        t[id].val = max(t[id].val, val);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(int id, int l, int r, int lq, int rq) {
    if (rq < l || lq > r) return node();
    if (lq <= l && r <= rq) return t[id];
    int mid = (l + r) / 2;
    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
}
```

## 6. Binary search through segment tree idea

```cpp
vi a(N);

struct node {
    int val = LONG_MIN;
    node() {
        val = LONG_MIN;
    }
};

node t[4 * N];

node merge(node a, node b) {
    node ans;
    ans.val = max(a.val, b.val);
    return ans;
}

void build(int id, int l, int r) {
    if (l == r) {
        t[id].val = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        t[id].val -= val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

int query(int id, int l, int r, int req) {
    if (req > t[id].val) return -1;
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (t[2 * id].val >= req) return query(2 * id, l, mid, req);
    return query(2 * id + 1, mid + 1, r, req);
}
```