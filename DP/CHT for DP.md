# CHT for DP

 <span style="font-size: 33.0;">
     # **this is, by default a max Convex Hull.** 

 </span> <span style="font-size: 33.0;">
     # **To use a min CH,**

 </span> <span style="font-size: 33.0;">
     # **add lines as (-m, -b) and use -eval(x)**

 </span>
 <span style="font-size: 33.0;">
     **Good problem:**

 </span> <span style="font-size: 33.0;">
     **[https://codeforces.com/problemset/problem/932/F](https://codeforces.com/problemset/problem/932/F)**
 </span>

const ll is_query = -(1LL<<62);
struct line {
    ll m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_hull : public multiset<line> { // will maintain upper hull for maximum
    const ll inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

		/* compare two lines by slope, make sure denominator is not 0 */
        ll v1 = (x->b - y->b);
        if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
        else v1 /= (y->m - x->m);
        ll v2 = (y->b - z->b);
        if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
        else v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((line) { x, is_query });
        return l.m * x + l.b;
    }
};

# *P* **p1 = hull.end()[-2];**
# *P* **p2 = hull.end()[-1];**
 <span style="font-size: 33.0;">
     # **Syntactical sugar. accessing last / second-last element of vector<P> hull**
 </span>