// Polygon Area
#include <bits/stdc++.h>
#define ll long long
#define cno cout << "NO" << endl;
#define cyes cout << "YES" << endl;

ll twice_area(vector<P>& polygon){
    ll ans = 0;
    int n = polygon.size();
    for(int i = 0; i<n; i++){
        P p1 = polygon[i];
        P p2 = polygon[(i + 1)%n];
        ans += p1*p2;
    }
    ans = abs(ans);
    return ans;
}





using namespace std;

struct P{
    long long x, y; 
    void read(){
        cin >> x >> y;
    }
    P operator - (const P& b) const{
        return P{x - b.x, y - b.y};
    }
    void operator -= (const P& b) {
        x -= b.x;
        y -= b.y;
    }
    long long operator * (const P& b) const{ // vector product aka cross product aka right hand curling 
        return x*b.y - y*b.x;
    }
    long long triangle (const P& b, const P& c) const {
        return (b - *this) * (c - *this);
    }
};

void test_case(){
    ll n; cin >> n;
    vector<P> polygon(n);
    for(P& p : polygon){
        p.read();
    }
    ll ans = 0; // assume reference to be {0,0}
    for(int i = 0; i<n; i++){
        P p1 = polygon[i];
        P p2 = polygon[(i + 1)%n];
        ans += p1*p2;
    }
    ans = abs(ans);
    cout << ans << endl; // 2area
}

int main(){
    int T = 1; // cin >> T;
    while(T--){
        test_case();
    }
}