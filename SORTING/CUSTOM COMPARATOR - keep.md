# CUSTOM COMPARATOR : keep

#

# PAIR OF INTS.

    static bool comp (pair<int,int> a, pair<int,int> b){
        return (a.first > b.first);
    }

# INTS

# **`sort(v.begin(), v.end(), [](int a, int b){return (a > b);});`**

bool comp(int a, int b) {
return a> b;
}
