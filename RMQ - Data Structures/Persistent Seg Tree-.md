# Persistent Seg Tree:

 <span style="font-size: 43.0;">
     **Persistent Seg Tree:
1.gemini**

 </span>#include <bits/stdc++.h>

*// Use long long for sums to avoid overflow*
using *ll* = long long;

*// Represents a node in the segment tree*
struct *Node* {
    *Node* *left = nullptr, *right = nullptr;
    *ll* sum = 0;
};

*// Store all nodes in a vector to avoid slow dynamic allocation*
std::vector<*Node*> node_pool;
int node_idx = 0;

*Node** new_node() {
    return &node_pool[node_idx++];
}

*// Roots of all arrays (versions)*
std::vector<*Node**> roots;

*// Build the initial segment tree*
*Node** build(*const* std::vector<int>*&* arr, int tl, int tr) {
    *Node** v = new_node();
    if (tl == tr) {
        v->sum = arr[tl];
    } else {
        int tm = tl + (tr - tl) / 2;
        v->left = build(arr, tl, tm);
        v->right = build(arr, tm + 1, tr);
        v->sum = v->left->sum + v->right->sum;
    }
    return v;
}

*// Persistent update: returns the root of the new version*
*Node** update(*Node** prev_v, int tl, int tr, int pos, int new_val) {
    *Node** v = new_node();
    *v = *prev_v; *// Copy data from the previous version's node*

    if (tl == tr) {
        v->sum = new_val;
    } else {
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm) {
            *// Path goes left, create a new left child*
            v->left = update(prev_v->left, tl, tm, pos, new_val);
        } else {
            *// Path goes right, create a new right child*
            v->right = update(prev_v->right, tm + 1, tr, pos, new_val);
        }
        v->sum = v->left->sum + v->right->sum;
    }
    return v;
}

*// Standard range sum query*
*ll* query_sum(*Node** v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return v->sum;
    }
    int tm = tl + (tr - tl) / 2;
    return query_sum(v->left, tl, tm, l, std::min(r, tm)) +
           query_sum(v->right, tm + 1, tr, std::max(l, tm + 1), r);
}

int main() {
    std::*ios_base*::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> initial_arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> initial_arr[i];
    }
    
    *// Pre-allocate memory for all nodes*
    *// Initial build: O(2n) nodes. Each query: O(log n) nodes.*
    node_pool.resize(2 * n + q * (log2(n) + 4));

    *// Build the first version*
    roots.push_back(build(initial_arr, 0, n - 1));

    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int k, a, x;
            std::cin >> k >> a >> x;
            *// Update creates a new root which replaces the old one*
            roots[k - 1] = update(roots[k - 1], 0, n - 1, a - 1, x);
        } else if (type == 2) {
            int k, a, b;
            std::cin >> k >> a >> b;
            std::cout << query_sum(roots[k - 1], 0, n - 1, a - 1, b - 1) << "\n";
        } else { *// type == 3*
            int k;
            std::cin >> k;
            *// Copy is just adding the pointer to the root*
            roots.push_back(roots[k - 1]);
        }
    }

    return 0;
}



 <span style="font-size: 43.0;">
     **2.CSES**
 </span>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct Node {
    Node *left = nullptr, *right = nullptr;
    ll sum;
};

// Builds a segment tree from vector v.
// Returns a pointer to the constructed tree.
Node *build(int l, int r, vector<int> &v) {
    Node *p = new Node();
    if (r - l == 1) {
        p->sum = v[l];
    } else {
        int m = (l + r) / 2;
        p->left = build(l, m, v);
        p->right = build(m, r, v);
        p->sum = p->left->sum + p->right->sum;
    }
    return p;
}

// Changes value in position k to x in tree p.
// Returns a pointer to the new tree.
Node *change(Node *p, int l, int r, int k, int x) {
    Node *n = new Node(*p);
    if (r - l == 1) {
        n->sum = x;
    } else {
        int m = (l + r) / 2;
        if (k < m) {
            n->left = change(p->left, l, m, k, x);
        } else {
            n->right = change(p->right, m, r, k, x);
        }
        n->sum = n->left->sum + n->right->sum;
    }
    return n;
}

// Returns the sum of values in range [ql, qr).
ll query(Node *p, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return p->sum;
    int m = (l + r) / 2;
    return query(p->left, l, m, ql, qr) + query(p->right, m, r, ql, qr);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<Node *> trees{build(0, n, v)};

    for (int qi = 0; qi < q; ++qi) {
        int t, k;
        cin >> t >> k;
        k--;
        if (t == 1) {
            int a, x;
            cin >> a >> x;
            trees[k] = change(trees[k], 0, n, a - 1, x);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(trees[k], 0, n, l - 1, r) << '\n';
        } else {
            trees.push_back(trees[k]);
        }
    }
}
